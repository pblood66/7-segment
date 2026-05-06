# 7-Segment Clock

A real-time digital clock rendered using a software 7-segment display, written in C with [raylib](https://www.raylib.com/). Built as a learning project to explore low-level graphics programming, data-driven design, and clean C project structure.

![7-segment clock displaying the current time in red segments on a black background]()

---

## About the Project

This project was an exercise in breaking a visual problem down into composable layers. Rather than drawing a clock directly, the display is built up from primitives: individual segment polygons compose into digits, digits compose into a full clock face. Each layer knows nothing about the layers above it.

Key concepts explored:

- **Bitmask encoding** — each digit 0–9 is encoded as a 7-bit integer where each bit maps to a named segment (a–g). Checking whether a segment should be lit is a single bitwise operation.
- **Data-driven rendering** — segment positions and orientations are stored as a static lookup table of offsets and flags rather than hardcoded in drawing logic, making the layout easy to reason about and adjust.
- **Separation of concerns** — timekeeping (`clock/`) is entirely decoupled from rendering (`display/`). `main.c` is the only place they meet.
- **Resizable window support** — the clock reflows automatically when the window is resized using raylib's `FLAG_WINDOW_RESIZABLE` and `GetScreenWidth()`/`GetScreenHeight()`.

---

## Project Structure

```
src/
├── main.c                  # Entry point — wires clock and display together
├── clock/
│   ├── clock.h
│   └── clock.c             # Reads local time via time.h (hours, minutes, seconds)
└── display/
    ├── segment.h / .c      # Draws a single hexagonal segment polygon
    ├── digit.h / .c        # Bitmask lookup + segment layout; draws one digit
    └── display.h / .c      # Positions all 6 digits and renders the full clock face
```

### Layer responsibilities

| Layer | Knows about | Does not know about |
|---|---|---|
| `segment` | How to draw one polygon | What digit it belongs to |
| `digit` | Bitmasks, segment layout | What time it is |
| `display` | Digit spacing, clock layout | How segments are drawn |
| `clock` | `time.h`, system time | Anything visual |
| `main` | All of the above | Implementation details of any layer |

---

## How the Segment Encoding Works

Each of the 7 segments is assigned a bit position:

```
 aaa
b   c       Bit: 6=g  5=f  4=e  3=d  2=c  1=b  0=a
b   c
 ddd
e   f
e   f
 ggg
```

Each digit is a `uint8_t` where a `1` bit means the segment is lit:

```c
static const uint8_t SEGMENTS[10] = {
    0b1110111, // 0
    0b0100100, // 1
    0b1011101, // 2
    ...
};
```

To draw a digit, the code loops over all 7 segments and checks the corresponding bit:

```c
for (int i = 0; i < 7; i++) {
    Color color = (mask & (1 << i)) ? RED : DIM;
    drawSegment(pos, LAYOUT[i].horizontal, scale, color);
}
```

Unlit segments are drawn in a dim color rather than skipped, giving the display a realistic inactive-segment appearance.

---

## Building

### Prerequisites

- [raylib](https://www.raylib.com/) installed (tested with raylib 4.x)
- GCC (via [MSYS2/UCRT64](https://www.msys2.org/) on Windows, or system GCC on Linux/macOS)

### Build command

```bash
gcc src/main.c src/display/digit.c src/display/segment.c src/clock/clock.c src/display/display.c \
    -o main \
    -IC:/raylib/src -LC:/raylib/src \
    -lraylib -lopengl32 -lgdi32 -lwinmm \
    -Wall -Wextra
```

### VS Code

A `tasks.json` build task is included. Open the project in VS Code and run **Terminal → Run Build Task** (or `Ctrl+Shift+B`).

---

## What I Learned

This project was intentionally small in scope but rich in decisions. Some things that came out of building it:

- How to structure a C project into logical modules with clean header interfaces
- Why constant data belongs in `static const` arrays rather than global variables or helper functions
- How bitmasks make lookup tables compact and efficient for this kind of state
- The importance of keeping rendering concerns out of logic layers — the clock module has no knowledge of raylib at all
- How a single `scale` parameter can propagate cleanly through a call stack to make a UI resolution-independent

---
