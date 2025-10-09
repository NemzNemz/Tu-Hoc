#include "my_lcd.h"

void lcd_send_cmd(LCD_PIN *pin, uint8_t cmd){
	//Keo chan RS xuong 
	HAL_GPIO_WritePin(pin->GPIO_R, pin->RS, 0);   // RS = 0  
	
	HAL_GPIO_WritePin(pin->DATA, pin->D0, (cmd >> 0) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D1, (cmd >> 1) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D2, (cmd >> 2) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D3, (cmd >> 3) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D4, (cmd >> 4) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D5, (cmd >> 5) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D6, (cmd >> 6) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D7, (cmd >> 7) & 0x01);
	
	//On dinh xung, DATASHEET HD44780U PAGE 58 - FIGURE 25
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 1);
	//80ns nhung chua hoc timer nen de 1ms
	HAL_Delay(1);
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 0);
	//10ns nhung chua hoc timer nen de 1ms
	HAL_Delay(1);
}

void lcd_clear(LCD_PIN *pin){
   	lcd_send_cmd(pin, 0x01);
}	

void lcd_return_home(LCD_PIN *pin){
	HAL_Delay(1);
	lcd_send_cmd(pin, 0x02);
}

void lcd_entry_mode_set(LCD_PIN *pin){
	HAL_Delay(1);
	lcd_send_cmd(pin, 0x06);
}

void lcd_function_set(LCD_PIN *pin){
	HAL_Delay(1);
	lcd_send_cmd(pin, 0xF8);
}

void lcd_display_off(LCD_PIN *pin){
	HAL_Delay(1);
	//Display on/ off control
	lcd_send_cmd(pin, 0x08);
}

void lcd_cusor_display_shift(LCD_PIN *pin){
//Cusor or display shift
	HAL_Delay(1);
	lcd_send_cmd(pin, 0x14);//Cusor or display shift
}

void lcd_display_on(LCD_PIN *pin) {
  HAL_Delay(1);
  lcd_send_cmd(pin, 0x0C); // Display ON, Cursor OFF, Blink OFF
}

//Tong hop lai 4 buoc init cuoi cho gon
void lcd_settings(LCD_PIN *pin){
	lcd_function_set(pin);
	lcd_display_on(pin);
	lcd_clear(pin);
	lcd_entry_mode_set(pin);
}

void lcd_init(LCD_PIN *pin){
	HAL_GPIO_WritePin(pin->GPIO_R, pin ->RW, 0);
	HAL_Delay(50);
	lcd_send_cmd(pin, 0x38);
	HAL_Delay(5);
	lcd_send_cmd(pin, 0x38);
	HAL_Delay(1);
	lcd_send_cmd(pin, 0x38);
	lcd_settings(pin);
}

void lcd_write(LCD_PIN *pin,uint8_t data){
	HAL_GPIO_WritePin(pin->GPIO_R, pin->RS, 1);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(pin->DATA, pin->D0, (data >> 0) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D1, (data >> 1) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D2, (data >> 2) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D3, (data >> 3) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D4, (data >> 4) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D5, (data >> 5) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D6, (data >> 6) & 0x01);
	HAL_GPIO_WritePin(pin->DATA, pin->D7, (data >> 7) & 0x01);
	
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	//On dinh xung, DATASHEET HD44780U PAGE 58 - FIGURE 25
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 1);
	//80ns nhung chua hoc timer nen de 1ms
	HAL_Delay(1);
	HAL_GPIO_WritePin(pin->GPIO_R, pin->EN, 0);
	//10ns nhung chua hoc timer nen de 1ms
	HAL_Delay(1);
}

void lcd_goto_x_y(LCD_PIN *pin, uint8_t row, uint8_t col){
	uint8_t row0 = 0x00; //line thu 1
	uint8_t row1 = 0x40; //line thu 2 
	uint8_t address = 0x00; //chua hieu cai nay lam
	if(row == 0) address = row0 + col;
	else if(row == 1) address = row1 + col;
	lcd_send_cmd(pin, 0x80 + address);
}