#ifndef OLED_H
#define OLED_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

// ========== KHAI BÁO HÀM ==========
void OLED_Init();
void OLED_Clear();
void OLED_Update();
void OLED_ShowMessage(const char* msg, int x, int y);
void OLED_DrawPixel(int x, int y, bool color);
void OLED_DrawRect(int x, int y, int w, int h, bool fill);
void OLED_DrawText(const char* text, int x, int y, int size);
void OLED_DrawScore(int score, int lives, int level);

// ========== BIẾN TOÀN CỤC ==========
extern Adafruit_SSD1306 display;

#endif // OLED_H