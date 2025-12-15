#include "led.h"

// ========== KHỞI TẠO LED ==========
void LED_Init() {
  Serial.println(F("Initializing LED..."));
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  Serial.println(F("LED initialized OK!"));
}

// ========== BẬT LED ==========
void LED_On() {
  digitalWrite(LED_PIN, HIGH);
}

// ========== TẮT LED ==========
void LED_Off() {
  digitalWrite(LED_PIN, LOW);
}

// ========== ĐẢO TRẠNG THÁI LED ==========
void LED_Toggle() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

// ========== NHÁY LED ==========
void LED_Blink(int times, int delayMs) {
  for (int i = 0; i < times; i++) {
    LED_On();
    delay(delayMs);
    LED_Off();
    delay(delayMs);
  }
}