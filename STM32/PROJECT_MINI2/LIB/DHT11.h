#ifndef	__DHT11_H
#define	__DHT11_H
#include "stm32f1xx_hal.h"
#include "stdint.h"

typedef struct{
	uint8_t int_RH;
	uint8_t dec_RH;
	uint8_t int_T;
	uint8_t dec_T;
	uint8_t checksum;
}DHT11_VAR;

void delay_us(uint16_t time_us);
void delay_ms(uint16_t time_ms);
void DHT_Start(void);
void set_to_input(void);
void set_to_output(void);
uint8_t DHT_Read();
void DHT_Handle();

#endif