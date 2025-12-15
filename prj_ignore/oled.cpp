#include "oled.h"

// Khởi tạo object OLED với I2C của STM32
// STM32 sử dụng Wire (PB6=SCL, PB7=SDA)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ========== KHỞI TẠO OLED ==========
void OLED_Init() {
  Serial.println(F("Initializing OLED..."));
  
  // Khởi tạo I2C cho STM32
  Wire.begin();
  Wire.setClock(400000); // 400kHz Fast Mode
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
    Serial.println(F("OLED init FAILED!"));
    while(1); // Dừng chương trình nếu lỗi
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();
  
  Serial.println(F("OLED initialized OK!"));
}

// ========== XÓA MÀN HÌNH ==========
void OLED_Clear() {
  display.clearDisplay();
}

// ========== CẬP NHẬT HIỂN THỊ ==========
void OLED_Update() {
  display.display();
}

// ========== HIỂN THỊ THÔNG BÁO ==========
void OLED_ShowMessage(const char* msg, int x, int y) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(x, y);
  display.println(msg);
  display.display();
}

// ========== VẼ PIXEL ==========
void OLED_DrawPixel(int x, int y, bool color) {
  display.drawPixel(x, y, color ? SSD1306_WHITE : SSD1306_BLACK);
}

// ========== VẼ HÌNH CHỮ NHẬT ==========
void OLED_DrawRect(int x, int y, int w, int h, bool fill) {
  if (fill) {
    display.fillRect(x, y, w, h, SSD1306_WHITE);
  } else {
    display.drawRect(x, y, w, h, SSD1306_WHITE);
  }
}

// ========== VẼ CHỮ ==========
void OLED_DrawText(const char* text, int x, int y, int size) {
  display.setTextSize(size);
  display.setCursor(x, y);
  display.print(text);
}

// ========== HIỂN THỊ ĐIỂM SỐ ==========
void OLED_DrawScore(int score, int lives, int level) {
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("S:"));
  display.print(score);
  display.print(F(" L:"));
  display.print(lives);
  display.print(F(" Lv"));
  display.print(level);
}