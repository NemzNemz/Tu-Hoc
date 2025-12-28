#include "DS3231.h"

extern I2C_HandleTypeDef hi2c2;

TIMEKEEING_REG time_reg ={
	.sec =		0x00,		//00–59
	.min =		0x01,		//00–59
	.hour = 	0x02,		//
	.day =		0x03,		//1–7
	.date = 	0x04,		//00–31
	.month = 	0x05,		//
	.year = 	0x06,		//00–99
	//Dia chi I2C cua DS3231
	.address = 0x68 << 1
};

//FUNCTIONs
void RTC_INIT(TIME_VAR *time){
	//Khoi tao moi thu bang 0 cai da
	time->sec =		0;
	time->min =		0;
	time->hour =	0;
	time->day =		0;
	time->date=		0;
	time->month =	0;
	time->year =	0;
}

void RTC_Write(TIME_VAR *time){
	uint8_t time_buf[8];
	//Luon luon bat dau tu thanh ghi second
	time_buf[0] = 0x00;
	//Xoa bit CH
	time_buf[1] = DEC_to_BCD(time->sec) & 0x7F;
	time_buf[2] = DEC_to_BCD(time->min) & 0x7F;
	//Dinh dang 24h
	time_buf[3] = DEC_to_BCD(time->hour) & 0x3F;
	time_buf[4] = DEC_to_BCD(time->day) & 0x7F;
	time_buf[5] = DEC_to_BCD(time->date) & 0x3F;
	time_buf[6] = DEC_to_BCD(time->month) & 0x1F;
	time_buf[7] = DEC_to_BCD(time->year);
	//Set pointer de ghi het vao struct thoi gian
	HAL_I2C_Master_Transmit(&hi2c2, time_reg.address, time_buf, 8, 100);
}

void RTC_Read(TIME_VAR *time){
	uint8_t time_buf[7];
	//Dia chi bat dau van la thanh ghi seconds
	uint8_t start_reg = time_reg.sec;
	//Set pointer
	HAL_I2C_Master_Transmit(&hi2c2, time_reg.address, &start_reg, sizeof(start_reg), 100);
	//Gom data ve
	HAL_I2C_Master_Receive(&hi2c2, time_reg.address, time_buf, sizeof(time_buf), 100);
	//Ghi vao tung truong gia tri cua struct
	time->sec = BCD_to_DEC(time_buf[0]);
	time->min = BCD_to_DEC(time_buf[1]);
	time->hour = BCD_to_DEC(time_buf[2]);
	time->day = BCD_to_DEC(time_buf[3]);
	time->date = BCD_to_DEC(time_buf[4]);
	time->month = BCD_to_DEC(time_buf[5]);
	time->year = BCD_to_DEC(time_buf[6]);
}

uint8_t BCD_to_DEC(uint8_t number){
	uint8_t val, high_bit, low_bit;
	//Hang chuc
	high_bit = (number >> 4) *10;
	//Hang dv
	low_bit = (number & 0x0F);
	//Cong vao ra dec
	val = high_bit + low_bit;
	return val;
}

uint8_t DEC_to_BCD(uint8_t number){
	uint8_t hang_chuc, hang_dv, val;
	hang_chuc = number /10;
	hang_dv 	= number %10;
	//OR BIT de ghep no lai
	val = (hang_chuc << 4) | hang_dv;
	return val;
}