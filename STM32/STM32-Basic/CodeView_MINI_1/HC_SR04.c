#include "HC_SR04.h"

extern TIM_HandleTypeDef htim2;

void HC_SR04_Init(){
	//bat dau TIMER
	HAL_TIM_Base_Start(&htim2);
}

void HC_SR04_Trigger(){ 
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 1);
	//Kich chan TRIG len 10us
	HAL_Delay(1);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 0);
}

float HC_SR04_Get_Distance(){
	uint32_t time;
	float distance;
	//Kich xungg
	HC_SR04_Trigger();
	
	uint32_t timeout = 60000;
	//Doi cho den khi ECHO len cao -> bat dau do
	while(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == 0);
	//Luc nay ECHO = 1
	__HAL_TIM_SET_COUNTER(&htim2, 0);
	
	//Doi cho den khi ECHO xuong thao -> Get time
	while(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == 1);
		//Lay time, 1cnt = 1us
	time = __HAL_TIM_GET_COUNTER(&htim2);
	distance = (float)time * 0.034 / 2;
	if(distance < 3.0) distance = 3.0;
	else if (distance > 20.0) distance = 20.0;
	return distance;
}
