/*
 * entities.h
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */

#ifndef GAME_ENTITIES_H_
#define GAME_ENTITIES_H_

#include <stdint.h>

typedef struct {
    int16_t x, y;
    int8_t  vx, vy;
    uint8_t r;
} Ball;

typedef struct {
    int16_t x, y;
    uint8_t w, h;
} Bar;

typedef struct {
    uint8_t alive;
} Box;

#endif /* GAME_ENTITIES_H_ */
