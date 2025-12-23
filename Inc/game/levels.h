/*
 * levels.h
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */

#ifndef GAME_LEVELS_H_
#define GAME_LEVELS_H_

#include <stdint.h>

typedef struct {
    int8_t ball_v;
    uint8_t rows;
    uint8_t cols;
} ark_level;

extern const ark_level LEVELS[];
extern uint8_t current_level;
#endif /* GAME_LEVELS_H_ */
