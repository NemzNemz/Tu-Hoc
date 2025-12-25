#ifndef __ST7735_H
#define __ST7735_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

/* ================= FONT ================= */

typedef struct{
    uint8_t height;
    uint8_t width;
    const uint16_t *data;
} FONT;

/* bitmap font d?t trong Flash */
extern const uint16_t Font7x10[];
extern FONT font_7x10;

/* ================= LCD COMMANDS ================= */

#define SWRESET    0x01
#define SLP_OUT    0x11
#define FRMCTR1    0xB1
#define FRMCTR2    0xB2
#define FRMCTR3    0xB3
#define INVCTR     0xB4
#define PWCTR1     0xC0
#define PWCTR2     0xC1
#define PWCTR3     0xC2
#define PWCTR4     0xC3
#define PWCTR5     0xC4
#define VMCTR1     0xC5
#define GMCTRP1    0xE9
#define GMCTRN1    0xE1
#define MADCTL     0x36
#define INTPXF     0x3A
#define DISPON    0x29
#define RAMWR     0x2C

/* ================= INIT DATA ================= */

extern const uint8_t FRC_data1[];
extern const uint8_t FRC_data2[];
extern const uint8_t FRC_data3[];

extern const uint8_t DI_data1[];

extern const uint8_t PWC_data1[];
extern const uint8_t PWC_data2[];
extern const uint8_t PWC_data3[];
extern const uint8_t PWC_data4[];
extern const uint8_t PWC_data5[];

extern const uint8_t VMC_data1[];

extern const uint8_t GM_data1[];
extern const uint8_t GM_data2[];

extern const uint8_t MDA_data1[];
extern const uint8_t INTPXF_data[];

/* ================= STRUCT ================= */

typedef struct{
    uint8_t cmd;
    const uint8_t *data;
    uint8_t lenght;
} LCD_FUNC_CMD;

/* ================= API ================= */

void LCD_Init(void);
void LCD_Write_CMD(uint8_t cmd);
void LCD_Write_Data(uint8_t data);
void LCD_set_pos(uint8_t xs, uint8_t xe, uint8_t ys, uint8_t ye);
void LCD_fill_color(uint16_t color);
void LCD_Draw_Pixel(uint8_t x, uint8_t y, uint16_t color);
void LCD_draw_char(uint8_t x, uint8_t y, char c, FONT font, uint16_t color, uint16_t bg);
void LCD_Draw_String(uint8_t x, uint8_t y, char *str, FONT font, uint16_t color, uint16_t bg);

#endif
