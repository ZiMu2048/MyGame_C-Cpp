#define _CRT_SECURE_NO_WARNINGS
#define Realse
#include "raylib.h"
#include "common.h"

typedef enum GameScreen { START = 0, PLAYING, GAMEOVER,WIN } GameScreen;

int main(void) {
    InitWindow(ScreenHight, ScreenWidth, "SnakeGame");//初始化窗口 (宽度, 高度, 标题)
    SetTargetFPS(60);
    InitRandom();//初始化随机
    InitApple();//初始化苹果
    InitSanke();

    GameScreen currentScreen = START;
    bool exitWindow = false;

    while (!WindowShouldClose()) {//主循环
        switch (currentScreen) {
        case START: {
            if (GetKeyPressed() != 0) {
                currentScreen = PLAYING; // 切换到游戏进行状态
            }
            break;
        }
        case PLAYING: {
            if (f_isAppleEaten()) {
                f_SnakeLength(true);
            }
            UpdateSnake();//更新状态
            if (f_Oops() == true) {
                currentScreen = GAMEOVER;
            }
            break;
        }
        case GAMEOVER: {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1)) {
                // 重新初始化游戏状态
                InitApple();
                InitSanke();
                Score = 0; // 重置分数
                currentScreen = PLAYING; // 再次进入游戏
            }
            else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2)) {
                exitWindow = true; // 触发退出条件
            }
            break;
        }
        case WIN: {
            if (Score == 400) {
                if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1)) {
                    // 重新初始化游戏状态
                    InitApple();
                    InitSanke();
                    Score = 0; // 重置分数
                    currentScreen = PLAYING; // 再次进入游戏
                }
                else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2)) {
                    exitWindow = true; // 触发退出条件
                }
                break;
            }
        }
        }
        //绘制函数
        BeginDrawing();//绘制帧开始
        ClearBackground(RAYWHITE); //清屏
        switch (currentScreen) {
        case START: {
            DrawText("Push Any Key to Start...", ScreenWidth / 2 - 140, ScreenHight / 2 - 20, 24, DARKGRAY);
            break;
        }
        case PLAYING: {
            DrawBackground();//绘制20*20背景
            DrawApple(AppleLocation.X, AppleLocation.Y);//绘制苹果
            DrawSnake();//绘制蛇
            DrawText(TextFormat("Score: %d", Score), 0, 0, 40, BLACK);
            break;
        }
        case GAMEOVER: {
            DrawText("GAME OVER", ScreenWidth / 2 - 100, ScreenHight / 2 - 60, 40, RED);
            DrawText("1. Restart", ScreenWidth / 2 - 60, ScreenHight / 2 + 10, 20, DARKGRAY);
            DrawText("2. Exit", ScreenWidth / 2 - 60, ScreenHight / 2 + 40, 20, DARKGRAY);
            break;
        }
        case WIN: {
            DrawText("WIN", ScreenWidth / 2 - 100, ScreenHight / 2 - 60, 40, RED);
            DrawText("1. Restart", ScreenWidth / 2 - 60, ScreenHight / 2 + 10, 20, DARKGRAY);
            DrawText("2. Exit", ScreenWidth / 2 - 60, ScreenHight / 2 + 40, 20, DARKGRAY);
            break;
        }
        }
        EndDrawing();//绘制帧结束
    }
    CloseWindow();//销毁窗口
    return 0;
}
