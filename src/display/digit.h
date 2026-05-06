#pragma once
#include <include/raylib.h>

typedef struct {
    Vector2 offset;  // relative to digit center
    bool horizontal;
} SegmentLayout;

void drawDigit(int digit, Vector2 center, float scale);