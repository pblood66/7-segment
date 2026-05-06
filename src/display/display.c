#include "display.h"
#include "segment.h"
#include "digit.h"

void drawClock(int hours, int minutes, int seconds, Vector2 center, float scale)
{
    int values[6] = {
        hours / 10, hours % 10,
        minutes / 10, minutes % 10,
        seconds / 10, seconds % 10
    };

    float spacing = SEGMENT_WIDTH * scale;

    float start_x = center.x - spacing * 4.75f;
    float cur_x = start_x;
    
    for (int i = 0; i < 6; i++) {
        Vector2 pos = { cur_x, center.y};
        drawDigit(values[i], pos, scale);

        if (i % 2 == 0) {
            cur_x = cur_x + (1.5f * spacing);
        } else {
            cur_x = cur_x + (2.5f * spacing);
        }
    }

}