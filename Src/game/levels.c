/*
 * levels.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "game/levels.h"

const ark_level LEVELS[] = {
    { .ball_v = 2, .rows = 3, .cols = 3 }, // level 1
    { .ball_v = 4, .rows = 3, .cols = 4 }, // level 2
    { .ball_v = 6, .rows = 3, .cols = 5 }  // level 3
};


uint8_t current_level = 1;
