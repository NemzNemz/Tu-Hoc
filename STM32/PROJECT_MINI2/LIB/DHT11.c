#include "DHT11.h"
DHT11_VAR dht = {
	.int_RH = 0,
	.dec_RH = 0,
	.int_T = 0,
	.dec_T = 0,
	.checksum =0
};
extern TIM_HandleTypeDef htim1;

//FUNCTIONS
void delay_us(uint16_t time_us){
	//Bat dau timer
	HAL_TIM_Base_Start(&htim1);
	//Keo CNT xuong 0 de no dem lai tu dau
	htim1.Instance ->CNT = 0;
	//Wait den khi dat moc time
	while(htim1.Instance ->CNT < time_us){
		//Nothing hereeeeee .... 
	}
	HAL_TIM_Base_Stop(&htim1);
}

void delay_ms(uint16_t time_ms){
	for(uint16_t i = 0; i < time_ms; i++){
		//1ms
		delay_us(1000);
	}
}

void set_to_input(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void set_to_output(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void DHT_Start(){
	//Set thanh output truoc vi luc nay can xuat tin hieu tu MCU
	set_to_output();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
	//Keo Data xuong it nhat 18ms
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);	
	delay_ms(20);
	//MCU keo len va cho 20-40us, xong sau do tra ve input vi tu day la data cua DHT11
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
	set_to_input();
	//DHT xung cao con lai tu Fig3
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);	
	//DHT set out response signal -> keep 80 us
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0);
	//DHT pull up -> Bat dau truyen
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1	);
}

uint8_t DHT_Read(){
	//Bien luu gia tri tra ve
	uint8_t response = 0;
	//Vong lap duyet 8 bit data
	for(uint8_t i = 0; i < 8; i++){
		//Khi chan data keo ve 0 va cho 50us (Both data 1 and 0)
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0);
		delay_us(50);
		//Neu nhu data la 1
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1){
			response = (response << 1) | (1 << 0);
		}
		//neu nhu data la 0
		else{
			//Thuc te hoan toan co the res << 1 ma ko can bitwise
		 response = (response << 1) & ~(1 << 0);
		}
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);
	}
	return response;
}

void DHT_Handle(){
	DHT_Start();
	//Doc 5 byte (8bit) 1 luot
	dht.int_RH = DHT_Read();
	dht.dec_RH = DHT_Read();
	dht.int_T = DHT_Read();
	dht.dec_T = DHT_Read();
	dht.checksum = DHT_Read();
}