#include "raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.h"

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
#define MAX_INPUT_BUF 50

// Colours
const Clay_Color COL_BACKGROUND = (Clay_Color) { 8, 10, 14, 255 };
const Clay_Color COL_BACKDROP = (Clay_Color) { 40, 42, 46, 255 };
const Clay_Color COL_FOREGROUND = (Clay_Color) { 197, 200, 198, 255 };
const Clay_Color COL_BACKDROP_ALT = (Clay_Color) { 50, 52, 56, 255 };
const Clay_Color COL_TRANSPARENT = (Clay_Color) { 0, 0, 0, 0 };
const Clay_Color COL_GREEN = (Clay_Color) { 5, 145, 19, 255};

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
int lyric_index;
RedactedSong redacted;
int redacted_index = 0;
char input_buf[MAX_INPUT_BUF];
int input_buf_count = 0;
char correct_chars[MAX_CORRECT_CHARS];
Clay_String correct_string;
bool game_won = false;


//////
/// Utility
static inline Clay_Vector2 RL_V2_TO_CLAY(Vector2 vec) {
    return (Clay_Vector2) { .x = vec.x, .y = vec.y};
}

//////
/// Functions
void reset_game() {
    // Get lyric index
    srand(time(NULL));
    lyric_index = rand() % NUM_LYRICS;
    Song song = LYRICS[lyric_index];

    // Redact lyrics
    redacted = redact_song(&song, song.lyrics.length / 300);
    redacted_index = 0;

    snprintf(correct_chars, MAX_CORRECT_CHARS, "[%d / %d correct]", redacted_index, redacted.num_redacted);
    correct_string = (Clay_String) {
        .chars = correct_chars,
        .length = strlen(correct_chars),
    };

    // Clear input
    input_buf_count = 0;
    input_buf[input_buf_count] = '\0';

    // Reset won state
    game_won = false;
}

void free_lyrics() {
    free((char*)redacted.redacted_lyrics.chars);
    for (unsigned i = 0; i < redacted.num_redacted; ++i) {
        free(redacted.redacted_words[i].word);
    }
    free(redacted.redacted_words);
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
                    .color = COL_BACKDROP_ALT,
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
                        .padding = { 4, 4 },
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
        free_lyrics();
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
                printf("Correct!\n");
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
                printf("Wrong!\n");
            }
        }
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
    // Set up game
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
    Raylib_fonts[FONT_ID_BODY_24] = (Raylib_Font) {
        .font = LoadFontEx("resources/Roboto-Regular.ttf", 48, 0, 400),
        .fontId = FONT_ID_BODY_24,
    };

    Raylib_fonts[FONT_ID_BODY_16] = (Raylib_Font) {
        .font = LoadFontEx("resources/Roboto-Regular.ttf", 32, 0, 400),
        .fontId = FONT_ID_BODY_16,
    };

    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_16].font.texture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(Raylib_fonts[FONT_ID_BODY_24].font.texture, TEXTURE_FILTER_BILINEAR);

    // Draw loop
    while(!WindowShouldClose()) {
        draw();
    }
    
    free_lyrics();

    return EXIT_SUCCESS;
}
