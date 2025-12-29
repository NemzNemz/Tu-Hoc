#include "BOOTLOADER.h"

void bootloader_lock(){
	//Khoa bootloader
	HAL_FLASH_Lock();
}

void bootloader_unlock(){
	//Mo khoa bootloader
	HAL_FLASH_Unlock();
}

void bootloader_erase(uint32_t address){
	//Dinh nghia FLASH_Erase
	FLASH_EraseInitTypeDef f_Erase;
	//Dinh kieu xoa Pages erase only
	f_Erase.TypeErase = FLASH_TYPEERASE_PAGES;
	//Chon page address
	f_Erase.PageAddress = address;
	//Chon so page xoa trong 1 luot
	f_Erase.NbPages = 1;
	uint32_t Page_err;
	//Thuc hien xoa page
	HAL_FLASHEx_Erase(&f_Erase, &Page_err);
}

void bootloader_write(uint32_t address, uint8_t *mData, uint16_t lenght){
	//Flag check xem co byte du hay ko
	uint8_t flag = 0;
	//Neu co du
	if(lenght %2 == 1){
		flag = 1;
		//Cat byte le ra xu ly rieng
		lenght --;
	}
	
	//Ghi 2 byte 1 lan, ghi chan
	for(uint32_t i =0; i < lenght; i+=2){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + i, 
														//Byte cao									//Byte thap
											(uint16_t)(*(mData + i + 1) << 8) | *(mData + i));
	
	}
	//Xu ly byte le ban nay
	if(flag == 1){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, 
											//Byte cao	//Byte thap
											0xFF << 8 | *(mData + lenght));
	}
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