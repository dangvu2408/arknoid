/*
 * render.c
 *
 *  Created on: Dec 15, 2025
 *      Author: Admin
 */


#include "graphic/render.h"
#include "boardconfig.h"
#include <stdio.h>

void clear_playfield(void){
	ucg_SetColor(&ucg, 0, 0,0,0);
	ucg_DrawBox(&ucg, 1, 1, SCR_W-3, SCR_H-3);
	ucg_SetColor(&ucg, 0, 255, 255, 255);
}

void draw_score_frame(uint16_t score){
	ucg_SetColor(&ucg, 0, 255, 255, 255);
	ucg_DrawFrame(&ucg, 0, 0, SCR_W-1, SCR_H-1);
	char buf[10];
	snprintf(buf,sizeof(buf),"%u",score);
	ucg_DrawString(&ucg, 2, 10, 0, buf);
}

void draw_ball(Ball *b){
    ucg_SetColor(&ucg, 0, 255, 255, 255);
    ucg_DrawDisc(&ucg, b->x, b->y, b->r, UCG_DRAW_ALL);
}

void draw_bar(Bar *bar){
    ucg_SetColor(&ucg, 0, 255, 255, 255);
    ucg_DrawBox(&ucg, bar->x, bar->y, bar->w, bar->h);
}

void draw_boxes(Box *boxes, uint8_t count){
    for(uint8_t i = 0; i < count; i++){
        if(!boxes[i].alive) continue;

        uint8_t row = i / BOX_COLS;
        uint8_t col = i % BOX_COLS;

        int16_t x = PLAY_X0 + col * (BOX_W + BOX_PAD_X);
        int16_t y = PLAY_Y0 + row * (BOX_H + BOX_PAD_Y);

        ucg_DrawBox(&ucg, x, y, BOX_W, BOX_H);
    }
}
