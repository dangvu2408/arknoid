#ifndef BUZZER_H
#define BUZZER_H

#include "config.h"

// ========== KHAI BÁO HÀM ==========
void Buzzer_Init();
void Buzzer_Beep(int frequency, int duration);
void Buzzer_Stop();
void Buzzer_PlayHit();
void Buzzer_PlayPaddle();
void Buzzer_PlayBrick();
void Buzzer_PlayGameOver();
void Buzzer_PlayLevelComplete();

#endif // BUZZER_H