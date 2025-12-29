#ifndef __BOOTLOADER_H
#define __BOOTLOADER_H

#include "stm32f1xx_hal.h"

void bootloader_lock();
void bootloader_unlock();
void bootloader_erase(uint32_t address);
void bootloader_write(uint32_t address, uint8_t *mData, uint16_t lenght);
void bootloader_read(uint32_t address, uint8_t *mData, uint16_t lenght);

#endif