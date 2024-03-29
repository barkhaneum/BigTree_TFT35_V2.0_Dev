#ifndef _ST7920_SIMULATOR_H_
#define _ST7920_SIMULATOR_H_

#include "stdint.h"
#include "../../Configuration.h"

// User-defined colors for 12864 mode from Configuration.h
#ifndef ST7920_BKCOLOR
  #define ST7920_BKCOLOR (BLACK)
#endif

#ifndef ST7920_FNCOLOR
  #define ST7920_FNCOLOR (GREEN)
#endif

#define ST7920_XSTART    (0x80)
#define ST7920_YSTART    (0x80)

#define LCD_XROWS 128.0f
#define LCD_YROWS 64.0f

#ifndef ST7920_FULLSCREEN
 #define PIXEL_XSIZE     (MIN(LCD_WIDTH/128, LCD_HEIGHT/64))
 #define PIXEL_YSIZE     (PIXEL_XSIZE)
#else
  #define PIXEL_XSIZE    (LCD_WIDTH/LCD_XROWS)
  #define PIXEL_YSIZE    (LCD_HEIGHT/LCD_YROWS)
#endif

#define SIMULATOR_XSTART ((LCD_WIDTH - PIXEL_XSIZE*LCD_XROWS) / 2)
#define SIMULATOR_YSTART ((LCD_HEIGHT - PIXEL_YSIZE*LCD_YROWS) / 2)

typedef enum
{
  ST7920_IDLE = 0,
  ST7920_WCMD = 0xF8,
  ST7920_WDATA = 0xFA,
  ST7920_RCMD = 0xFC,
  ST7920_RDATA = 0xFE,
} ST7920_CTRL_STATUS;

typedef struct 
{
  int16_t x, y;
  uint8_t x_cur;
  uint8_t x_record;
}ST7920_PIXEL;


void ST7920_WriteXY(uint8_t xy);
void ST7920_ST7920_ParseWCmd(uint8_t cmd);
void ST7920_DrawPixel(int16_t x, int16_t y, uint16_t color);

void menuST7920(void);
  
#endif
