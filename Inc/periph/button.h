/*
 * button.h
 *
 *  Created on: Dec 18, 2025
 *      Author: Admin
 */

#ifndef PERIPH_BUTTON_H_
#define PERIPH_BUTTON_H_

#include "boardconfig.h"
#include <stdint.h>

void Button_Init(void);

uint8_t SW1_Click(void);
uint8_t SW2_Click(void);
uint8_t SW3_Click(void);
uint8_t SW4_Click(void);
uint8_t SW5_Click(void);

#endif /* PERIPH_BUTTON_H_ */
