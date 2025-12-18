/*
 * genboxes.c
 *
 *  Created on: Dec 15, 2025
 *      Author: Admin
 */


#include "graphic/genboxes.h"
#define ROWS3 3
#define COLS3 3

uint8_t box_alive[ROWS3][COLS3];
uint8_t box_r[ROWS3][COLS3];
uint8_t box_g[ROWS3][COLS3];
uint8_t box_b[ROWS3][COLS3];

void gen9Box(ucg_int_t start_x, ucg_int_t start_y, ucg_int_t box_w, ucg_int_t box_h, ucg_int_t padding_x, ucg_int_t padding_y) {
	for (int row = 0; row < ROWS3; row++) {
	    for (int col = 0; col < COLS3; col++) {
	    	box_alive[row][col] = 1;
	    	ucg_int_t x = start_x + col * (box_w + padding_x);
	    	ucg_int_t y = start_y + row * (box_h + padding_y);

	    	if (box_alive[row][col] == 1) {
	    		ucg_int_t r = rand() % 256;
	    		ucg_int_t g = rand() % 256;
	    		ucg_int_t b = rand() % 256;
	    		ucg_SetColor(&ucg, 0, r, g, b);
	    	    ucg_DrawBox(&ucg, x, y, box_w, box_h);
	    	} else {
	    		ucg_SetColor(&ucg, 0, 0, 0, 0);
	    		ucg_DrawBox(&ucg, x, y, box_w, box_h);
	    	}
	    }
	}
}
