#define _CRT_SECURE_NO_WARNINGS
#include "raylib.h"
#include "common.h"

struct Vector Vector2;
struct Snake SnakeBody;
bool isGameOver = false;

void DrawHead(int RH_X, int RH_Y) {//绘制蛇头
	DrawRectangle(RH_X, RH_Y, RectangleWidth, RectangleWidth, GREEN);
}

void DrawBody(int RB_X, int RB_Y) {//绘制蛇身
	DrawRectangle(RB_X, RB_Y, RectangleWidth, RectangleWidth, BLACK);
}

void InitSanke(void) {
	SnakeBody.length = 3;
	SnakeBody.direction.X = 1;//右
	SnakeBody.direction.Y = 0;

	for (int i = 0; i < SnakeBody.length; i++) {
		SnakeBody.body[i].X = (ScreenWidth / 2) - (i * RectangleWidth);
		SnakeBody.body[i].Y = (ScreenHight / 2);
	}
}

void UpdateSnake(void) {
	static float moveTimer = 0.0f;
	static float moveInterval = Speed;//静态变量!!!

	if (IsKeyPressed(KEY_UP) && SnakeBody.direction.Y != 1) {
		SnakeBody.direction.X = 0; 
		SnakeBody.direction.Y = -1;
	}
	else if (IsKeyPressed(KEY_DOWN) && SnakeBody.direction.Y != -1) {
		SnakeBody.direction.X = 0; 
		SnakeBody.direction.Y = 1;
	}
	else if (IsKeyPressed(KEY_LEFT) && SnakeBody.direction.X != 1) {
		SnakeBody.direction.X = -1; 
		SnakeBody.direction.Y = 0;
	}
	else if (IsKeyPressed(KEY_RIGHT) && SnakeBody.direction.X != -1) {
		SnakeBody.direction.X = 1; 
		SnakeBody.direction.Y = 0;
	}//向量归一化

	// 累加这一帧经过的时间
	moveTimer += GetFrameTime();

	if (moveTimer >= moveInterval) {
		//倒时序!!更新由后向前，所以蛇尾巴先继承前一位位置!!
		for (int i = SnakeBody.length - 1; i > 0; i--) {
			SnakeBody.body[i] = SnakeBody.body[i - 1];//重复前一位坐标
		}
		//身体位移

		SnakeBody.body[0].X += SnakeBody.direction.X * RectangleWidth;
		SnakeBody.body[0].Y += SnakeBody.direction.Y * RectangleHight;
		//舌头位移

		if (SnakeBody.body[0].Y >= ScreenHight) {
			SnakeBody.body[0].Y = 0;
		}//下->上
		else if (SnakeBody.body[0].Y < 0) {
			SnakeBody.body[0].Y = ScreenHight - RectangleHight;
		}//上->下
		else if (SnakeBody.body[0].X >= ScreenWidth) {
			SnakeBody.body[0].X = 0;
		}//右->左
		else if (SnakeBody.body[0].X < 0) {
			SnakeBody.body[0].X = ScreenWidth - RectangleWidth;
		}//左->右

		moveTimer -= moveInterval;//重记时
	}
}

void f_SnakeLength(bool isAppleEaten) {
	if (isAppleEaten) {
		SnakeBody.length += 1;
	}
}

bool f_Oops(void) {
	for (int i = 1; i < SnakeBody.length; i++) {
		if (SnakeBody.body[0].X == SnakeBody.body[i].X && SnakeBody.body[0].Y == SnakeBody.body[i].Y) {
			return true;
		}
	}
	return false;
}

void DrawSnake(void) {
	for (int i = 0; i < SnakeBody.length; i++) {
		if (i == 0) {
			DrawHead(SnakeBody.body[i].X, SnakeBody.body[i].Y);
		}
		else {
			DrawBody(SnakeBody.body[i].X, SnakeBody.body[i].Y);
		}
	}
}
