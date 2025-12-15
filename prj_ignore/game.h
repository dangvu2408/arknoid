#ifndef GAME_H
#define GAME_H

#include "config.h"

// ========== CẤU TRÚC DỮ LIỆU ==========
struct Paddle {
  int x;
  int y;
  int width;
  int height;
  int speed;
};

struct Ball {
  float x;
  float y;
  float speedX;
  float speedY;
  int size;
};

// ========== BIẾN TOÀN CỤC ==========
extern GameState currentState;
extern int currentLevel;
extern int score;
extern int lives;
extern Paddle paddle;
extern Ball ball;
extern bool bricks[BRICK_ROWS][BRICK_COLS];
extern int bricksRemaining;
extern unsigned long lastFrameTime;
extern int frameDelay;

// ========== KHAI BÁO HÀM ==========
void Game_Init();
void Game_Update();
void Game_Start();
void Game_Reset();

// State handlers
void Game_UpdateMenu();
void Game_UpdatePlaying();
void Game_UpdateGameOver();
void Game_UpdateLevelComplete();

// Game logic
void Game_InitBricks();
void Game_MovePaddle();
void Game_MoveBall();
void Game_CheckCollisions();
void Game_CheckBrickCollision();
void Game_CheckWallCollision();
void Game_CheckPaddleCollision();
void Game_CheckBallLost();

// Drawing
void Game_Draw();
void Game_DrawMenu();
void Game_DrawPlaying();
void Game_DrawGameOver();
void Game_DrawLevelComplete();
void Game_DrawBricks();
void Game_DrawPaddle();
void Game_DrawBall();

#endif // GAME_H