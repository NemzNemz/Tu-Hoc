#ifndef _ST_7735
#define _ST_7735

#include "stm32f1xx_hal.h"
#include "stdint.h"

//--------------------------------------------DEFINE PIN_OUT----------------------------------------------------//
#define LED_PIN 					GPIO_PIN_1  //PA1
#define	LED_PORT					GPIOA
#define SPEAKER_PIN 			GPIO_PIN_2  //PA2
#define SPEAKER_PORT			GPIOA

//------------LCD ST7735---------------//
#define LCD_CS_PIN 				GPIO_PIN_0  //PB0
#define	LCD_CS_PORT				GPIOB

#define LCD_RESET_PIN 		GPIO_PIN_10	//PB10
#define	LCD_RESET_PORT		GPIOB

#define LCD_A0_PIN				GPIO_PIN_1	//PB1
#define	LCD_A0_PORT				GPIOB

#define LCD_SDA_PIN 			GPIO_PIN_7	//PA7
#define	LCD_SDA_PORT			GPIOA

#define LCD_SCK_PIN				GPIO_PIN_5	//PA5
#define	LCD_SCK_PORT			GPIOA

//--------------------Lenh LCD ST7735--------------------------//
#define SW_RESET 0x01 //Software reset
#define SLP_OUT  0x11 //Sleep out
#define FRMCTR1  0xB1 //Frame rate control 1
#define FRMCTR2  0xB2 //Frame rate control 2
#define FRMCTR3  0xB3 //Frame rate control 3
#define INVCTR   0xB4 //Display inversion control
#define PWCTR1   0xC0 //Power control 1
#define PWCTR2	 0xC1 //Power control 2
#define PWCTR3   0xC2 //Power control 3
#define PWCTR4   0xC3 //Power control 4
#define PWCTR5   0xC4 //Power control 5
#define VMCTR1   0xC5 //VCOM control
#define GAMCTRP1 0xE0 //Gamma adjustment +
#define GAMCTRN1 0xE1 //Gamma adjustment -
#define MADCTL   0x36 //Memory data access control 
#define INVOFF   0x20 //Display inversion off
#define INTPXF   0x3A //Interface pixel format
#define CASET    0x2A //Column address set
#define RASET    0x2B //Row address set
#define DISPON   0x29 //Display on
#define DISOFF   0x28 //Display off

//Frame rate control 1-2-3 data
extern const uint8_t FRMCTR1_data[];
extern const uint8_t FRMCTR2_data[];
extern const uint8_t FRMCTR3_data[];

//Display inversion control data
extern const uint8_t INVCTR_data[];

//Power control 1-2-3-4-5 data
extern const uint8_t PWCTR1_data[];
extern const uint8_t PWCTR2_data[];
extern const uint8_t PWCTR3_data[];
extern const uint8_t PWCTR4_data[];
extern const uint8_t PWCTR5_data[];

//VCOM Control Data
extern const uint8_t VMCTR1_data[];

//Gamma adjustment +/- data
extern const uint8_t GAMCTRP1_data[];
extern const uint8_t GAMCTRN1_data[];

//Memory data access control data - RGB
extern const uint8_t MADCTL_data[];

//Interface pixel format data 5-6-5 RGB
extern const uint8_t INTPXF_data[];

//Struct luu cmd, data va so luong param cua tung lenh cu the
typedef struct{
	uint8_t cmd;
	const uint8_t *data; //Array
	uint8_t parameters;
}LCD_FUNC_CMD;
  

//----------------API ---------------------//
void write_cmd(uint8_t cmd); 
void write_data(uint8_t data);
void lcd_set_pos(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void fill_color(uint16_t color);
void lcd_init();
void draw_pixel(uint8_t x, uint8_t y, uint16_t color);
void draw_map();
void draw_blink_point(uint8_t x, uint8_t y);

#endif