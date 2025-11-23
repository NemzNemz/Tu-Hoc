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
#include "math.h"

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
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//Dia chi I2C chi bao gom 7 bit, bit con lai la Read/Write nen phai dich sang trai 1 bit
#define I2C_ADDRESS 0x68<<1
#define REG_WHO_AM_I 0x75
#define REG_PWR_MGMT_1 0x6B
#define REG_SMPLRT_DIV 0x19
#define REG_GYRO_CONFIG 0X1B
#define REG_ACCEL_CONFIG 0x1C

//6 dia chi thanh ghi GYRO
#define REG_GYRO_XOUT_H 0x43
#define REG_GYRO_XOUT_L 0x44
#define REG_GYRO_YOUT_H 0x45
#define REG_GYRO_YOUT_L 0x46
#define REG_GYRO_ZOUT_H 0x47
#define REG_GYRO_ZOUT_L 0x48

//6 dia chi thanh ghi ACCEL
#define REG_ACCEL_XOUT_H 0x3B
#define REG_ACCEL_XOUT_L 0x3C
#define REG_ACCEL_YOUT_H 0x3D
#define REG_ACCEL_YOUT_L 0x3E
#define REG_ACCEL_ZOUT_H 0x3F
#define REG_ACCEL_ZOUT_L 0x40

//Doi RAD sang DEGREE
#define RAD_TO_DEG 57.295

//Struct luu 3 goc x, y, z cua cam bien gia toc
typedef struct{
	int16_t raw_ax;
	int16_t raw_ay;
	int16_t raw_az;
	float real_ax;
	float real_ay;
	float real_az;
}ACCEL;

ACCEL accel = {
	.raw_ax = 0,
	.raw_ay = 0,
	.raw_az = 0,
	.real_ax =0.0,
	.real_ay =0.0,
	.real_az =0.0
};

//Struct luu 3 goc x, y, z cua con quay hoi chuyen
typedef struct{
	int16_t raw_gx;
	int16_t raw_gy;
	int16_t raw_gz;
	float real_gx;
	float real_gy;
	float real_gz;
}GYRO;

GYRO gyro = {
	.raw_gx =0,
	.raw_gy =0,
	.raw_gz =0,
	.real_gx =0.0,
	.real_gy =0.0,
	.real_gz =0.0
};

typedef struct{
	float pitch;
	float yaw;
	float roll;
}ORIENT;

ORIENT orient = {
	.pitch = 0.0,
	.yaw = 0.0,
	.roll = 0.0
};


void MPU_6050_INIT();
void MPU_6050_Read_Accel();
void MPU_6050_Read_Gyro();
void convert_to_orientation(float ax, float ay, float az, float gx, float gy, float gz);

void MPU_6050_INIT(){
	/*tham so: hi2c1, dia chi cua device, dia chi cua thanh ghi muon doc, 
	kich thuoc dia chi do (BYTE), *pData de tra gia tri, so byte muon doc, timeout*/
	uint8_t check;
	uint8_t pmData;
	uint8_t smpData;
	uint8_t gyroData;
	uint8_t accelData;
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDRESS, REG_WHO_AM_I, 1, &check, 1, 1000);
	//Neu dung dia chi 0x68 thi bat dau ghi vao cac thanh ghi can thiet
	if(check == 0x68){
		pmData = 0x00; //CLK_SEL 0 de chon thanh anh noi 8Mhz
		HAL_I2C_Mem_Write(&hi2c1, I2C_ADDRESS, REG_PWR_MGMT_1, 1, &pmData, 1, 1000);
		smpData = 0x07; //GYRO_OUTPUT_RATE = 1kHz (0x00 hoac 0x07)
		HAL_I2C_Mem_Write(&hi2c1, I2C_ADDRESS, REG_SMPLRT_DIV, 1, &smpData, 1, 1000);
		gyroData = 0x00; //FS_SEL 00, tam do +- 250/s
		HAL_I2C_Mem_Write(&hi2c1, I2C_ADDRESS, REG_GYRO_CONFIG, 1, &gyroData, 1, 1000);
		accelData = 0x00; //AFS_SEL 00, tam do +-2g
		HAL_I2C_Mem_Write(&hi2c1, I2C_ADDRESS, REG_ACCEL_CONFIG, 1, &accelData, 1, 1000);
	}
}

void MPU_6050_Read_Gyro(){
	//Tao 6 mang, 1 mang luu 1 thanh ghi, yeu cau 6 thanh ghi day du cho 3 gia tri x, y, z
	uint8_t gyroData[6];
	/*tham so: hi2c1, dia chi cua device, dia chi cua thanh ghi muon doc, 
	kich thuoc dia chi do (BYTE), *pData de tra gia tri, so byte muon doc, timeout*/
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDRESS, REG_GYRO_XOUT_H, 1, gyroData, 6, 1000);
	gyro.raw_gx = (int16_t)(gyroData[0] << 8 | gyroData[1]);
	gyro.raw_gy = (int16_t)(gyroData[2] << 8 | gyroData[3]);
	gyro.raw_gz = (int16_t)(gyroData[4] << 8 | gyroData[5]);
	//Tam do +- 250d/s
	gyro.real_gx = (float)gyro.raw_gx /131.0;
	gyro.real_gy = (float)gyro.raw_gy /131.0;
	gyro.real_gz = (float)gyro.raw_gz /131.0;
}

void MPU_6050_Read_Accel(){
	//Tao 6 mang, 1 mang luu 1 thanh ghi, yeu cau 6 thanh ghi day du cho 3 gia tri x, y, z
	uint8_t accelData[6];
	/*tham so: hi2c1, dia chi cua device, dia chi cua thanh ghi muon doc, 
	kich thuoc dia chi do (BYTE), *pData de tra gia tri, so byte muon doc, timeout*/
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDRESS, REG_ACCEL_XOUT_H, 1, accelData, 6, 1000);
	accel.raw_ax = (int16_t)(accelData[0] << 8 | accelData[1]);
	accel.raw_ay = (int16_t)(accelData[2] << 8 | accelData[3]);
	accel.raw_az = (int16_t)(accelData[4] << 8 | accelData[5]);
	//Tam do +-2g
	accel.real_ax = (float)accel.raw_ax /16384.0;
	accel.real_ay = (float)accel.raw_ay /16384.0;
	accel.real_az = (float)accel.raw_az /16384.0;
}

void convert_to_orientation(float ax, float ay, float az, float gx, float gy, float gz){
	//Goc Pitch va Roll lay tu Accel
	float pitch_A = atan2f(ay, sqrtf(ax*ax + az*az))*RAD_TO_DEG;
	float roll_A = atan2f(-ax, sqrtf(ay*ay + az*az))*RAD_TO_DEG;
	
	//Goc Pitch va Roll lay tu Gyro
	float pitch_G = orient.pitch + gx * (1/100.0f);
	float roll_G = orient.roll + gy * (1/100.0f);
	
	orient.pitch = 0.98 * pitch_G + 0.02 * pitch_A;
	orient.roll = 0.98 * roll_G + 0.02 * roll_A;
}


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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
	MPU_6050_INIT();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		MPU_6050_Read_Gyro();
		MPU_6050_Read_Accel();
		convert_to_orientation(accel.real_ax, accel.real_ay, accel.real_az, gyro.real_gx, gyro.real_gy, gyro.real_gz);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

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
