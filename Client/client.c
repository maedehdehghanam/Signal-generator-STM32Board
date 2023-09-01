#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "LCD16x2Lib/LCD.h"



#define V_REF 5f // Reference voltage 
#define ADC_MAX_VALUE 4095 // Maximum value of 12-bit ADC
#define MAX_DURATION_VALUE 10000 
#define MIN_DURATION_VALUE 500 
#define MAX_FREQUENCY_VALUE 1
#define MIN_FREQUENCY_VALUE 1000 


void GPIO_Init();
void SysTick_Handler();
char read_keypad();
void MX_ADC1_Init(void);
uint32_t ADC_Read();
void MX_GPIO_Init(void);
void SystemClock_Config(void);
double get_time(double);
uint32_t set_duration(void);
uint32_t set_frequency(void);
void Error_Handler(void);


ADC_HandleTypeDef hadc1;
ADC_ChannelConfTypeDef sConfig = {0};
double duration_golbal=0;
double frequency_golbal =0;
int wave = -1;


int main(void)
{
	char key= '*';
	SystemCoreClockUpdate();
	HAL_Init();
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	SystemClock_Config();
	
	GPIO_Init();
	MX_GPIO_Init();
	MX_ADC1_Init();
	
	LCD_Init();
	LCD_Puts(1, 0, "ID: 99243017");
	LCD_Puts(40, 0, "ID: 99243034");
	LCD_Delay_ms(1000);
	
	LCD_Clear();
	LCD_Puts(1, 3, "1.Sin  2.Square   3.Triangle");
	LCD_Puts(40, 7, "4.|Sin|   5.Sawtooth   6.ramp");
	while (1)
	{
		key = read_keypad();
		LCD_Puts(8, 5, &key);
		if(key == '1'){
			wave = 1;
			LCD_Clear();
			duration_golbal = set_duration();
			frequency_golbal = set_frequency();
		} 
		else if(key == '2'){
			wave = 2;
			LCD_Clear();
			duration_golbal = set_duration();
			frequency_golbal = set_frequency();
		} 
		else if(key == '3'){
			wave = 3;
			
		} 
		else if(key == '4'){
			wave = 4;
		} 
		else if(key == '5'){
			wave = 5;
		} 
		else if(key == '6'){
			wave = 6;
		} 
		HAL_Delay(200);
	}
	return 0;
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

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
	char read_keypad(void)
{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);  //Pull the R1 low
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // Pull the R2 High
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);  // Pull the R3 High
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);  // Pull the R4 High
		
	if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)));   // wait till the button is pressed
		return '1';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
		return '2';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
		return '3';
	}
	
	
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the R1 low
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);  // Pull the R2 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);  // Pull the R3 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);  // Pull the R4 High
		
	if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)));   // wait till the button is pressed
		return '4';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
		return '5';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
		return '6';
	}
	
	
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the R1 low
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // Pull the R2 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);  // Pull the R3 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);  // Pull the R4 High
		
	if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)));   // wait till the button is pressed
		return '7';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
		return '8';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
		return '9';
	}
	
	
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);  //Pull the R1 low
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // Pull the R2 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);  // Pull the R3 High
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);  // Pull the R4 High
		
	if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
	{
		while (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)));   // wait till the button is pressed
		return '*';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 2 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
		return '0';
	}
		
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)))   // if the Col 3 is low
	{
		while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
		return '#';
	}
}
	

void GPIO_Init()
{
	GPIO_InitTypeDef PinConfig;
	PinConfig.Pin = GPIO_PIN_7;
	PinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.Pull = GPIO_PULLDOWN ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	PinConfig.Pin = GPIO_PIN_0;
	PinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.Pull = GPIO_PULLDOWN ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	PinConfig.Pin = GPIO_PIN_2;
	PinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.Pull = GPIO_PULLDOWN ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	PinConfig.Pin = GPIO_PIN_3;
	PinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.Pull = GPIO_PULLDOWN ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	
	PinConfig.Pin = GPIO_PIN_4;
	PinConfig.Mode = GPIO_MODE_INPUT;
	PinConfig.Pull = GPIO_PULLUP  ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	
	PinConfig.Pin = GPIO_PIN_5;
	PinConfig.Mode = GPIO_MODE_INPUT;
	PinConfig.Pull = GPIO_PULLUP  ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	
	
	PinConfig.Pin = GPIO_PIN_6;
	PinConfig.Mode = GPIO_MODE_INPUT;
	PinConfig.Pull = GPIO_PULLUP  ;
	PinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &PinConfig);
	

}
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

 // __HAL_RCC_GPIOA_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void MX_ADC1_Init(void)
{
	__HAL_RCC_ADC1_CLK_ENABLE();
   hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_10B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  //sConfig.Offset = 0;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	
	GPIO_InitTypeDef GPIO_InitStruct;


}
uint32_t ADC_Read()
{
  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, 5);
  uint32_t value = HAL_ADC_GetValue(&hadc1);
  return value;
}
double get_time(double adc_val){
	adc_val = (adc_val/ ADC_MAX_VALUE)*5;
	double duration = adc_val;
	return duration;
}
uint32_t set_duration(){
	uint32_t adc_value;
	
	while(1){
		adc_value = ADC_Read();
		double duration = ((float)(adc_value) / 681.0) * 5;
		duration = (duration * (100 - 5) /5) + 5;
		duration *= 100;
		char adc_string[20];
		char key2 ='*';
		sprintf(adc_string, "%.1lf", duration);
		LCD_Puts(20, 7, adc_string);
		key2 = read_keypad();
		if(key2 == '#'){
			duration_golbal = duration;
			break;
		}
	}
	return adc_value;
}

uint32_t set_frequency(){
	uint32_t adc_value;
	char key2 ='*';
	while(1){
		adc_value = ADC_Read();
		double frequency = ((float)(adc_value) / 681.0) * 5;
		frequency = (frequency * (1000 - 1) /5) + 1;
		char adc_string[20];
		sprintf(adc_string, "%.1lf", frequency);
		LCD_Puts(20, 7, adc_string);
		key2 = read_keypad();
		if(key2 == '#'){
			frequency_golbal = frequency;
			break;
		}
	}
	return adc_value;
}
void SysTick_Handler()
{
  HAL_IncTick();
}
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

