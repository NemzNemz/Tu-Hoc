#include "ST_7735.h"

extern SPI_HandleTypeDef hspi1;

//---------------------------------------------------- DATA ST7735 --------------------------------------------------------------//
//Frame rate control 1-2-3 data
const uint8_t FRMCTR1_data[] = {0x01, 0x2C, 0x2D};
const uint8_t FRMCTR2_data[] = {0x01, 0x2C, 0x2D};
const uint8_t FRMCTR3_data[] = {0x01, 0x2C, 0x2D, 0x01, 0x2C, 0x2D};

//Display inversion control data
const uint8_t INVCTR_data[] = {0x07};

//Power control 1-2-3-4-5 data
const uint8_t PWCTR1_data[] = {0xA2, 0x02, 0x84};
const uint8_t PWCTR2_data[] = {0xC5};
const uint8_t PWCTR3_data[] = {0x0A, 0x00};
const uint8_t PWCTR4_data[] = {0x8A, 0x2A};
const uint8_t PWCTR5_data[] = {0x8A, 0xEE};

//VCOM Control Data
const uint8_t VMCTR1_data[] = {0x0E};

//Gamma adjustment +/- data
const uint8_t GAMCTRP1_data[] = {0x02, 0x1C, 0x07, 0x12, 0x37, 0x32, 0x29, 0x2D, 0x29, 0x25, 0x2B, 0x39, 0x00, 0x01, 0x03, 0x10};
const uint8_t GAMCTRN1_data[] = {0x03, 0x1D, 0x07, 0x06, 0x2E, 0x2C, 0x29, 0x2D, 0x2E, 0x2E, 0x37, 0x3F, 0x00, 0x00, 0x02, 0x10};

//Memory data access control data - RGB
const uint8_t MADCTL_data[] = {0x00};

//Interface pixel format data 5-6-5 RGB
const uint8_t INTPXF_data[] = {0x05};


//Struct ST7735, bao gom CMD, DATA va so luong tham so
LCD_FUNC_CMD lcd_func[] = {
	{FRMCTR1, FRMCTR1_data, sizeof(FRMCTR1_data)},      //Lenh set frame1    [0]
	{FRMCTR2, FRMCTR2_data, sizeof(FRMCTR2_data)},      //Lenh set frame2    [1]
	{FRMCTR3, FRMCTR3_data, sizeof(FRMCTR3_data)},      //Lenh set frame3    [2]
	{INVCTR, INVCTR_data, sizeof(INVCTR_data)},         //Lenh inversion     [3]
	{PWCTR1, PWCTR1_data, sizeof(PWCTR1_data)},         //Lenh power1        [4]
	{PWCTR2, PWCTR2_data, sizeof(PWCTR2_data)},		      //Lenh power2        [5]
	{PWCTR3, PWCTR3_data, sizeof(PWCTR3_data)},         //Lenh power3        [6]
	{PWCTR4, PWCTR4_data, sizeof(PWCTR4_data)},         //Lenh power4        [7]
	{PWCTR5, PWCTR5_data, sizeof(PWCTR5_data)},         //Lenh power5        [8] 
	{VMCTR1, VMCTR1_data, sizeof(VMCTR1_data)},         //Lenh VCOM          [9]
	{GAMCTRP1, GAMCTRP1_data, sizeof(GAMCTRP1_data)},   //Lenh Gamma+        [10]
	{GAMCTRN1, GAMCTRN1_data, sizeof(GAMCTRN1_data)},   //Lenh Gamma-     	 [11]
	{MADCTL, MADCTL_data, sizeof(MADCTL_data)},         //Lenh Memory Access [12]
	{INTPXF, INTPXF_data, sizeof(INTPXF_data)},         //Lenh RGB           [13]
};

//------------------------------------------LCD FUNC-------------------------------------------//
void SPI_WRITE(uint8_t data){
	//Keo CS xuong 0
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
	//Truyen data SPI
	HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
	//Keo CS len 1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
}

void write_cmd(uint8_t cmd){ 
	//Keo CS xuong 0 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); 
	//Keo A0 ST7735 (PB1) xuong 0 de gui CMD 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0); 
	HAL_SPI_Transmit(&hspi1, &cmd, 1, 1000); 
	//Keo CS len 1 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1); 
}

void write_data(uint8_t data){ 
	//Keo CS xuong 0 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); 
	//Keo A0 ST7735 (PB1) len 1 de gui DATA 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1); 
	HAL_SPI_Transmit(&hspi1, &data, 1, 1000); 
	//Keo CS len 1 
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1); 
}

void lcd_set_pos(uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye){
	//Lenh set column
	write_cmd(0x2A);
	//Chay tu X_Start toi X_End
	write_data(0x00); //MSB
	write_data(xs);   //LSB
	write_data(0x00);
	write_data(xe);
	
	//Lenh set row
	write_cmd(0x2B);
	//Chay tu Y_Start toi Y_End
	write_data(0x00); //MSB
	write_data(ys);   //LSB
	write_data(0x00);
	write_data(ye);
}

void fill_color(uint16_t color){
	//Memory Write
	write_cmd(0x2C);
	for(int i = 0; i < 128 * 160; i++){
		write_data(color >> 8);
		write_data(color & 0xFF);
	}
}

void lcd_init(){
	//Reset timing: tRESW >5us
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	HAL_Delay(10);
	//Reset timing: tREST <120ms
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
	HAL_Delay(10);
	//Software Reset
	write_cmd(0x01);
	//Delay SWRST
	HAL_Delay(120);
	//Sleep Out - Boost on
	write_cmd(0x11);
	//Delay SLEEP OUT
	HAL_Delay(120);
	
	//Frame Rate Control 1
	write_cmd(lcd_func[0].cmd);
	for(uint8_t i =0; i < lcd_func[0].parameters; i ++){
		write_data(lcd_func[0].data[i]);
	}
	//Frame Rate Control 2
	write_cmd(lcd_func[1].cmd);
	for(uint8_t i = 0; i < lcd_func[1].parameters; i++){
		write_data(lcd_func[1].data[i]);
	}
	//Frame Rate Control 3
	write_cmd(lcd_func[2].cmd);
	for(uint8_t i = 0; i < lcd_func[2].parameters; i++){
		write_data(lcd_func[2].data[i]);
	}
	//Display Inversion control
	write_cmd(lcd_func[3].cmd);
	for(uint8_t i = 0; i < lcd_func[3].parameters; i++){
		write_data(lcd_func[3].data[i]);
	}
	//Power Control 1
	write_cmd(lcd_func[4].cmd);
	for(uint8_t i = 0; i < lcd_func[4].parameters; i++){
		write_data(lcd_func[4].data[i]);
	}
	//Power Control 2
	write_cmd(lcd_func[5].cmd);
	for(uint8_t i = 0; i < lcd_func[5].parameters; i++){
		write_data(lcd_func[5].data[i]);
	}
	//Power Control 3
	write_cmd(lcd_func[6].cmd);
	for(uint8_t i = 0; i < lcd_func[6].parameters; i++){
		write_data(lcd_func[6].data[i]);
	}
	//Power Control 4
	write_cmd(lcd_func[7].cmd);
	for(uint8_t i = 0; i < lcd_func[7].parameters; i++){
		write_data(lcd_func[7].data[i]);
	}
	//Power Control 5
	write_cmd(lcd_func[8].cmd);
	for(uint8_t i = 0; i < lcd_func[8].parameters; i++){
		write_data(lcd_func[8].data[i]);
	}
	//VCOM Control 1
	write_cmd(lcd_func[9].cmd);
	for(uint8_t i = 0; i < lcd_func[9].parameters; i++){
		write_data(lcd_func[9].data[i]);
	};
	//Gamma adjustment +
	write_cmd(lcd_func[10].cmd);
	for(uint8_t i = 0; i < lcd_func[10].parameters; i++){
		write_data(lcd_func[10].data[i]);
	}
	//Gamma adjustment -
	write_cmd(lcd_func[11].cmd);
	for(uint8_t i = 0; i < lcd_func[11].parameters; i++){
		write_data(lcd_func[11].data[i]);
	}
	//Memory Data Access Control
	write_cmd(lcd_func[12].cmd);
	for(uint8_t i = 0; i < lcd_func[12].parameters; i++){
		write_data(lcd_func[12].data[i]);
	}
	//Interface pixel format
	write_cmd(lcd_func[13].cmd);
	for(uint8_t i = 0; i < lcd_func[13].parameters; i++){
		write_data(lcd_func[13].data[i]);
	}
	
	//Display Inversion off
	write_cmd(0x20);
	//Set vi tri va do phan giai cho LCD
	lcd_set_pos(0, 0, 128, 160);
	//Display On
	write_cmd(0x29);
	HAL_Delay(120);
}

void draw_pixel(uint8_t x, uint8_t y, uint16_t color){
	//Neu nhu chieu ngang lon hon 128 va chieu dai lon hon 160, thoat
	if(x >= 128 || y >= 160){
		return ;
	}
	lcd_set_pos(x, y, x+1, y+1);
	//Memory Write
	write_cmd(0x2C);
	//Ve 1 pixel mau
  //write_data(color & 0xFF);
	write_data(color >> 8);
	write_data(color & 0xFF);
}

void draw_map(){
	//Vien xanh la
	//Ve vien tren va duoi
	for(uint8_t i =0; i < 128; i++){
		draw_pixel(i, 0, 0x8FC0);
		draw_pixel(i, 159, 0x8FC0);
	}
	//Ve vien trai va phai
	for(uint8_t x =0; x < 160; x++){
		draw_pixel(0, x, 0x8FC0);
		draw_pixel(127, x, 0x8FC0);
	}
	
	for(uint8_t x = 1; x < 127; x++ ){
		for(uint8_t y = 1; y < 159; y++){
			//Phan chia 1 nua man hinh, ben mau nay ben mau kia
			//Ben nay mau den
			if(x < 64){
				draw_pixel(x, y, 0x0000);
			}
			//Ben kia mau trang
			else{
				draw_pixel(x, y, 0xFFFF);
			}
		}
	}
}

void draw_blink_point(uint8_t x, uint8_t y){
	static uint8_t last_pos_x = 2;
	static uint8_t last_pos_y = 80;
	//Neu nhu hien thi o goc man hinh, thoat ham
	if(x == 0 || x == 127 || y ==0 || y == 159) return;
	
	uint16_t old_color;
	//Neu nhu diem anh nam ben trai
	if (last_pos_x < 64) old_color = 0x0000;
	//Neu nhu diem anh nam ben phai
	else old_color = 0xFFFF;
	
	//Ve pixel dai dien cho vat the
	for(int dx = -2; dx <= 2; dx++){
		for(int dy = -2; dy <= 2; dy++){
			draw_pixel(last_pos_x+dx, last_pos_y+dy, old_color);
		}
	}
	
	for(int dx = -2; dx <= 2; dx++){
		for(int dy = -2; dy <= 2; dy++){
			draw_pixel(x+dx, y+dy, 0xF800);
		}
	}
	if(x < 64){
		HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SPEAKER_PORT, SPEAKER_PIN, GPIO_PIN_SET);
	} 
	else{
		HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SPEAKER_PORT, SPEAKER_PIN, GPIO_PIN_RESET);
	}
	last_pos_x = x;
	last_pos_y = y;
}
//------------------------------------------END OF LCD FUNC-------------------------------------------//