#ifndef __DS3231_H
#define __DS3231_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

//STRUCT THANH GHI DS3231
typedef struct{
	uint8_t	sec;
	uint8_t	min;
	uint8_t hour;
	uint8_t	day;
	uint8_t	date;
	uint8_t	month;
	uint8_t	year;
	uint8_t address;
}TIMEKEEING_REG;
extern TIMEKEEING_REG time_reg;


//STRUCT LUU TRU GIA TRI THOI GIAN
typedef struct {
	uint8_t	sec;
	uint8_t	min;
	uint8_t hour;
	uint8_t	day;
	uint8_t	date;
	uint8_t	month;
	uint8_t	year;
}TIME_VAR;

//APIs
void RTC_INIT(TIME_VAR *time);
void RTC_Write(TIME_VAR *time);
void RTC_Read(TIME_VAR *time);
uint8_t BCD_to_DEC(uint8_t number);
uint8_t DEC_to_BCD(uint8_t number);

#endif