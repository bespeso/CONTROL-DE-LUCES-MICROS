/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "STM_MY_LCD16X2.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_SELECT 4;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */




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
  /* USER CODE BEGIN 2 */

  //Inicializar LCD

  LCD1602_Begin4BIT(RS_DISPLAY_GPIO_Port, RS_DISPLAY_Pin, E_DISPLAY_Pin, D4_DISPLAY_GPIO_Port, D4_DISPLAY_Pin, D5_DISPLAY_Pin, D6_DISPLAY_Pin, D7_DISPLAY_Pin);
  LCD1602_clear();


  //Variables

  int mode=0;
  int selection=0;

  int enter=0;
  int back=0;
  int action=0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if(mode==0) //Selection mode
	  {
		  if(selection==0)
		  {
			  LCD1602_1stLine();
			  LCD1602_print("SELECCIONE ");
			  LCD1602_2ndLine();
			  LCD1602_print("MODO -> ");
		  }
		  else if(selection==1)//Manual mode
		  {

			  LCD1602_1stLine();
			  LCD1602_print("MODO 1");
			  LCD1602_2ndLine();
			  LCD1602_print("<- MANUAL ->");
			  	  if(enter==1) //Press enter to manual mode on
			  	  {
			  		  LCD1602_clear();
			  		  enter=0;
			  		  mode=1;
			  	  }
		  }
		  else if(selection==2) //Light mode
		  {

			  LCD1602_1stLine();
			  LCD1602_print("MODO 2");
			  LCD1602_2ndLine();
			  LCD1602_print("<- DIA/NOCHE ->");
			  	  if(enter==1)
			  	  {
		  				LCD1602_clear();
		  				enter=0;
		  				mode=2;
		  			}
		  	}
		  	else if(selection==3) //Movement mode
		  	{
		  		LCD1602_1stLine();
		  		LCD1602_print("MODO 3");
		  		LCD1602_2ndLine();
		  		LCD1602_print("<- MOVIMIENTO ->");

		  		if(enter==1)
		  		{
		  			LCD1602_clear();
		  			enter=0;
		  			mode=3;
		  		}
		  	}
		  	else if(selection==4) //Brightness regulation
		  	{
		  		LCD1602_1stLine();
		  		LCD1602_print("MODO 4");
				LCD1602_2ndLine();
				LCD1602_print("<- PWM BRILLO");

				if(enter==1)
				{
		  			LCD1602_clear();
					enter=0;
					mode=4;
				}
		  	}
	  }
	  else if(mode==1) //Manual mode
	  {
	  		LCD1602_1stLine();
	  		LCD1602_print("MODO 1 ON");
	  		LCD1602_2ndLine();
	  		LCD1602_print("MANUAL");



	  		if(back==1) //Press back to selection mode on
	  		{
	  			LCD1602_clear();
	  			back=0;
	  			mode=0;
	  		}
	 }
	 else if(mode==2) //Light mode
	 {
		  LCD1602_1stLine();
		  LCD1602_print("MODO 2 ON");
		  LCD1602_2ndLine();
		  LCD1602_print("DIA/NOCHE");

		  //ADC


		  if(back==1)
		  {
			  LCD1602_clear();
			  back=0;
			  mode=0;
		  }
	  }

	  else if(mode==3) //Movement mode
	  {
	  		LCD1602_1stLine();
	  		LCD1602_print("MODO 3 ON");
	  		LCD1602_2ndLine();
	  		LCD1602_print("MOVIMIENTO");

	  		//Ultrasound

	  		if(back==1)
	  		{
	  			LCD1602_clear();
	  			back=0;
	  			modE=0;
	  		}
	  	}

	  	else if (mode==4) //Brightness regulation
	  	{
	  		LCD1602_1stLine();
	  		LCD1602_print("MODO 4 ON");
	  		LCD1602_2ndLine();
	  		LCD1602_print("BRILLO");

	  		//PWM

	  		if(back==1)
	  		{
	  			LCD1602_clear();
	  			back=0;
	  			mode=0;
	  		}
	  	}





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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
