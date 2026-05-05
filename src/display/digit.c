#include "segment.h"
#include "digit.h"
#include <stdint.h>

void drawDigit(int digit, Vector2 center) {
    static const uint8_t SEGMENTS[10] = {
        0b1110111, // 0
        0b0100100, // 1
        0b1011101, // 2
        0b1101101, // 3
        0b0101110, // 4
        0b1101011, // 5
        0b1111011, // 6
        0b0100101, // 7
        0b1111111, // 8 
        0b1101111  // 9
    };

    static const SegmentLayout LAYOUT[7] = {
        {{0, -SEGMENT_WIDTH}, true},  // a
        {{-SEGMENT_WIDTH / 2, -SEGMENT_WIDTH / 2}, false}, // b
        {{SEGMENT_WIDTH / 2, -SEGMENT_WIDTH / 2}, false}, // c
        {{0, 0}, true},  // d
        {{-SEGMENT_WIDTH / 2, SEGMENT_WIDTH / 2}, false}, // e
        {{SEGMENT_WIDTH / 2, SEGMENT_WIDTH / 2}, false}, // f
        {{0, SEGMENT_WIDTH}, true},  // g
    };

    
    uint8_t mask = SEGMENTS[digit];
    for (int i = 0; i < 7; i++) {
        if (mask & (1 << i)) {
            Vector2 pos = {
                center.x + LAYOUT[i].offset.x,
                center.y + LAYOUT[i].offset.y,
            };
            drawSegment(pos, LAYOUT[i].horizontal);
        }
    }
}