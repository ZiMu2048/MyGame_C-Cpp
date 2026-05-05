#define _CRT_SECURE_NO_WARNINGS
#include "raylib.h"
#include "common.h"

void DrawBackground(void) {
    for (int Y = 0; Y <= ScreenHight; Y += 50) {
        DrawLine(0, Y, ScreenWidth, Y, BLACK);
    }
    for (int X = 0; X <= ScreenWidth; X += 50) {
        DrawLine(X, 0, X, ScreenHight, BLACK);
    }
}
