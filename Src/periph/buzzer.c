/*
 * buzzer.c
 *
 *  Created on: Dec 18, 2025
 *      Author: Admin
 */


#include "periph/buzzer.h"
#include "drivers/timebase.h"

void Buzzer_Init(void){
  GPIO_InitTypeDef gi;
  gi.GPIO_Pin   = BUZZ_PIN;
  gi.GPIO_Mode  = GPIO_Mode_OUT;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(BUZZ_GPIOx, &gi);
  GPIO_ResetBits(BUZZ_GPIOx, BUZZ_PIN);
}

void Buzzer_Beep(uint16_t ms){
  GPIO_SetBits(BUZZ_GPIOx, BUZZ_PIN);
  Delay_ms(ms);
  GPIO_ResetBits(BUZZ_GPIOx, BUZZ_PIN);
}
