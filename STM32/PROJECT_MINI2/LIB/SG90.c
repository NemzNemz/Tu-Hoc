#include "SG90.h"
extern TIM_HandleTypeDef htim3;

//Function
void servo_init(){
	//Gan nhu mac dinh cho moi cam bien su dung TIM lam tieu chuan
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
void servo_change_angle(uint8_t angle){
	//CCRx là 1 thanh ghi dieu khien PWM trong TIM, co 4 thanh CCRx tuong duong 4 kenh CHx
	uint16_t CCRx = 500 + (angle * 2000) / 180;
	//Do chon CH1, nen se tro vao CCR1 va gan no bang voi CCRx de quay chinh xac goc
	htim3.Instance ->CCR1 = CCRx;
}
