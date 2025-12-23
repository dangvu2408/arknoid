/*
 * menu_ui.c
 *
 *  Created on: Dec 23, 2025
 *      Author: Admin
 */


#include "game/menu_ui.h"
#include "boardconfig.h"
#include "graphic/render.h"
#include "periph/buzzer.h"
#include "periph/button.h"
#include "game/levels.h"
#include <button.h>
#include <stdio.h>


void UI_ShowMenu(void) {
    ucg_ClearScreen(&ucg);

    ucg_SetFont(&ucg, ucg_font_helvR08_tf);
    ucg_SetColor(&ucg, 0, 255, 255, 255);

    ucg_DrawString(&ucg, 20, 32, 0, "ARKANOID");
    ucg_DrawString(&ucg, 10, 48, 0, " LEVEL:");
    ucg_DrawString(&ucg, 10, 64, 0, "START");

    char lv[4];
    uint8_t cursor = 0;

    while (1) {
        processTimerScheduler();

        if (cursor == 0 && Button_GetLogicInputPin(BUTTON_KIT_ID4) == 0) {
            Buzzer_Beep(50);
            current_level++;
            if (current_level > 3) current_level = 1;

            snprintf(lv, sizeof(lv), "%d", current_level);
            ucg_SetColor(&ucg, 0, 0, 0, 0);
            ucg_DrawBox(&ucg, 70, 40, 10, 10);
            ucg_SetColor(&ucg, 0, 255, 255, 255);
            ucg_DrawString(&ucg, 70, 48, 0, lv);
        }

        if (Button_GetLogicInputPin(BUTTON_KIT_ID2) == 0) {
            Buzzer_Beep(50);
            cursor ^= 1;

            ucg_SetColor(&ucg, 0, 0, 0, 0);
            ucg_DrawBox(&ucg, 0, 40, 10, 30);

            ucg_SetColor(&ucg, 0, 255, 255, 255);
            if (cursor == 0)
                ucg_DrawString(&ucg, 0, 48, 0, ">");
            else
                ucg_DrawString(&ucg, 0, 64, 0, ">");
        }

        if (cursor == 1 && Button_GetLogicInputPin(BUTTON_KIT_ID4) == 0) {
            Buzzer_Beep(100);
            return;
        }
    }
}
