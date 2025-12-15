#include "buzzer.h"

// Biến cho tone trên STM32
static unsigned long toneEndTime = 0;
static bool toneActive = false;

// ========== KHỞI TẠO BUZZER ==========
void Buzzer_Init() {
  Serial.println(F("Initializing Buzzer..."));
  
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println(F("Buzzer initialized OK!"));
}

// ========== PHÁT ÂM THANH ==========
void Buzzer_Beep(int frequency, int duration) {
  // STM32 có thể sử dụng tone() nếu có thư viện hỗ trợ
  // Hoặc sử dụng PWM thủ công
  tone(BUZZER_PIN, frequency, duration);
  
  // Nếu tone() không hoạt động, có thể dùng cách này:
  /*
  toneActive = true;
  toneEndTime = millis() + duration;
  // Sử dụng timer hoặc PWM để tạo tần số
  */
}

// ========== CẬP NHẬT BUZZER (gọi trong loop nếu cần) ==========
void Buzzer_Update() {
  if (toneActive && millis() >= toneEndTime) {
    Buzzer_Stop();
  }
}

// ========== DỪNG ÂM THANH ==========
void Buzzer_Stop() {
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
  toneActive = false;
}

// ========== ÂM THANH VA CHẠM TƯỜNG ==========
void Buzzer_PlayHit() {
  Buzzer_Beep(600, 30);
}

// ========== ÂM THANH CHẠM PADDLE ==========
void Buzzer_PlayPaddle() {
  Buzzer_Beep(1000, 50);
}

// ========== ÂM THANH PHÁ GẠCH ==========
void Buzzer_PlayBrick() {
  Buzzer_Beep(1200, 40);
}

// ========== ÂM THANH GAME OVER ==========
void Buzzer_PlayGameOver() {
  Buzzer_Beep(200, 300);
}

// ========== ÂM THANH HOÀN THÀNH LEVEL ==========
void Buzzer_PlayLevelComplete() {
  Buzzer_Beep(1500, 100);
  delay(150);
  Buzzer_Beep(1800, 100);
  delay(150);
  Buzzer_Beep(2000, 200);
}