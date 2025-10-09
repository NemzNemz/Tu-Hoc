#ifndef MY_LCD_H
#define MY_LCD_H
#include "stdint.h"
#include "stm32f1xx_hal.h"

//D0 - D7: DATA
//RS, RW, E: GPIO_R

//Struct LCD_PIN
typedef struct{
	GPIO_TypeDef *DATA;
	GPIO_TypeDef *GPIO_R;
	uint16_t D0;
	uint16_t D1;
	uint16_t D2;
	uint16_t D3;
     
	uint16_t D4;
	uint16_t D5;
	uint16_t D6;
	uint16_t D7;
	uint16_t RS;
	uint16_t RW;
	uint16_t EN;
}LCD_PIN;

void lcd_init(LCD_PIN *pin);
void lcd_clear(LCD_PIN *pin);
void lcd_write(LCD_PIN *pin,uint8_t data);
void lcd_return_home(LCD_PIN *pin);
void lcd_function_set(LCD_PIN *pin);
void lcd_entry_mode_set(LCD_PIN *pin);
void lcd_display_off(LCD_PIN *pin);
void lcd_display_on(LCD_PIN *pin);
void lcd_cusor_display_shift(LCD_PIN *pin);
void lcd_settings(LCD_PIN *pin);
void lcd_goto_x_y(LCD_PIN *pin, uint8_t row, uint8_t col);
void lcd_send_cmd(LCD_PIN *pin, uint8_t cmd);

#endif