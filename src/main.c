#include <stdio.h>
#include <raylib.h>
#include <time.h>

#define WIDTH 900
#define HEIGHT 600
#define SEGMENT_WIDTH 200
#define SEGMENT_HEIGHT 50

void DrawSegment(Vector2 center)
{
    int count = 6;

    Vector2 a, b, c, d, e, f;
    a = (Vector2){center.x - SEGMENT_WIDTH / 2 - SEGMENT_HEIGHT / 2, center.y};
    b = (Vector2){center.x - SEGMENT_WIDTH / 2, center.y + SEGMENT_HEIGHT / 2};
    c = (Vector2){center.x - SEGMENT_WIDTH / 2, center.y - SEGMENT_HEIGHT / 2};
    d = (Vector2){center.x + SEGMENT_WIDTH / 2, center.y + SEGMENT_HEIGHT / 2};
    e = (Vector2){center.x + SEGMENT_WIDTH / 2, center.y - SEGMENT_HEIGHT / 2};
    f = (Vector2){center.x + SEGMENT_WIDTH / 2 + SEGMENT_HEIGHT / 2, center.y};
    Vector2 points[] = {a, b, c, d, e, f};


    DrawTriangleStrip(points, 6, RED);
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
        DrawSegment(center);
       
        EndDrawing();
    }

    CloseWindow();

    return 0;
}