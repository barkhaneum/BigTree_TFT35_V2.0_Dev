#ifndef _UI_DRAW_H_
#define _UI_DRAW_H_

#include "stdint.h"
#include "variants.h"

#define SPACE_X ((LCD_WIDTH - ICON_WIDTH*4)/4)
#define START_X (SPACE_X/2)
#define SPACE_X_PER_ICON (LCD_WIDTH/4)

#define SPACE_Y ((LCD_HEIGHT - TITLE_END_Y - ICON_HEIGHT*2)/2)

/*about GCODEKEY*/
#define SPACE_GKX   ((LCD_WIDTH - GCODE_KEYW*6)/6)
#define START_GKX   (SPACE_GKX/2)
#define SPACE_GKEY  (LCD_WIDTH/6)
#define SPACE_GKY   ((LCD_HEIGHT - TITLE_END_Y - GCODE_KEYH*4)/4)

//select marlin or bigtree
#define SPACE_SELEX   ((LCD_WIDTH-selecticonw*2)/4)
#define SPACE_SELEY   ((LCD_HEIGHT-selecticonw)/2)
#define text_startx    (LCD_WIDTH/2)

void LCD_DMA_Config(void);

void LOGO_ReadDisplay(void);
void ICON_ReadDisplay(uint16_t sx, uint16_t sy, uint8_t icon);
void ICON_PressedDisplay(uint16_t sx, uint16_t sy, uint8_t icon);

#endif

