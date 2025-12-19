#include "HC_SR04.h"
extern TIM_HandleTypeDef htim2;

//Function
void HC_SR04_Init(){
	//Bat dau timer vi HC_SR04 can do chinh xac cao
	HAL_TIM_Base_Start(&htim2);
}

void HC_SR04_Trigger(){
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
	//Datasheet bao kich len 10us ma luoi qua nen de 1ms
	HAL_Delay(1);
	//Keo chan Trig xuong thap
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
}

float HC_SR04_Get_Distance(){
	uint32_t start_CNT;
	uint32_t end_CNT;
	uint32_t raw_CNT;			//Tick timer t
	uint32_t timeout = 60; 	//60ms
	float distance; 
	//Step 1: 
	HC_SR04_Trigger();
	//Wait cho ECHO len cao
	uint32_t t0 = HAL_GetTick();
	while(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)==0){
		//Neu het 60ms ma ko duoc thi tra ve -1
		if(HAL_GetTick() - t0 >= timeout){
			return -1;
		}
	}
	start_CNT = htim2.Instance -> CNT;
	//Wait cho ECHO xuong thap
	uint32_t t1 = HAL_GetTick();
	while(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)== 1){
		//Neu het 60ms ma ko duoc thi tra ve -1
		if(HAL_GetTick() - t1 >= timeout){
			return -1;
		}
	}
	end_CNT = htim2.Instance -> CNT;
	//Da luu lai gia tri CNT sau khi ECHO duoc kich
	raw_CNT = end_CNT - start_CNT;
	//Chuyen doi 1 lan bang cong thuc eq3: distance = us / 58
	distance = (float)raw_CNT/58;
	//Tra ve khoang cach
	return distance;
}