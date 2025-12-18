/*
 * button.c
 *
 *  Created on: Dec 18, 2025
 *      Author: Admin
 */


#include "periph/button.h"
#include "drivers/timebase.h"

static inline uint8_t pin_read_active(GPIO_TypeDef* port, uint16_t pin){
  return GPIO_ReadInputDataBit(port, pin) ? 0 : 1; /* active-LOW */
}

typedef struct {
	uint8_t last;
	uint32_t t;
} btn_state_t;

static btn_state_t b_sw1 = {0, 0}, b_sw2 = {0, 0}, b_sw3 = {0, 0}, b_sw4 = {0, 0}, b_sw5 = {0, 0};

static uint8_t btn_clicked(btn_state_t* st, uint8_t now){
  uint32_t ms = Millis();
  if(now != st->last && (ms - st->t) > 15){
    st->t = ms;
    st->last = now;
    if(now) return 1;
  }
  return 0;
}

void Input_Init(void){
  GPIO_InitTypeDef gi;

  /* Configure inputs with PULL-UPs */
  gi.GPIO_Pin   = SW1_PIN | SW2_PIN | SW5_PIN;   // PB5, PB3, PB4
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);

  gi.GPIO_Pin   = SW4_PIN; // PB0
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);

  gi.GPIO_Pin   = SW3_PIN; // PA4
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &gi);
}

uint8_t SW1_Click(void){ return btn_clicked(&b_sw1, pin_read_active(SW1_GPIOx, SW1_PIN)); }
uint8_t SW2_Click(void){ return btn_clicked(&b_sw2, pin_read_active(SW2_GPIOx, SW2_PIN)); }
uint8_t SW3_Click(void){ return btn_clicked(&b_sw3, pin_read_active(SW3_GPIOx, SW3_PIN)); }
uint8_t SW4_Click(void){ return btn_clicked(&b_sw4, pin_read_active(SW4_GPIOx, SW4_PIN)); }
uint8_t SW5_Click(void){ return btn_clicked(&b_sw5, pin_read_active(SW5_GPIOx, SW5_PIN)); }
