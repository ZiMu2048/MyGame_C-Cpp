#define _CRT_SECURE_NO_WARNINGS
#include "raylib.h"
#include "common.h"
#include <stdlib.h>
#include <time.h>

int Location[AppleNum] = { 25,75,125,175,225,275,325,375,425,475,525,575,625,675,725,775,825,875,925,975 };
struct Apple AppleLocation;
bool isAppleEaten = false;
int Score = 0;

void InitRandom(void) {
    srand((unsigned int)time(NULL));
}

int Random_Apple_Coordinate(void) {
    static int len = 0;
    if (len == 0) len = sizeof(Location) / sizeof(Location[0]);
    int index = rand() % len;
    return Location[index];
}

void InitApple(void) {
    AppleLocation.X = Random_Apple_Coordinate();
    AppleLocation.Y = Random_Apple_Coordinate();
}

bool f_isAppleEaten(void) {
    if ((SnakeBody.body[0].X + 25) == AppleLocation.X && (SnakeBody.body[0].Y + 25) == AppleLocation.Y) {
        AppleLocation.X = Random_Apple_Coordinate();
        AppleLocation.Y = Random_Apple_Coordinate();
        Score++;
        return true;
    }
    else {
        for (int i = 1; i < SnakeBody.length; i++) {
            if (SnakeBody.body[i].X + 25 == AppleLocation.X && SnakeBody.body[i].Y + 25 == AppleLocation.Y) {
                AppleLocation.X = Random_Apple_Coordinate();
                AppleLocation.Y = Random_Apple_Coordinate();
            }
        }
    }
    return false;
}

void DrawApple(int A_X, int A_Y) {//»æÖÆÆ»¹û
    DrawCircle(A_X, A_Y, AppleRadius, RED);
}
