#ifndef BUTTON_H
#define BUTTON_H

#include "config.h"

// ========== KHAI BÁO HÀM ==========
void Button_Init();
void Button_Update();
bool Button_IsLeftPressed();
bool Button_IsRightPressed();
bool Button_IsLeftJustPressed();
bool Button_IsRightJustPressed();
unsigned long Button_GetHoldTime();
void Button_ResetHold();

// ========== BIẾN TOÀN CỤC ==========
extern bool btnLeftState;
extern bool btnRightState;
extern bool btnLeftLastState;
extern bool btnRightLastState;
extern unsigned long btnHoldStartTime;

#endif // BUTTON_H