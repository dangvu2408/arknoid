#ifndef LED_H
#define LED_H

#include "config.h"

// ========== KHAI BÁO HÀM ==========
void LED_Init();
void LED_On();
void LED_Off();
void LED_Toggle();
void LED_Blink(int times, int delayMs);

#endif // LED_H