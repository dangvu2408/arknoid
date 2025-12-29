#include "game/menu_ui.h"
#include "boardconfig.h"
#include "graphic/render.h"
#include "periph/buzzer.h"
#include "periph/button.h"
#include "game/levels.h"
#include <button.h>
#include <stdio.h>

#define B1  BUTTON_KIT_ID1  // Up
#define B2  BUTTON_KIT_ID2  // Left
#define B3  BUTTON_KIT_ID3  // Enter
#define B4  BUTTON_KIT_ID4  // Right
#define B5  BUTTON_KIT_ID5  // Down

static uint8_t cursor = 0;     // 0: Title  | 1: Level | 2: Start
static uint8_t level_edit = 0; // 0: normal | 1: editing level

static uint8_t up_rel = 1;
static uint8_t down_rel = 1;
static uint8_t left_rel = 1;
static uint8_t right_rel = 1;
static uint8_t enter_rel = 1;

static void draw_item(int x0, int y0, int x1, int y1, int x2, int y2, uint8_t active) {
    if(active) {
    	ucg_SetColor(&ucg, 0, 255, 255, 255);
    	ucg_DrawTriangle(&ucg, x0, y0, x1, y1, x2, y2);
    } else {
    	ucg_SetColor(&ucg, 0, 0, 0, 0);
    	ucg_DrawTriangle(&ucg, x0, y0, x1, y1, x2, y2);
    	ucg_SetColor(&ucg, 0, 255, 255, 255);
    }
}

void UI_ShowMenu(void) {

    ucg_ClearScreen(&ucg);
    ucg_SetFont(&ucg, ucg_font_helvB08_tr);
    ucg_SetColor(&ucg, 0, 255, 255, 255);
    ucg_DrawString(&ucg, 15, 20, 0, "ARKANOID");
    ucg_DrawString(&ucg, 15, 44, 0, "LEVEL");
    ucg_DrawString(&ucg, 15, 68, 0, "START");

    uint8_t need_redraw = 1;

    while(1){
        processTimerScheduler();

        uint8_t up    = (Button_GetLogicInputPin(B1) == 0);
        uint8_t left  = (Button_GetLogicInputPin(B2) == 0);
        uint8_t enter = (Button_GetLogicInputPin(B3) == 0);
        uint8_t right = (Button_GetLogicInputPin(B4) == 0);
        uint8_t down  = (Button_GetLogicInputPin(B5) == 0);

        if(!level_edit) {
            if(up && up_rel && cursor > 0) {
                cursor--;
                Buzzer_Beep(40);
                need_redraw = 1;
                up_rel = 0;
            }
            if(down && down_rel && cursor < 2) {
                cursor++;
                Buzzer_Beep(40);
                need_redraw = 1;
                down_rel = 0;
            }
        }

        if(enter && enter_rel) {
            Buzzer_Beep(80);
            if(cursor == 1 && !level_edit) {
                level_edit = 1;
            }
            else if(cursor == 1 && level_edit) {
                level_edit = 0;
                cursor = 2;
            }
            else if(cursor == 2) {
            	ucg_ClearScreen(&ucg);
                return;
            }
            need_redraw = 1;
            enter_rel = 0;
        }

        if(level_edit) {
            if(right && right_rel && current_level < 3) {
            	current_level++;
            	Buzzer_Beep(40);
            	need_redraw = 1;
            	right_rel = 0;
            }
            if(left && left_rel && current_level > 1) {
            	current_level--;
                Buzzer_Beep(40);
                need_redraw = 1;
                left_rel = 0;
            }
        }

        if(!up)    up_rel    = 1;
        if(!down)  down_rel  = 1;
        if(!left)  left_rel  = 1;
        if(!right) right_rel = 1;
        if(!enter) enter_rel = 1;

        if(need_redraw) {
            need_redraw = 0;

            ucg_SetColor(&ucg, 0, 0, 0, 0);
            ucg_DrawBox(&ucg, 60, 32, 50, 20);

            draw_item(0, 12, 0, 20, 10, 16, cursor == 0);
            draw_item(0, 36, 0, 44, 10, 40, cursor == 1);
            draw_item(0, 60, 0, 68, 10, 64, cursor == 2);
            int base_x = 60;
            int base_y = 36;

            for(uint8_t i = 0; i < current_level; i++){
                int x = base_x + i * 8;
                ucg_SetColor(&ucg, 0, 255, 255, 255);
                ucg_DrawBox(&ucg, x, base_y, 6, 8);
//                if(i < current_level) ucg_SetColor(&ucg, 0, 255, 255, 255);
//                else ucg_SetColor(&ucg, 0, 0, 0, 0);
//                ucg_DrawBox(&ucg, base_x + i * 10, base_y, 6, 8);
            }

        }

    }
}
