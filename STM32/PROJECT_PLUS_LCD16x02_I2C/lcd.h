#ifndef _LCD_H
#define _LCD_H

#include "stm32f1xx_hal.h"
#include "stdint.h"
//-------------DEFINE PIN_OUT---------------//
#define I2C_ADDRESS			(0x27 << 1)	
#define LCD_BACKLIGHT		0x08				//P3
#define LCD_RS					0x01				//P0 (P1 ko su dung!)
#define LCD_EN					0x04				//P2

//----------------API ---------------------//
void lcd_send_cmd(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_function_set();
void lcd_display_on();
void lcd_init();
void lcd_clear();
void lcd_entry_mode_set();
void lcd_send_string(char *str);

#endif