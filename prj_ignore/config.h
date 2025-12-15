#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ========== CẤU HÌNH CHÂN GPIO STM32 ==========
// Sử dụng chân GPIO của STM32 (Blue Pill)
#define BTN_LEFT_PIN    PB12
#define BTN_RIGHT_PIN   PB13
#define LED_PIN         PC13  // LED onboard
#define BUZZER_PIN      PB8

// ========== CẤU HÌNH OLED ==========
#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64
#define OLED_I2C_ADDR   0x3C

// STM32 I2C pins (mặc định Wire)
// SDA: PB7
// SCL: PB6

// ========== CẤU HÌNH GAME ==========
#define PADDLE_WIDTH    20
#define PADDLE_HEIGHT   3
#define PADDLE_SPEED    3
#define BALL_SIZE       2

#define BRICK_ROWS      4
#define BRICK_COLS      8
#define BRICK_WIDTH     14
#define BRICK_HEIGHT    4

#define MAX_LIVES       3

// ========== GAME STATES ==========
enum GameState {
  STATE_MENU,
  STATE_PLAYING,
  STATE_GAME_OVER,
  STATE_LEVEL_COMPLETE,
  STATE_PAUSED
};

#endif // CONFIG_H