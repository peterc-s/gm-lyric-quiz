#include "raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.h"
#define ARENA_IMPLEMENTATION
#include "arena.h"

#include "lyrics.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

///////
/// Global constants
const uint32_t FONT_ID_BODY_24 = 0;
const uint32_t FONT_ID_BODY_16 = 1;
#define MAX_CORRECT_CHARS 64
#define MAX_INPUT_BUF 35
// probably don't set this lower than 20 to be safe (or the length longest word in all of the lyrics)
// the higher this number, the easier
const uint16_t WORD_RATIO = 50;

// Colours
const Clay_Color COL_BACKGROUND = { 8, 10, 14, 255 };
const Clay_Color COL_BACKDROP = { 40, 42, 46, 255 };
const Clay_Color COL_FOREGROUND = { 197, 200, 198, 255 };
const Clay_Color COL_BACKDROP_ALT = { 50, 52, 56, 255 };
const Clay_Color COL_TRANSPARENT = { 0, 0, 0, 0 };
const Clay_Color COL_GREEN = { 5, 145, 19, 255};
const Clay_Color COL_RED = { 165, 66, 34, 255 };

// Layouts
const Clay_Sizing layout_grow = {
    .width = CLAY_SIZING_GROW(),
    .height = CLAY_SIZING_GROW(),
};

const Clay_Sizing layout_fit = {
    .width = CLAY_SIZING_FIT(),
    .height = CLAY_SIZING_FIT(),
};

///////
/// Global state
bool debug = false;
int64_t wrong_time;
bool show_wrong = false;
int lyric_index;
RedactedSong redacted;
int redacted_index = 0;
char input_buf[MAX_INPUT_BUF];
int input_buf_count = 0;
char correct_chars[MAX_CORRECT_CHARS];
Clay_String correct_string;
bool game_won = false;

///////
/// Arenas
static Arena lyric_arena = { 0 };

///////
/// Utility
static inline Clay_Vector2 RL_V2_TO_CLAY(Vector2 vec) {
    return (Clay_Vector2) { .x = vec.x, .y = vec.y};
}

static inline uint64_t time_ms() {
    clock_t current_time = clock();
    return (uint64_t)(current_time * 10000) / CLOCKS_PER_SEC;
}

///////
/// Functions
void reset_game() {
    // Get lyric index
    lyric_index = rand() % NUM_LYRICS;
    Song song = LYRICS[lyric_index];

    // Redact lyrics
    arena_reset(&lyric_arena);
    int num_to_redact = (song.lyrics.length / WORD_RATIO);
    redacted = redact_song(&lyric_arena, &song, num_to_redact <= 0 ? 1 : num_to_redact);
    redacted_index = 0;

    snprintf(correct_chars, MAX_CORRECT_CHARS, "[%d / %d correct]", redacted_index, redacted.num_redacted);
    correct_string = (Clay_String) {
        .chars = correct_chars,
        .length = strlen(correct_chars),
    };

    // Clear input
    input_buf_count = 0;
    input_buf[input_buf_count] = '\0';

    // Reset wrong flag
    wrong_time = time_ms();
    show_wrong = false;

    // Reset won stat
    game_won = false;
}

Clay_RenderCommandArray layout() {
    Clay_BeginLayout();

    CLAY(
        CLAY_ID("Background"),
        CLAY_RECTANGLE({ .color = COL_BACKGROUND }),
        CLAY_LAYOUT({
            .sizing = layout_grow,
            .padding = { 6, 6 },
            .childGap = 6,
            .layoutDirection = CLAY_TOP_TO_BOTTOM,
        })
    ) {
        if (game_won) {
            CLAY(
                CLAY_ID("Win Box"),
                CLAY_RECTANGLE({
                    .color = COL_GREEN,
                    .cornerRadius = 8,
                }),
                CLAY_FLOATING({
                    .offset = {
                        .x = GetScreenWidth() / 2.0,
                        .y = GetScreenHeight() / 2.0,
                    },
                    .attachment = CLAY_ATTACH_POINT_CENTER_CENTER,
                    .pointerCaptureMode = CLAY_POINTER_CAPTURE_MODE_CAPTURE,
                }),
                CLAY_LAYOUT({
                    .sizing = {
                        .height = CLAY_SIZING_FIT(),
                        .width = CLAY_SIZING_FIT(),
                    },
                    .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    .childAlignment = {
                        .x = CLAY_ALIGN_X_CENTER,
                        .y = CLAY_ALIGN_Y_TOP,
                    }
                })
            ) {
                CLAY(
                    CLAY_ID("Win Header"),
                    CLAY_TEXT(CLAY_STRING("You win!"), CLAY_TEXT_CONFIG({
                        .fontId = FONT_ID_BODY_24,
                        .fontSize = 70,
                        .textColor = COL_FOREGROUND,
                    })),
                    CLAY_LAYOUT({
                        .padding = { 30, 20 },
                    })
                ) {}

                CLAY(
                    CLAY_ID("Win Help Text"),
                    CLAY_TEXT(CLAY_STRING("Press Ctrl+q to quit or Ctrl+r to reset."), CLAY_TEXT_CONFIG({
                        .fontId = FONT_ID_BODY_16,
                        .fontSize = 36,
                        .textColor = COL_FOREGROUND,
                    })),
                    CLAY_LAYOUT({
                        .padding = { 20, 20 },
                    })
                ) {}
            }
        }

        CLAY(
            CLAY_ID("Header"),
            CLAY_RECTANGLE({
                .color = COL_BACKDROP,
                .cornerRadius = 8,
            }),
            CLAY_LAYOUT({
                .sizing = {
                    .height = CLAY_SIZING_FIT({ 60 }),
                    .width = CLAY_SIZING_GROW(),
                },
                .childAlignment = {
                    .x = CLAY_ALIGN_X_CENTER,
                    .y = CLAY_ALIGN_Y_CENTER,
                },
                .childGap = 20,
            })
        ) {
            CLAY(
                CLAY_ID("Header Text"),
                CLAY_TEXT(LYRICS[lyric_index].title, CLAY_TEXT_CONFIG({
                    .fontId = FONT_ID_BODY_24,
                    .fontSize = 42,
                    .textColor = COL_FOREGROUND,
                }))
            ) {}

            CLAY(
                CLAY_ID("Correct Count Box"),
                CLAY_RECTANGLE({
                    .color = COL_TRANSPARENT,
                    .cornerRadius = 4,
                }),
                CLAY_LAYOUT({
                    .childAlignment = {
                        .x = CLAY_ALIGN_X_CENTER,
                        .y = CLAY_ALIGN_Y_CENTER,
                    },
                })
            ) {
                CLAY(
                    CLAY_ID("Correct Count"),
                    CLAY_TEXT(correct_string, CLAY_TEXT_CONFIG({
                        .fontId = FONT_ID_BODY_24,
                        .fontSize = 42,
                        .textColor = COL_FOREGROUND,
                    }))
                ) {}
            }
        }

        CLAY(
            CLAY_ID("Lyric Container"),
            CLAY_RECTANGLE({
                .color = COL_BACKDROP,
                .cornerRadius = 8,
            }),
            CLAY_SCROLL({ .vertical = true }),
            CLAY_LAYOUT({
                .sizing = layout_grow,
            })
        ) {
            CLAY(
                CLAY_ID("Lyrics"),
                CLAY_TEXT(redacted.redacted_lyrics, CLAY_TEXT_CONFIG({
                    .fontId = FONT_ID_BODY_16,
                    .fontSize = 24,
                    .textColor = COL_FOREGROUND,
                })),
                CLAY_LAYOUT({
                    .padding = { 8, 8 },
                })
            ) {}
        }

        CLAY(
            CLAY_ID("Word Input Container"),
            CLAY_RECTANGLE({
                .color = COL_BACKDROP,
                .cornerRadius = 8,
            }),
            CLAY_LAYOUT({
                .sizing = {
                    .height = CLAY_SIZING_FIT({ 80 }),
                    .width = CLAY_SIZING_GROW(),
                },
                .childAlignment = {
                    .x = CLAY_ALIGN_X_LEFT,
                    .y = CLAY_ALIGN_Y_CENTER,
                },
                .childGap = 6,
                .padding = { 6, 6 },
            })
        ) {
            CLAY(
                CLAY_ID("Word Input Prompt Backboard"),
                CLAY_RECTANGLE({
                    .color = COL_TRANSPARENT,
                }),
                CLAY_LAYOUT({
                    .sizing = layout_fit,
                    .childAlignment = {
                        .x = CLAY_ALIGN_X_LEFT,
                        .y = CLAY_ALIGN_Y_CENTER,
                    }
                })
            ) {
                CLAY(
                    CLAY_ID("Word Input Prompt"),
                    CLAY_TEXT(CLAY_STRING("Enter first missing word: "), CLAY_TEXT_CONFIG({
                        .fontId = FONT_ID_BODY_24,
                        .fontSize = 36,
                        .textColor = COL_FOREGROUND,
                    })),
                    CLAY_LAYOUT({
                        .padding = { 6, 6 },
                        .sizing = layout_grow,
                    })
                ) {}
            }

            CLAY(
                CLAY_ID("Word Input Backboard"),
                CLAY_RECTANGLE({
                    .color = show_wrong ? COL_RED : COL_BACKDROP_ALT,
                    .cornerRadius = 8,
                }),
                CLAY_LAYOUT({
                    .childAlignment = {
                        .x = CLAY_ALIGN_X_LEFT,
                        .y = CLAY_ALIGN_Y_CENTER,
                    },
                    .sizing = layout_grow,
                })
            ) {
                Clay_String input_buf_string = (Clay_String) {
                    .chars = input_buf,
                    .length = input_buf_count,
                };

                CLAY(
                    CLAY_ID("Word Input"),
                    CLAY_TEXT(input_buf_string, CLAY_TEXT_CONFIG({
                        .fontId = FONT_ID_BODY_24,
                        .fontSize = 36,
                        .textColor = COL_FOREGROUND,
                    })),
                    CLAY_LAYOUT({
                        .padding = { 10, 4 },
                    })
                ) {}
            }
        }
    }

    return Clay_EndLayout();
}

void draw() {
    // Mouse wheel
    Clay_Vector2 mwheel_delta = RL_V2_TO_CLAY(GetMouseWheelMoveV());

    // Mouse
    Clay_Vector2 mouse_pos = RL_V2_TO_CLAY(GetMousePosition());
    Clay_SetPointerState(mouse_pos, IsMouseButtonDown(0));
    Clay_UpdateScrollContainers(true, mwheel_delta, GetFrameTime());

    // Screen size
    Clay_SetLayoutDimensions((Clay_Dimensions) { (float)GetScreenWidth(), (float)GetScreenHeight() });

    // Debug
    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_D)) {
        debug = !debug;
        Clay_SetDebugModeEnabled(debug);
    }

    // Quit
    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Q)) {
        CloseWindow();
        return;
    }

    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_R)) {
        reset_game();
    }

    // Text input
    if (!game_won) {
        int key = GetCharPressed();

        // Handle english characters
        while (key > 0) {
            if (key >= 32 && key <= 125 && input_buf_count < MAX_INPUT_BUF - 1) {
                input_buf[input_buf_count] = (char)key;
                input_buf[input_buf_count + 1] = '\0';
                ++input_buf_count;
            }

            key = GetCharPressed();
        }

        // Handle backspace
        if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) {
            --input_buf_count;
            if (input_buf_count < 0) input_buf_count = 0;
            input_buf[input_buf_count] = '\0';
        }

        // Ctrl+L to clear
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_L)) {
            input_buf_count = 0;
            input_buf[input_buf_count] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER)) {
            if (!strcmp(redacted.redacted_words[redacted_index].word, input_buf)) {
                // Copy word from original into the redacted
                memcpy((char*)redacted.redacted_lyrics.chars + redacted.redacted_words[redacted_index].start_index, redacted.redacted_words[redacted_index].word, redacted.redacted_words[redacted_index].len);
                ++redacted_index;

                // Clear input buffer
                input_buf_count = 0;
                input_buf[input_buf_count] = '\0';

                char correct_chars[64];
                snprintf(correct_chars, 64, "Correct: %d of %d", redacted_index, redacted.num_redacted);
                correct_string = (Clay_String) {
                    .chars = correct_chars,
                    .length = strlen(correct_chars),
                };

                if (redacted_index  == redacted.num_redacted) {
                    game_won = true;
                }
            } else {
                wrong_time = time_ms();
                show_wrong = true;
            }
        }
    }

    // reset wrong display
    if (time_ms() - wrong_time > 444 && show_wrong) {
        show_wrong = false;
    }

    // Get layout
    Clay_RenderCommandArray render_commands = layout();

    // Render with raylib
    BeginDrawing();
    // Background cleared so there are no dirty pixels
    ClearBackground(BLACK);
    Clay_Raylib_Render(render_commands);
    EndDrawing();
}

int main(void) {
    // No debug messages
    SetTraceLogLevel(LOG_ERROR); 
    
    // Set up game
    srand(time(NULL));
    reset_game();

    // Allocate memory
    uint64_t total_mem = Clay_MinMemorySize();
    Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(total_mem, malloc(total_mem));

    // Set measure text
    Clay_SetMeasureTextFunction(Raylib_MeasureText);

    // Initialise Clay with raylib
    Clay_Initialize(arena, (Clay_Dimensions) { (float)GetScreenWidth(), (float)GetScreenHeight() });
    Clay_Raylib_Initialize(1024, 768, "George Michael Lyric Quiz", FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

    // Fonts
    // Get home directory.
    const char* home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "ERROR: HOME environment variable not set.\n");
        exit(EXIT_FAILURE);
    }
    
    // Required font should be at `~/.cache/gm-quiz/Roboto-Regular.ttf`
    const char* cache_font_suffix = ".cache/gm-quiz/Roboto-Regular.ttf";
    size_t font_path_len = strlen(home_dir) + strlen(cache_font_suffix) + 2;
    char* cache_font_path = malloc(font_path_len);
    if (cache_font_path == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for font path.\n");
        exit(EXIT_FAILURE);
    }

    // Construct the cache font path
    snprintf(cache_font_path, font_path_len, "%s/%s", home_dir, cache_font_suffix);

    // Required font could also be at `resources/Roboto-Regular.ttf`
    const char* relative_font_path = "resources/Roboto-Regular.ttf";

    // Choose correct font
    char* font = NULL;
    if (FileExists(relative_font_path)) {
        // prioritise relative font path
        font = (char*)relative_font_path;
    } else if (FileExists(cache_font_path)) {
        // use cache font path if 
        font = (char*)cache_font_path;
    } else {
        fprintf(stderr, "ERROR: Required font not found at %s or %s\n", cache_font_path, relative_font_path);
        exit(EXIT_FAILURE);
    }

    Raylib_fonts[FONT_ID_BODY_24] = (Raylib_Font) {
        .font = LoadFontEx(font, 48, 0, 400),
        .fontId = FONT_ID_BODY_24,
    };

    Raylib_fonts[FONT_ID_BODY_16] = (Raylib_Font) {
        .font = LoadFontEx(font, 32, 0, 400),
        .fontId = FONT_ID_BODY_16,
    };

    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_16].font.texture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_24].font.texture, TEXTURE_FILTER_BILINEAR);

    // Draw loop
    while(!WindowShouldClose()) {
        draw();
    }

    arena_free(&lyric_arena);

    return EXIT_SUCCESS;
}
