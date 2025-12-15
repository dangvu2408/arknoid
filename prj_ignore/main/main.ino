#include "config.h"
#include "oled.h"
#include "button.h"
#include "led.h"
#include "buzzer.h"
#include "game.h"

// ========== SETUP ==========
void setup() {
  // Khởi tạo Serial (STM32 sử dụng Serial qua USB hoặc UART)
  Serial.begin(115200);
  while (!Serial && millis() < 3000); // Đợi Serial ready (timeout 3s)
  
  Serial.println(F("\n========================================"));
  Serial.println(F("   BREAKOUT GAME - STM32 VERSION"));
  Serial.println(F("========================================"));
  
  // Khởi tạo các module
  LED_Init();
  Buzzer_Init();
  Button_Init();
  OLED_Init();
  Game_Init();
  
  // Hiển thị thông báo khởi động
  OLED_ShowMessage("BREAKOUT\nSTM32 Ready!", 25, 20);
  LED_Blink(2, 200);
  delay(1500);
  
  Serial.println(F("System initialized successfully!"));
  Serial.println(F("========================================\n"));
}

// ========== LOOP ==========
void loop() {
  // Cập nhật trạng thái nút bấm
  Button_Update();
  
  // Cập nhật và vẽ game
  Game_Update();
  
  // Cập nhật hiển thị OLED
  OLED_Update();
  
  // Delay nhỏ để tránh quá tải CPU (STM32 chạy nhanh hơn Arduino)
  // Game_Update đã có frame limiting nên có thể bỏ delay này
  // delay(1);
}