/*
 * collision.h
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */

#ifndef GAME_COLLISION_H_
#define GAME_COLLISION_H_

#include "boardconfig.h"
#include "game/entities.h"

uint8_t ball_collide_wall(Ball *b);
uint8_t ball_collide_bar(Ball *b, Bar *bar);
uint8_t ball_collide_boxes(Ball *b, Box *boxes, uint8_t count);

#endif /* GAME_COLLISION_H_ */
