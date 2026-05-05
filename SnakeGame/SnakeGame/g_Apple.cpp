#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include <stdlib.h>
#include <time.h>

int Location[AppleNum] = { 25,75,125,175,225,275,325,375,425,475,525,575,625,675,725,775,825,875,925,975};
struct Apple AppleLocation;
bool isAppleEaten = false;

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

bool f_isAppleEaten(bool isAppleEaten) {
    if (isAppleEaten) {
        AppleLocation.X = Random_Apple_Coordinate();
        AppleLocation.Y = Random_Apple_Coordinate();
        return false; //∑¿÷π÷ÿ∏¥…˙≥…
    }
    return isAppleEaten;
}

