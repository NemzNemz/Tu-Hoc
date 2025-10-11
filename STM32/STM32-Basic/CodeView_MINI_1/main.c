/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//--------------------------------------------DEFINE PIN_OUT----------------------------------------------------//
#define LED_PIN 					GPIO_PIN_1  //PA1
#define	LED_PORT					GPIOA
#define SPEAKER_PIN 			GPIO_PIN_2  //PA2
#define SPEAKER_PORT			GPIOA

//------------HC-SR04-------------------//
#define TRIG_PIN 					GPIO_PIN_9	//PB9
#define	TRIG_PORT					GPIOB
#define ECHO_PIN 					GPIO_PIN_8	//PB8
#define ECHO_PORT					GPIOB

//------------LCD ST7735---------------//
#define LCD_CS_PIN 				GPIO_PIN_0  //PB0
#define	LCD_CS_PORT				GPIOB

#define LCD_RESET_PIN 		GPIO_PIN_10	//PB10
#define	LCD_RESET_PORT		GPIOB

#define LCD_A0_PIN				GPIO_PIN_1	//PB1
#define	LCD_A0_PORT				GPIOB

#define LCD_SDA_PIN 			GPIO_PIN_7	//PA7
#define	LCD_SDA_PORT			GPIOA

#define LCD_SCK_PIN				GPIO_PIN_5	//PA5
#define	LCD_SCK_PORT			GPIOA

//--------------------Lenh LCD ST7735--------------------------//
#define SW_RESET 0x01 //Software reset
#define SLP_OUT  0x11 //Sleep out
#define FRMCTR1  0xB1 //Frame rate control 1
#define FRMCTR2  0xB2 //Frame rate control 2
#define FRMCTR3  0xB3 //Frame rate control 3
#define INVCTR   0xB4 //Display inversion control
#define PWCTR1   0xC0 //Power control 1
#define PWCTR2	 0xC1 //Power control 2
#define PWCTR3   0xC2 //Power control 3
#define PWCTR4   0xC3 //Power control 4
#define PWCTR5   0xC4 //Power control 5
#define VMCTR1   0xC5 //VCOM control
#define GAMCTRP1 0xE0 //Gamma adjustment +
#define GAMCTRN1 0xE1 //Gamma adjustment -
#define MADCTL   0x36 //Memory data access control 
#define INVOFF   0x20 //Display inversion off
#define INTPXF   0x3A //Interface pixel format
#define CASET    0x2A //Column address set
#define RASET    0x2B //Row address set
#define DISPON   0x29 //Display on
#define DISOFF   0x28 //Display off
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

//Struct luu cmd, data va so luong param cua tung lenh cu the
typedef struct{
	uint8_t cmd;
	const uint8_t *data; //Array
	uint8_t parameters;
}LCD_FUNC_CMD;

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
//----------------------------------------------------API --------------------------------------------------------------//
void delay_us(uint16_t time);
void delay_ms(uint16_t time);
void HC_SR04_Init();
void HC_SR04_Trigger();
float HC_SR04_Get_Distance();
void SPI_WRITE(uint8_t data);
void write_cmd(uint8_t cmd); 
void write_data(uint8_t data);
void lcd_set_pos(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void fill_color(uint16_t color);
void lcd_init();
void draw_pixel(uint8_t x, uint8_t y, uint16_t color);
void draw_map();
void draw_blink_point(uint8_t x, uint8_t y);
//-------------------------------------------------E.OFF API-------------------------------------------------------------//
//Tranh compiler toi uu hoa
volatile float test = 0;
volatile uint8_t pos_x =0;


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

//------------------------------------------DELAY FUNC------------------------------------------------//
void delay_us(uint16_t time){
	//B1: bat dau TIMER
	HAL_TIM_Base_Start(&htim2);
	//B2: Tro htim2 toi CNT de no chac chan bang 0
	htim2.Instance -> CNT = 0;
	while(htim2.Instance -> CNT < time){
		//Ko thoat khoi while cho den khi CNT tran
	}
	HAL_TIM_Base_Stop(&htim2);
}

void delay_ms(uint16_t time){
	for(int i = 0; i < time; i++){
		delay_us(1000);
	}
}
//------------------------------------------END OF DELAY FUNC------------------------------------------------//

//------------------------------------------HC_SR05 FUNC-------------------------------------------//
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
//------------------------------------------END OF HC_SR05 FUNC-------------------------------------------//
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
	//Khoi tao HC_SR04
	HC_SR04_Init();
	lcd_init();
	fill_color(0x0000);
	draw_map();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		test = HC_SR04_Get_Distance();
		HAL_Delay(50);
		pos_x = 10 + (test * 5.5);
		draw_blink_point(pos_x, 80);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
// Tr�nh x? l� ng?t TIM2
void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}

// Callback du?c g?i khi c� s? ki?n Input Capture
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        HC_SR04_Get_Distance();
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
