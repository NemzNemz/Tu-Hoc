#include "BOOLOADER.h"

void bootloader_erase(uint32_t address){
	FLASH_EraseInitTypeDef pErase;
	pErase.NbPages = 1;
	pErase.PageAddress = address;
	pErase.TypeErase = FLASH_TYPEERASE_PAGES;
	uint32_t Page_err;
	HAL_FLASHEx_Erase(&pErase, &Page_err);
}

void bootloader_write(uint32_t address, uint8_t *mData, uint16_t lenght){
	uint8_t status = 0x00;
	if(lenght %2 == 1){
		status = 1;
		//Giam lenght ve tu so le thanh so chan
		lenght--;
	}
	//Ghi 2 byte 1, ghi so chan lan 
	for(uint32_t i = 0; i < lenght; i+=2){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address+i, 
											*(mData + i) | (uint16_t)(*(mData + i + 1) << 8));
	}
	//Ghi bit cuoi cung vao mang neu do dai la so le
	if(status == 1) {
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + lenght, 
											*(mData + lenght) | (uint16_t)((0xFF) << 8));
	}
}

void bootloader_lock(){
	HAL_FLASH_Lock();
}

void bootloader_unlock(){
	HAL_FLASH_Unlock();
}

void bootloader_read(uint32_t address, uint8_t *mData, uint16_t lenght){
	for(uint32_t i = 0; i < lenght; i +=2){
		//Giai tham chieu de lay du lieu tu dia chi ra ma xai
		uint16_t haft_word = *(volatile uint16_t*)(address + i);
		//Bit thap
		mData[i] = (uint8_t)(haft_word & 0xFF);
		//Bit cao
		mData[i+1] = (uint8_t)((haft_word >> 8) & 0xFF);
	}
}