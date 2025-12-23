/*
 * levels.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "game/levels.h"

const ark_level LEVELS[] = {
    { .ball_v = 1, .rows = 3, .cols = 3 }, // level 1
    { .ball_v = 2, .rows = 3, .cols = 4 }  // level 2
};


uint8_t current_level = 1;
