/*
 * timebase.c
 *
 *  Created on: Dec 6, 2025
 *      Author: Dang Vu
 */

#include "drivers/timebase.h"
#include <timer.h>

static volatile uint32_t g_ms = 0;

uint32_t Millis(void){
	return GetMilSecTick();
}

void Delay_ms(uint32_t d){
	uint32_t t = millis();

	while((uint32_t)(millis() - t) < d) {
		processTimerScheduler();
	}
}

void Timebase_Init(void){
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000);
    TimerInit();
}
