/*
 * run_game.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */

#include <stdlib.h>
#include "game/run_game.h"
#include "boardconfig.h"
#include "drivers/timebase.h"
#include "periph/led.h"
#include "periph/button.h"
#include "periph/buzzer.h"
#include "graphic/render.h"
#include "game/entities.h"
#include "game/levels.h"
#include "game/collision.h"
#include <button.h>
#include <stdio.h>

uint8_t key_2_released = 1;
uint8_t key_4_released = 1;

static void game_over_blink(uint8_t times){
	LED_Blink(times, 120, 120);
}

void run_game(void) {
	ark_level L = LEVELS[current_level-1];
	uint8_t box_count = L.rows * L.cols;
	int score = 0;
	int last_score = -1;
	uint8_t boxes_left = box_count;

	Ball ball = {
			.x = SCR_W/2,
	        .y = SCR_H - 20,
	        .vx = L.ball_v,
	        .vy = -L.ball_v,
	        .r = 3
	};

	Bar bar = {
	        .x = (SCR_W-40)/2,
	        .y = 120,
	        .w = 40,
	        .h = 5
	};

	Box boxes[15];
	for(uint8_t i = 0; i < box_count; i++)
	    boxes[i].alive = 1;


	ucg_ClearScreen(&ucg);
	Delay_ms(50);


	while(1){
        if(!Button_GetLogicInputPin(BUTTON_KIT_ID2)) {
        	Buzzer_Beep(40);
        	if (key_2_released) {
        		bar.x -= 10;
        		key_2_released = 0;
        	}
        } else {
        	key_2_released = 1;
    	}

        if(!Button_GetLogicInputPin(BUTTON_KIT_ID4)) {
        	Buzzer_Beep(40);
        	if (key_4_released) {
        		bar.x += 10;
        		key_4_released = 0;
        	}
        } else {
        	key_4_released = 1;
        }

        if(bar.x < 0) bar.x = 0;
        if(bar.x + bar.w > SCR_W)
            bar.x = SCR_W - bar.w;

        clear_ball(&ball);
        ball.x += ball.vx;
        ball.y += ball.vy;
        draw_ball(&ball);

        ball_collide_wall(&ball);
        ball_collide_bar(&ball, &bar);

        int8_t hit = ball_collide_boxes(&ball, boxes, box_count);
        if(hit >= 0) {
        	uint8_t row = hit / BOX_COLS;
        	uint8_t col = hit % BOX_COLS;

        	int16_t x = PLAY_X0 + col * (BOX_W + BOX_PAD_X);
        	int16_t y = PLAY_Y0 + row * (BOX_H + BOX_PAD_Y);

        	ucg_SetColor(&ucg, 0, 0, 0, 0);
        	ucg_DrawBox(&ucg, x, y, BOX_W, BOX_H);

            score += 10;
            boxes_left--;
        }

        draw_bar(&bar);

        if (score != last_score) {
            // draw_score_frame(score);

        	char buff[20];
        	sprintf(buff, "Score: %d", score);

        	ucg_SetColor(&ucg, 0, 255, 255, 255);
        	ucg_SetFont(&ucg, ucg_font_helvR08_tf);
        	ucg_DrawString(&ucg, 2, 12, 0, buff);
        }

        draw_boxes(boxes, box_count);

        if(boxes_left == 0) {
        	ucg_ClearScreen(&ucg);
        	ucg_SetColor(&ucg, 0, 255, 255, 255);
        	ucg_SetFont(&ucg, ucg_font_helvB10_tr);
            ucg_DrawString(&ucg, 20, 64, 0, "LEVEL CLEAR");
            game_over_blink(3);
            Delay_ms(1000);

            return;
        }

        if(ball.y > SCR_H) {
        	ucg_ClearScreen(&ucg);
        	ucg_SetColor(&ucg, 0, 255, 255, 255);
        	ucg_SetFont(&ucg, ucg_font_helvB10_tr);
            ucg_DrawString(&ucg, 20, 64, 0, "GAME OVER");
            game_over_blink(6);
            Delay_ms(1000);

            return;
        }
        processTimerScheduler();
	}

}
