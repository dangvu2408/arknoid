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
#include "graphic/render.h"
#include "game/entities.h"
#include "game/levels.h"
#include "game/collision.h"

static void game_over_blink(uint8_t times){
	LED_Blink(times, 120, 120);
}

void run_game(void) {
	ark_level L = LEVELS[current_level-1];
	uint8_t box_count = L.rows * L.cols;
	uint16_t score = 0;
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
	        .y = SCR_H - 10,
	        .w = 40,
	        .h = 4
	};

	Box boxes[12];
	for(uint8_t i = 0; i < box_count; i++)
	    boxes[i].alive = 1;
	uint32_t last_step = 0;


	while(1){
        uint32_t now = Millis();
        if(now - last_step < 20){
            processTimerScheduler();
            continue;
        }
        last_step = now;

        if(SW2_Click()) bar.x -= 6;
        if(SW4_Click()) bar.x += 6;

        if(bar.x < 0) bar.x = 0;
        if(bar.x + bar.w > SCR_W)
            bar.x = SCR_W - bar.w;

        ball.x += ball.vx;
        ball.y += ball.vy;

        ball_collide_wall(&ball);
        ball_collide_bar(&ball, &bar);

        if(ball_collide_boxes(&ball, boxes, box_count)){
            score += 10;
            boxes_left--;
        }

        clear_playfield();
        draw_score_frame(score);
        draw_boxes(boxes, box_count);
        draw_bar(&bar);
        draw_ball(&ball);

        if(boxes_left == 0){
            ucg_DrawString(&ucg, 30, 64, 0, "LEVEL CLEAR");
            game_over_blink(3);
            Delay_ms(800);
            current_level = (current_level % 2) + 1;
            return;
        }

        if(ball.y > SCR_H){
            ucg_DrawString(&ucg, 30, 64, 0, "GAME OVER");
            game_over_blink(6);
            Delay_ms(800);
            return;
        }
	}

}
