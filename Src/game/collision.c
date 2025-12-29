/*
 * collision.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */

#include "game/collision.h"
#include "boardconfig.h"

uint8_t ball_collide_wall(Ball *b) {
    if (b->x - b->r <= PLAY_X0) {
        b->x = PLAY_X0 + b->r;
        b->vx = -b->vx;
    }

    if (b->x + b->r >= PLAY_X0 + PLAY_W) {
        b->x = PLAY_X0 + PLAY_W - b->r;
        b->vx = -b->vx;
    }

    if (b->y - b->r <= PLAY_Y0) {
        b->y = PLAY_Y0 + b->r;
        b->vy = -b->vy;
    }

    if (b->y + b->r >= PLAY_Y0 + PLAY_H) {
        return 1;
    }

    return 0;
}

uint8_t ball_collide_bar(Ball *b, Bar *bar) {
    if (b->y + b->r >= bar->y &&
        b->y - b->r <= bar->y + bar->h &&
        b->x >= bar->x &&
        b->x <= bar->x + bar->w)
    {
        b->y  = bar->y - b->r;
        b->vy = -b->vy;
        return 1;
    }
    return 0;
}

uint8_t ball_collide_boxes(Ball *b, Box *boxes, uint8_t count) {
    for(uint8_t i = 0; i < count; i++) {
        if(!boxes[i].alive) continue;

        uint8_t row = i / BOX_COLS;
        uint8_t col = i % BOX_COLS;

        int16_t x = PLAY_X0 + col * (BOX_W + 2);
        int16_t y = PLAY_Y0 + row * (BOX_H + 2);



        if (b->x + b->r > x &&
            b->x - b->r < x + BOX_W &&
            b->y + b->r > y &&
            b->y - b->r < y + BOX_H) {
            boxes[i].alive = 0;
            b->vy = -b->vy;
            return i;
        }
    }
    return -1;
}

