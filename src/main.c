#include "raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.h"

#include "lyrics.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

///////
/// Global constants
const uint32_t FONT_ID_BODY_24 = 0;
const uint32_t FONT_ID_BODY_16 = 1;

// Colours
const Clay_Color COL_BACKGROUND = (Clay_Color) { 8, 10, 14, 255 };
const Clay_Color COL_BACKDROP = (Clay_Color) { 40, 42, 46, 255 };
const Clay_Color COL_FOREGROUND = (Clay_Color) { 197, 200, 198, 255 };

// Layouts
const Clay_Sizing layout_grow = {
    .width = CLAY_SIZING_GROW(),
    .height = CLAY_SIZING_GROW(),
};

///////
/// Global variables
bool debug = false;
int lyric_index;

//////
/// Utility
static inline Clay_Vector2 RL_V2_TO_CLAY(Vector2 vec) {
    return (Clay_Vector2) { .x = vec.x, .y = vec.y};
}

//////
/// Functions
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
        CLAY(
            CLAY_ID("Header"),
            CLAY_RECTANGLE({
                .color = COL_BACKDROP,
                .cornerRadius = 8,
            }),
            CLAY_LAYOUT({
                .sizing = {
                    .height = CLAY_SIZING_FIXED(60),
                    .width = CLAY_SIZING_GROW(),
                },
                .childAlignment = {
                    .x = CLAY_ALIGN_X_CENTER,
                    .y = CLAY_ALIGN_Y_CENTER,
                },
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
                CLAY_TEXT(LYRICS[lyric_index].lyrics, CLAY_TEXT_CONFIG({
                    .fontId = FONT_ID_BODY_16,
                    .fontSize = 24,
                    .textColor = COL_FOREGROUND,
                })),
                CLAY_LAYOUT({
                    .padding = { 8, 8 },
                })
            ) {}
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

    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Q)) {
        CloseWindow();
        return;
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

    // Get lyric index
    srand(time(NULL));
    lyric_index = rand() % NUM_LYRICS;

    // Draw loop
    while(!WindowShouldClose()) {
        draw();
    }

    return EXIT_SUCCESS;
}
