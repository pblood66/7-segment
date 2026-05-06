#include "segment.h"

void drawSegment(Vector2 center, bool horizontal, float scale)
{
    int count = 6;
    int width = SEGMENT_WIDTH / 2 * scale;
    int height = SEGMENT_HEIGHT / 2 * scale;

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

    DrawTriangleStrip(points, count, RED);
}