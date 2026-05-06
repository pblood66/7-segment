#include <stdio.h>
#include <raylib.h>
#include <time.h>

#include "display/digit.h"
#include "clock/clock.h"

#define WIDTH 900
#define HEIGHT 600



int main()
{
    InitWindow(WIDTH, HEIGHT, "7 Segment Clock");
    double last_time = GetTime();

    int i = 0;
    while (!WindowShouldClose())
    {
        double now = GetTime();
        if (now - last_time >= 1.0)
        {
            i++;
            last_time = now;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        Vector2 center = {WIDTH / 2, HEIGHT / 2};
        drawDigit(getMinutes(), center, .5);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}