#include "raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// Global constants
const uint32_t FONT_ID_BODY_24 = 0;
const uint32_t FONT_ID_BODY_16 = 1;
const Clay_Color COL_BACKGROUND = (Clay_Color) { 8, 10, 14, 255 };

// Global variables
bool debug = false;

// Utility
static inline Clay_Vector2 RL_V2_TO_CLAY(Vector2 vec) {
    return (Clay_Vector2) { .x = vec.x, .y = vec.y};
}

// Main clay code
Clay_RenderCommandArray layout() {
    Clay_BeginLayout();

    CLAY (
        CLAY_RECTANGLE({ .color = COL_BACKGROUND }),
        CLAY_LAYOUT({
            .sizing = {
                .width = CLAY_SIZING_GROW(),
                .height = CLAY_SIZING_GROW(),
            }
        })
    ) {}

    return Clay_EndLayout();
}

void draw(void) {
    // Mouse wheel
    Vector2 mwheel_delta = GetMouseWheelMoveV();

    // Mouse
    Clay_Vector2 mouse_pos = RL_V2_TO_CLAY(GetMousePosition());
    Clay_SetPointerState(mouse_pos, IsMouseButtonDown(0));

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

    // Draw loop
    while(!WindowShouldClose()) {
        draw();
    }

    return EXIT_SUCCESS;
}
