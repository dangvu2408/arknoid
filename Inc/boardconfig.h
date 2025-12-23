/*
 * boardconfig.h
 *
 *  Created on: Dec 7, 2025
 *      Author: Dang Vu
 */

// file function unknown

#ifndef BOARDCONFIG_H_
#define BOARDCONFIG_H_

#include <stdint.h>
#include <stdbool.h>
#include <stm32f401re.h>
#include <stm32f401re_rcc.h>
#include <stm32f401re_gpio.h>
#include <system_stm32f4xx.h>
#include <Ucglib.h>

#define LED_GPIOx       GPIOA
#define LED_PIN         GPIO_Pin_11

#define BUZZ_GPIOx      GPIOC
#define BUZZ_PIN        GPIO_Pin_9

#define SW1_GPIOx   GPIOB
#define SW1_PIN     GPIO_Pin_5

#define SW2_GPIOx   GPIOB
#define SW2_PIN     GPIO_Pin_3

#define SW3_GPIOx   GPIOA
#define SW3_PIN     GPIO_Pin_4

#define SW4_GPIOx   GPIOB
#define SW4_PIN     GPIO_Pin_0

#define SW5_GPIOx   GPIOB
#define SW5_PIN     GPIO_Pin_4

#define SCR_W 128
#define SCR_H 128
#define PLAY_X0 2
#define PLAY_Y0 6
#define PLAY_W (SCR_W - 4)
#define PLAY_H (SCR_H - 10)

/* ===== ARKANOID CONFIG ===== */

#define BOX_ROWS   3
#define BOX_COLS   3
#define BOX_W      38
#define BOX_H      8
#define BOX_PAD_X  2
#define BOX_PAD_Y  2

#define BAR_W      45
#define BAR_H      5
#define BAR_Y      120

#define BALL_R     3


extern ucg_t ucg;

#endif /* BOARDCONFIG_H_ */
