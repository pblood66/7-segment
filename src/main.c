#include <stdio.h>
#include <raylib.h>
#include <time.h>

#define WIDTH 900
#define HEIGHT 600
#define SEGMENT_WIDTH 200
#define SEGMENT_HEIGHT 50

void DrawSegment(Vector2 center, bool horizontal)
{
    int count = 6;
    int width = SEGMENT_WIDTH / 2;
    int height = SEGMENT_HEIGHT / 2;

    Vector2 a, b, c, d, e, f;

    if (horizontal)
    {
        a = (Vector2){center.x - width - height, center.y};
        b = (Vector2){center.x - width, center.y + height};
        c = (Vector2){center.x - width, center.y - height};
        d = (Vector2){center.x + width, center.y + height};
        e = (Vector2){center.x + width, center.y - height};
        f = (Vector2){center.x + width + height, center.y};
    }
    else
    {
        a = (Vector2){center.x, center.y + width + height};
        b = (Vector2){center.x + height, center.y + width};
        c = (Vector2){center.x - height, center.y + width};
        d = (Vector2){center.x + height, center.y - width};
        e = (Vector2){center.x - height, center.y - width};
        f = (Vector2){center.x, center.y - width - height};
    }
    Vector2 points[] = {a, b, c, d, e, f};

    BeginDrawing();
    DrawTriangleStrip(points, 6, RED);
    EndDrawing();
}

int main(int argc, char *argv[])
{

    time_t cur_time = time(NULL);

    char *c_time = ctime(&cur_time);
    printf("%s", c_time);

    InitWindow(WIDTH, HEIGHT, "7 Segment Clock");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        Vector2 center = {WIDTH / 2, HEIGHT / 2};
        DrawSegment(center, false);
        DrawSegment(center, true);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}