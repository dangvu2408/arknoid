#include "button.h"
#include "buzzer.h"

// ========== BIẾN MODULE ==========
bool btnLeftState = false;
bool btnRightState = false;
bool btnLeftLastState = false;
bool btnRightLastState = false;
unsigned long btnHoldStartTime = 0;

// ========== KHỞI TẠO NÚT BẤM ==========
void Button_Init() {
  Serial.println(F("Initializing Buttons..."));
  
  // STM32 sử dụng INPUT_PULLUP tương tự Arduino
  pinMode(BTN_LEFT_PIN, INPUT_PULLUP);
  pinMode(BTN_RIGHT_PIN, INPUT_PULLUP);
  
  btnLeftState = false;
  btnRightState = false;
  btnLeftLastState = false;
  btnRightLastState = false;
  btnHoldStartTime = 0;
  
  Serial.println(F("Buttons initialized OK!"));
}

// ========== CẬP NHẬT TRẠNG THÁI NÚT ==========
void Button_Update() {
  // Lưu trạng thái cũ
  btnLeftLastState = btnLeftState;
  btnRightLastState = btnRightState;
  
  // Đọc trạng thái mới (LOW = nhấn vì dùng INPUT_PULLUP)
  btnLeftState = (digitalRead(BTN_LEFT_PIN) == LOW);
  btnRightState = (digitalRead(BTN_RIGHT_PIN) == LOW);
  
  // Phát âm thanh khi vừa nhấn nút
  if (Button_IsLeftJustPressed()) {
    Buzzer_Beep(800, 30);
  }
  if (Button_IsRightJustPressed()) {
    Buzzer_Beep(800, 30);
  }
  
  // Theo dõi thời gian giữ nút phải
  if (btnRightState && !btnRightLastState) {
    btnHoldStartTime = millis();
  } else if (!btnRightState) {
    btnHoldStartTime = 0;
  }
}

// ========== KIỂM TRA NÚT TRÁI ĐANG NHẤN ==========
bool Button_IsLeftPressed() {
  return btnLeftState;
}

// ========== KIỂM TRA NÚT PHẢI ĐANG NHẤN ==========
bool Button_IsRightPressed() {
  return btnRightState;
}

// ========== KIỂM TRA NÚT TRÁI VỪA NHẤN ==========
bool Button_IsLeftJustPressed() {
  return (btnLeftState && !btnLeftLastState);
}

// ========== KIỂM TRA NÚT PHẢI VỪA NHẤN ==========
bool Button_IsRightJustPressed() {
  return (btnRightState && !btnRightLastState);
}

// ========== LẤY THỜI GIAN GIỮ NÚT ==========
unsigned long Button_GetHoldTime() {
  if (btnHoldStartTime == 0) {
    return 0;
  }
  return millis() - btnHoldStartTime;
}

// ========== RESET THỜI GIAN GIỮ NÚT ==========
void Button_ResetHold() {
  btnHoldStartTime = 0;
}