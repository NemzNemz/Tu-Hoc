#ifndef _HC_SR04
#define _HC_SR04

#include "stm32f1xx_hal.h"

//------------HC-SR04-------------------//
#define TRIG_PIN 					GPIO_PIN_9	//PB9
#define	TRIG_PORT					GPIOB
#define ECHO_PIN 					GPIO_PIN_8	//PB8
#define ECHO_PORT					GPIOB

//----------------API ---------------------//
void HC_SR04_Init();
void HC_SR04_Trigger();
float HC_SR04_Get_Distance();

#endif 