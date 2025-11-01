#include "lcd.h"
extern I2C_HandleTypeDef hi2c1;

void lcd_send_cmd(uint8_t cmd){
	//4bit cao, 4 bit thap
	uint8_t high_bit, low_bit;
	uint8_t data_send[4];
	//lay 4 bit cao
	high_bit = cmd & 0xF0;
	//lay 4 bit thap
	low_bit = (cmd << 4) & 0xF0;
	//Truyen cac bit vao mang
	/*
	Bit7   Bit6   Bit5   Bit4   Bit3   Bit2   Bit1   Bit0
	D7     D6     D5     D4     BL     EN     RW     RS
																					(ko xai)
	*/
	data_send[0] = high_bit | LCD_EN | LCD_BACKLIGHT;
	data_send[1] = high_bit | LCD_BACKLIGHT;
	data_send[2] = low_bit  | LCD_EN | LCD_BACKLIGHT;
	data_send[3] = low_bit  | LCD_BACKLIGHT;
	HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS, data_send, 4, 100);
	HAL_Delay(20);
}

void lcd_send_data(uint8_t data){
	//4bit cao, 4 bit thap
	uint8_t high_bit, low_bit;
	uint8_t data_send[4];
	//lay 4 bit cao
	high_bit = data & 0xF0;
	//lay 4 bit thap
	low_bit = (data << 4) & 0xF0;
	//Truyen cac bit vao mang
	/*
	Bit7   Bit6   Bit5   Bit4   Bit3   Bit2   Bit1   Bit0
	D7     D6     D5     D4     BL     EN     RW     RS
																					(ko xai)
	*/
	data_send[0] = high_bit | LCD_EN | LCD_BACKLIGHT| LCD_RS;
	data_send[1] = high_bit | LCD_BACKLIGHT| LCD_RS;
	data_send[2] = low_bit  | LCD_EN | LCD_BACKLIGHT| LCD_RS;
	data_send[3] = low_bit  | LCD_BACKLIGHT| LCD_RS;
	HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS, data_send, 4, 100);
	HAL_Delay(20);
}

void lcd_function_set(){
	HAL_Delay(1);
	lcd_send_cmd(0x28);	//4bit interface
}

void lcd_display_on() {
  HAL_Delay(1);
  lcd_send_cmd(0x0C); // Display ON, Cursor OFF, Blink OFF
}

void lcd_clear(){
   	lcd_send_cmd(0x01);
}

void lcd_entry_mode_set(){
	HAL_Delay(1);
	lcd_send_cmd(0x06);
}

void lcd_settings(){
	lcd_function_set();
	lcd_display_on();
	lcd_clear();
	lcd_entry_mode_set();
}

void lcd_init(){
	HAL_Delay(50);				// cho LCD on dinh 
	lcd_send_cmd(0x33);		// ép ve che do 8-bit
	HAL_Delay(5);
	lcd_send_cmd(0x32);		// chuyen sang 4-bit mode
	HAL_Delay(5);
	lcd_send_cmd(0x28);		// 4-bit, 2 lines, 5x8 font
	HAL_Delay(5);
	lcd_settings();
}

void lcd_send_string(char *str){
	while(*str){
		lcd_send_data(*str++);
	}
}

