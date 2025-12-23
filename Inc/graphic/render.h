/*
 * render.h
 *
 *  Created on: Dec 15, 2025
 *      Author: Admin
 */

#ifndef GRAPHIC_RENDER_H_
#define GRAPHIC_RENDER_H_

#include "boardconfig.h"
#include "game/entities.h"

void clear_playfield(void);
void draw_score_frame(uint16_t score);
void draw_ball(Ball *b);
void draw_bar(Bar *bar);
void draw_boxes(Box *boxes, uint8_t count);

#endif /* GRAPHIC_RENDER_H_ */
