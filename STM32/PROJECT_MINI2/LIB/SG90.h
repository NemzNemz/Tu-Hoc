#ifndef __SG90_H
#define __SG90_H
#include "stm32f1xx_hal.h"
#include "stdint.h"

//API
void servo_init();
void servo_change_angle(uint8_t angle);

#endif