#ifndef COMMON_H
#define COMMON_H

#define ScreenWidth 1000
#define ScreenHight 1000
#define AppleRadius 20
#define RectangleWidth 50
#define RectangleHight 50
#define AppleNum 20
#define Speed 0.20f

struct Vector {
    int X;
    int Y;
};
extern struct Vector Vector2;//二维坐标
struct Snake {
    Vector body[400];//身体坐标
    int length;//身体长度
    Vector direction;//移动向量
};
extern struct Snake SnakeBody;

struct Apple {
    int X;
    int Y;
};
extern struct Apple AppleLocation;//苹果坐标

extern bool isAppleEaten;//苹果状态

extern bool isGameOver;

extern int Score;

void DrawBackground(void);
void DrawBody(int RB_X, int RB_Y);
void InitRandom(void);
int Random_Apple_Coordinate(void);
void InitApple(void);
bool f_isAppleEaten(void);
void InitSanke(void);
void UpdateSnake(void);
void f_SnakeLength(bool isAppleEaten);
bool f_Oops(void);
void DrawSnake(void); 
void DrawApple(int A_X, int A_Y);
void DrawHead(int RH_X, int RH_Y);
#endif
