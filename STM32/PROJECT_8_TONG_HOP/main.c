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
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
uint16_t pwm_val = 0;
uint16_t old_pwm_val = 0;
uint16_t old_int_temp =0;
uint16_t old_int_hum =0;
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
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//************* Cac ham delay tu tao *****************//
void delay_us(uint16_t time_us);
void delay_ms(uint16_t time_ms);

void delay_us(uint16_t time_us){
	//B1: Bat dau timer
	HAL_TIM_Base_Start(&htim1);
	//B2: Set thanh CNT = 0 
	htim1.Instance ->CNT = 0;
	//B3: Chung nao CNT chua bang tham so time thi con ket trong vong lap
	while(htim1.Instance -> CNT < time_us){
	}
}

void delay_ms(uint16_t time_ms){
	//1 vong lap tao lao khac
	uint16_t i =0;
	for(int i =0; i < time_ms; i++){
		delay_us(1000);
	}
}
//************* Cac ham delay tu tao *****************//

//************* Danh cho doc ADC tu bien tro *****************//
uint16_t adc_val = 0;
float adc_volt = 0;
void ADC_START();
float ADC_VOLT(float *adc_volt, uint16_t adc_val);

void ADC_START(){
	//B1: Kich ADC
	HAL_ADC_Start(&hadc1);
	//B2: Doi ADC chuyen doi xong
	HAL_ADC_PollForConversion(&hadc1, 1000);
	//B3: Luu ADC
	adc_val = HAL_ADC_GetValue(&hadc1);
	//B4: Tat ADC
	HAL_ADC_Stop(&hadc1);
}

float ADC_VOLT(float *adc_volt, uint16_t adc_val){
	return *adc_volt = (adc_val / 4095.0) * 3.3;
}
//************* Danh cho doc ADC tu bien tro *****************//	

//************* Danh cho doc DHT11 *****************//
uint8_t int_temp = 0;
uint8_t dec_temp = 0;
uint8_t int_hum = 0;
uint8_t dec_hum = 0;
uint8_t check_sum = 0;

uint8_t DHT11_READ();
void DHT11_HANDLE();
void DHT11_START();
void set_gpio_dht11_to_output();
void set_gpio_dht11_to_input();

void set_gpio_dht11_to_output(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void set_gpio_dht11_to_input(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void DHT11_START(){
	//Set chan PB11 thanh dau ra truoc
	set_gpio_dht11_to_output();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
	delay_ms(20);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
	//delay_us(40);
	//Xong qua trinh kich chan roi thi ve lai input
	set_gpio_dht11_to_input();
	//Cho tin hieu muc cao
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){}
	//Cho tin hieu muc thap
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 0){}
	//Cho tin hieu muc cao 1 lan nua
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){}
	//Xong qua trinh nay DHT11 bat dau gui 40byte data
}

uint8_t DHT11_READ(){
	uint8_t data = 0;
	for(int i =0; i < 8; i++){
		//every bit of data begins with the 50us low-voltage-leve
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 0){}
		//while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){}
		//Moc delay 50us nay de xac dinh dien ap con high hay low
		delay_us(50);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){
			data = (data << 1) | 1;
			//bit 1
		}else{
			data = (data << 1) & ~1;
			//bit 0
		}
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11) == 1){}
	}
	return data;
}

void DHT11_HANDLE(){
	DHT11_START();
	//Doc 5 byte data
	int_hum = DHT11_READ();
	dec_hum = DHT11_READ();
	//temp nay la nhiet do so nguyen
	int_temp = DHT11_READ();
	dec_temp = DHT11_READ();
	check_sum = DHT11_READ();
}
//************* Danh cho doc DHT11 *****************//

//************* Danh cho LCD 16x02 ******************//
void lcd_init();
void lcd_write(uint8_t data);
void lcd_send_command(uint8_t cmd);
void lcd_function_set();
void lcd_display_off();
void lcd_display_on();
void lcd_clear_display();
void lcd_entry_mode_set();
void lcd_return_home();
void lcd_cursor_or_display_shift();
void lcd_go_to_xy(uint8_t row, uint8_t col);
void lcd_printf_string(char *str);

void lcd_send_command(uint8_t cmd){
	//Keo chan RS xuong 0 trong t_AS min = 40ns
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	
	//MSB - dua tung bit 1 vao dung vi tri cua no
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (cmd >> 0) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (cmd >> 1) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (cmd >> 2) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (cmd >> 3) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (cmd >> 4) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (cmd >> 5) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (cmd >> 6) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (cmd >> 7) & 0x01);
	
	//Ha chan Enable xuong trong t_ER max 20ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	delay_ms(1);
	//Kich chan Enable len trong t_DSW min 80ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
	delay_ms(1);
	//Ha chan Enable xuong trong t_H min 10ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	delay_ms(1);
}

void lcd_clear_display(){
	lcd_send_command(0x01);
	//Execution time max 1.52ms
}

void lcd_return_home(){
	//Execution time max 1.52ms
	delay_ms(5);
	lcd_send_command(0x02);
}

void lcd_entry_mode_set(){
	//Execution time max 37us
	delay_us(100);
	lcd_send_command(0x06);
}

void lcd_display_off(){
	//Execution time max 37us
	delay_us(100);
	//Display off
	//Cursor off
	//Blink off
	lcd_send_command(0x08); 
}

void lcd_display_on(){
	//Execution time max 37us
	delay_us(100);
	//Display on
	//Cursor off
	//Blink on
	lcd_send_command(0x0C); //0x13;
}

void lcd_cursor_or_display_shift(){
	//Execution time max 37us
	delay_us(100);
	//Cursor move
	//Shift to the right
	lcd_send_command(0x14);
}

void lcd_function_set(){
	//Execution time max 37us
	delay_us(100);
	//8 bits
	//2 lines
	//5x8 dots
	lcd_send_command(0xF8);
}

void lcd_init(){
	//Nho keo chan RW xuong 0, chua ro vi sao
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
	delay_ms(50);
	lcd_send_command(0x38);
	delay_ms(5);
	lcd_send_command(0x38);
	delay_ms(1);
	lcd_send_command(0x38); 
	
	lcd_function_set();
	//lcd_cursor_or_display_shift();
	lcd_display_off();
	lcd_clear_display();
	lcd_entry_mode_set();
	lcd_display_on();
}

void lcd_write(uint8_t data){
	//Keo chan RS xuong 0 trong t_AS min = 40ns
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
	//Ko co delay_ns nen lay us
	delay_ms(1);
	
	//MSB - dua tung bit 1 vao dung vi tri cua no
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data >> 0) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data >> 1) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data >> 2) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data >> 3) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data >> 4) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data >> 5) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data >> 6) & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data >> 7) & 0x01);
	
	//Ha chan Enable xuong trong t_ER max 20ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	delay_ms(1);
	//Kich chan Enable len trong t_DSW min 80ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
	delay_ms(1);
	//Ha chan Enable xuong trong t_H min 10ns
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	delay_ms(1);
}

void lcd_go_to_xy(uint8_t row, uint8_t col){
	uint8_t row0 = 0x00; //Line 1
	uint8_t row1 = 0x40; //Line 2
	uint8_t address = 0x00;
	
	if(row == 0) address = row0 + col;
	else if(row == 1) address = row1 + col;
	lcd_send_command(0x80 + address);
}

void lcd_printf_string(char *str){
  while(*str){
    lcd_write(*str++);
  }
}

void lcd_print_pwm(int num){
	char buffer[6];
	sprintf(buffer, "%5d", num);
	lcd_printf_string(buffer);
}

void lcd_print_num(int num){
	char buffer[10];
	sprintf(buffer, "%d", num);
	lcd_printf_string(buffer);
}

	
//************* Danh cho LCD 16x02 ******************//

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
  MX_ADC1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	HAL_ADCEx_Calibration_Start(&hadc1);
	lcd_init();
	//Cai nay de danh cho xuat xung PWM LED tai PB10 - TIM2_CH3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	lcd_go_to_xy(0, 0);
  lcd_printf_string("PWM_VAL:");
	
	lcd_go_to_xy(1, 0);
	lcd_printf_string("TEMP:");
	lcd_go_to_xy(1, 9);
	lcd_printf_string("HUM:");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		//old_pwm_val = pwm_val;
		//old_int_temp = int_temp;
		//old_int_hum = int_hum;
		
		
		ADC_START();
		ADC_VOLT(&adc_volt, adc_val);
		pwm_val = (adc_val * 65535) / 4095;
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, pwm_val);
		DHT11_HANDLE();
		
		if(int_temp > 31) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);
		else HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
		
		lcd_go_to_xy(0, 8);
		lcd_print_pwm(pwm_val);
		HAL_Delay(300);
		
		lcd_go_to_xy(1, 5);
		lcd_print_num(int_temp);
		lcd_go_to_xy(1, 13);
		lcd_print_num(int_hum);
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 63;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 63;
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
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7
                           PA8 PA9 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
