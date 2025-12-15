#include "game.h"
#include "oled.h"
#include "button.h"
#include "led.h"
#include "buzzer.h"

// ========== BIẾN GAME ==========
GameState currentState = STATE_MENU;
int currentLevel = 1;
int score = 0;
int lives = MAX_LIVES;

Paddle paddle;
Ball ball;
bool bricks[BRICK_ROWS][BRICK_COLS];
int bricksRemaining = 0;

unsigned long lastFrameTime = 0;
int frameDelay = 20;
bool levelChangeMode = false;

// ========== KHỞI TẠO GAME ==========
void Game_Init() {
  Serial.println(F("Initializing Game..."));
  
  currentState = STATE_MENU;
  currentLevel = 1;
  
  // Khởi tạo paddle
  paddle.x = (SCREEN_WIDTH - PADDLE_WIDTH) / 2;
  paddle.y = SCREEN_HEIGHT - 6;
  paddle.width = PADDLE_WIDTH;
  paddle.height = PADDLE_HEIGHT;
  paddle.speed = PADDLE_SPEED;
  
  // Khởi tạo ball
  ball.x = SCREEN_WIDTH / 2;
  ball.y = SCREEN_HEIGHT / 2;
  ball.speedX = 2.0;
  ball.speedY = -2.0;
  ball.size = BALL_SIZE;
  
  Serial.println(F("Game initialized OK!"));
}

// ========== CẬP NHẬT GAME ==========
void Game_Update() {
  unsigned long currentTime = millis();
  
  // Giới hạn frame rate
  if (currentTime - lastFrameTime < frameDelay) {
    return;
  }
  lastFrameTime = currentTime;
  
  // Xử lý theo state
  switch(currentState) {
    case STATE_MENU:
      Game_UpdateMenu();
      break;
    case STATE_PLAYING:
      Game_UpdatePlaying();
      break;
    case STATE_GAME_OVER:
      Game_UpdateGameOver();
      break;
    case STATE_LEVEL_COMPLETE:
      Game_UpdateLevelComplete();
      break;
  }
  
  // Vẽ game
  Game_Draw();
}

// ========== BẮT ĐẦU GAME MỚI ==========
void Game_Start() {
  currentState = STATE_PLAYING;
  score = 0;
  lives = MAX_LIVES;
  
  // Reset paddle
  paddle.x = (SCREEN_WIDTH - paddle.width) / 2;
  
  // Reset ball
  ball.x = SCREEN_WIDTH / 2;
  ball.y = SCREEN_HEIGHT / 2;
  
  // Tốc độ theo level
  if (currentLevel == 1) {
    ball.speedX = 1.5;
    ball.speedY = -1.5;
    frameDelay = 25;
  } else {
    ball.speedX = 2.0;
    ball.speedY = -2.0;
    frameDelay = 16;
  }
  
  // Khởi tạo gạch
  Game_InitBricks();
  
  Buzzer_Beep(1200, 150);
}

// ========== RESET GAME ==========
void Game_Reset() {
  ball.x = SCREEN_WIDTH / 2;
  ball.y = SCREEN_HEIGHT / 2;
  ball.speedY = -abs(ball.speedY);
  paddle.x = (SCREEN_WIDTH - paddle.width) / 2;
}

// ========== KHỞI TẠO GẠCH ==========
void Game_InitBricks() {
  bricksRemaining = 0;
  int rows = (currentLevel == 1) ? 3 : 4;
  
  for (int row = 0; row < BRICK_ROWS; row++) {
    for (int col = 0; col < BRICK_COLS; col++) {
      if (row < rows) {
        bricks[row][col] = true;
        bricksRemaining++;
      } else {
        bricks[row][col] = false;
      }
    }
  }
  
  Serial.print(F("Bricks initialized: "));
  Serial.println(bricksRemaining);
}

// ========== CẬP NHẬT MENU ==========
void Game_UpdateMenu() {
  // Kiểm tra giữ nút phải để đổi level
  if (Button_GetHoldTime() > 2000 && !levelChangeMode) {
    levelChangeMode = true;
    currentLevel = (currentLevel == 1) ? 2 : 1;
    Buzzer_Beep(1500, 200);
    Serial.print(F("Level changed to: "));
    Serial.println(currentLevel);
  }
  
  if (!Button_IsRightPressed()) {
    levelChangeMode = false;
  }
  
  // Nhấn nút trái để bắt đầu
  if (Button_IsLeftJustPressed()) {
    Game_Start();
  }
}

// ========== CẬP NHẬT PLAYING ==========
void Game_UpdatePlaying() {
  Game_MovePaddle();
  Game_MoveBall();
  Game_CheckCollisions();
  
  // Kiểm tra hoàn thành level
  if (bricksRemaining == 0) {
    currentState = STATE_LEVEL_COMPLETE;
    Buzzer_PlayLevelComplete();
  }
}

// ========== DI CHUYỂN PADDLE ==========
void Game_MovePaddle() {
  if (Button_IsLeftPressed() && paddle.x > 0) {
    paddle.x -= paddle.speed;
    if (paddle.x < 0) paddle.x = 0;
  }
  
  if (Button_IsRightPressed() && paddle.x < SCREEN_WIDTH - paddle.width) {
    paddle.x += paddle.speed;
    if (paddle.x > SCREEN_WIDTH - paddle.width) {
      paddle.x = SCREEN_WIDTH - paddle.width;
    }
  }
}

// ========== DI CHUYỂN BÓNG ==========
void Game_MoveBall() {
  ball.x += ball.speedX;
  ball.y += ball.speedY;
}

// ========== KIỂM TRA VA CHẠM ==========
void Game_CheckCollisions() {
  Game_CheckWallCollision();
  Game_CheckPaddleCollision();
  Game_CheckBrickCollision();
  Game_CheckBallLost();
}

// ========== VA CHẠM TƯỜNG ==========
void Game_CheckWallCollision() {
  // Tường trái/phải
  if (ball.x <= 0 || ball.x >= SCREEN_WIDTH - ball.size) {
    ball.speedX = -ball.speedX;
    Buzzer_PlayHit();
  }
  
  // Tường trên
  if (ball.y <= 8) {
    ball.speedY = -ball.speedY;
    Buzzer_PlayHit();
  }
}

// ========== VA CHẠM PADDLE ==========
void Game_CheckPaddleCollision() {
  if (ball.y + ball.size >= paddle.y && 
      ball.y + ball.size <= paddle.y + paddle.height &&
      ball.x + ball.size >= paddle.x && 
      ball.x <= paddle.x + paddle.width) {
    
    ball.speedY = -abs(ball.speedY);
    Buzzer_PlayPaddle();
    
    // Thay đổi góc dựa vào vị trí chạm
    float hitPos = (ball.x - paddle.x) / (float)paddle.width;
    ball.speedX = (hitPos - 0.5) * 5.0;
  }
}
void Game_CheckBrickCollision() {
  int brickStartY = 10;
  
  for (int row = 0; row < BRICK_ROWS; row++) {
    for (int col = 0; col < BRICK_COLS; col++) {
      if (!bricks[row][col]) continue;
      
      int brickX = col * (BRICK_WIDTH + 2) + 2;
      int brickY = row * (BRICK_HEIGHT + 2) + brickStartY;
      
      // Kiểm tra va chạm
      if (ball.x + ball.size >= brickX && 
          ball.x <= brickX + BRICK_WIDTH &&
          ball.y + ball.size >= brickY && 
          ball.y <= brickY + BRICK_HEIGHT) {
        
        // Xóa gạch
        bricks[row][col] = false;
        bricksRemaining--;
        score += 10;
        
        // Đổi hướng ball
        ball.speedY = -ball.speedY;
        
        Buzzer_PlayBrick();
        
        Serial.print(F("Brick destroyed! Remaining: "));
        Serial.println(bricksRemaining);
        return;
      }
    }
  }
}

// ========== KIỂM TRA BÓNG RƠI ==========
void Game_CheckBallLost() {
  if (ball.y > SCREEN_HEIGHT) {
    lives--;
    Buzzer_PlayGameOver();
    
    Serial.print(F("Ball lost! Lives: "));
    Serial.println(lives);
    
    if (lives <= 0) {
      currentState = STATE_GAME_OVER;
      LED_Blink(3, 200);
    } else {
      Game_Reset();
    }
  }
}

// ========== CẬP NHẬT GAME OVER ==========
void Game_UpdateGameOver() {
  if (Button_IsLeftJustPressed()) {
    currentState = STATE_MENU;
    delay(300);
  }
}

// ========== CẬP NHẬT LEVEL COMPLETE ==========
void Game_UpdateLevelComplete() {
  static unsigned long completeTime = 0;
  
  if (completeTime == 0) {
    completeTime = millis();
  }
  
  if (millis() - completeTime > 3000) {
    completeTime = 0;
    
    if (currentLevel < 2) {
      currentLevel++;
      Game_Start();
    } else {
      currentState = STATE_MENU;
      currentLevel = 1;
    }
  }
}

// ========== VẼ GAME ==========
void Game_Draw() {
  OLED_Clear();
  
  switch(currentState) {
    case STATE_MENU:
      Game_DrawMenu();
      break;
    case STATE_PLAYING:
      Game_DrawPlaying();
      break;
    case STATE_GAME_OVER:
      Game_DrawGameOver();
      break;
    case STATE_LEVEL_COMPLETE:
      Game_DrawLevelComplete();
      break;
  }
}

// ========== VẼ MENU ==========
void Game_DrawMenu() {
  OLED_DrawText("BREAKOUT", 25, 5, 2);
  
  char buffer[32];
  sprintf(buffer, "Level: %d", currentLevel);
  OLED_DrawText(buffer, 35, 25, 1);
  
  OLED_DrawText("LEFT: Start", 20, 38, 1);
  OLED_DrawText("Hold RIGHT: Level", 5, 50, 1);
}

// ========== VẼ PLAYING ==========
void Game_DrawPlaying() {
  // Vẽ điểm số
  OLED_DrawScore(score, lives, currentLevel);
  
  // Vẽ gạch
  Game_DrawBricks();
  
  // Vẽ paddle
  Game_DrawPaddle();
  
  // Vẽ ball
  Game_DrawBall();
}

// ========== VẼ GẠCH ==========
void Game_DrawBricks() {
  int brickStartY = 10;
  
  for (int row = 0; row < BRICK_ROWS; row++) {
    for (int col = 0; col < BRICK_COLS; col++) {
      if (bricks[row][col]) {
        int x = col * (BRICK_WIDTH + 2) + 2;
        int y = row * (BRICK_HEIGHT + 2) + brickStartY;
        OLED_DrawRect(x, y, BRICK_WIDTH, BRICK_HEIGHT, true);
      }
    }
  }
}

// ========== VẼ PADDLE ==========
void Game_DrawPaddle() {
  OLED_DrawRect(paddle.x, paddle.y, paddle.width, paddle.height, true);
}

// ========== VẼ BÓNG ==========
void Game_DrawBall() {
  OLED_DrawRect((int)ball.x, (int)ball.y, ball.size, ball.size, true);
}

// ========== VẼ GAME OVER ==========
void Game_DrawGameOver() {
  OLED_DrawText("GAME OVER", 20, 10, 2);
  
  char buffer[32];
  sprintf(buffer, "Score: %d", score);
  OLED_DrawText(buffer, 30, 35, 1);
  
  OLED_DrawText("LEFT: Menu", 25, 52, 1);
}

// ========== VẼ LEVEL COMPLETE ==========
void Game_DrawLevelComplete() {
  OLED_DrawText("LEVEL", 35, 10, 2);
  OLED_DrawText("COMPLETE!", 20, 28, 2);
  
  char buffer[32];
  sprintf(buffer, "Score: %d", score);
  OLED_DrawText(buffer, 30, 50, 1);
}