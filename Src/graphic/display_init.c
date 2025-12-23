/*
 * display_init.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "graphic/display_init.h"

ucg_t ucg;

void Display_Init(void){
  Ucglib4WireSWSPI_begin(&ucg, 0);
  ucg_SetFont(&ucg, ucg_font_helvR12_tf);
  ucg_ClearScreen(&ucg);
  ucg_SetFont(&ucg, ucg_font_helvR08_tf);
  ucg_SetColor(&ucg, 0, 255, 255, 255);
  ucg_SetColor(&ucg, 1, 0, 0, 0);
  ucg_SetRotate180(&ucg);
}
