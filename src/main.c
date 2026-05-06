#include <stdio.h>
#include <raylib.h>
#include <time.h>

#include "display/display.h"
#include "clock/clock.h"

#define WIDTH 1200
#define HEIGHT 800

int main()
{
    int width = WIDTH;
    int height = HEIGHT;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "7 Segment Clock");
    while (!WindowShouldClose())
    {
        if (IsWindowResized()) {
            width = GetScreenWidth();
            height = GetScreenHeight();
        }

        Vector2 center = { width / 2, height / 2 };
        
        BeginDrawing();
        ClearBackground(BLACK);
        drawClock(getHour(), getMinutes(), getSeconds(), center, 0.5f);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}