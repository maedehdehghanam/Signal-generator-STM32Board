#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "LCD16x2Lib/LCD.h"
#include <math.h>
#include "lookup_table.h"

#define M_TWOPI 6.283185307179586476925286766559

//methods define
void delay(int n);
void SystemClock_Config(void);
void SysTick_Handler(void);
void Error_Handler(void);
void TIM2_Init(void);
void TIM2_IRQHandler(void);
void set_parameters(void);	
void analog_port_ADC_init(void);

void show_sin(void);
void show_square(void);
void show_triangle(void);
void show_fabs_sin(void);
void show_ramp(void);
void show_sawtooth(void);

int sign(double input);

//variables define
volatile static int sample = 200;
volatile static int wave = -1;

volatile static int frequency_global = 4096;
volatile static int duration_global = 4096;
volatile static int is_duration = 0;
volatile static int time = 1;


int main(void)
{
	SystemCoreClockUpdate();
	HAL_Init();
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	SystemClock_Config();
	
	//enabling clks - setting output-input modes
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOA->MODER = 0x55555555;
	GPIOC->MODER = 0x55555555;

	LCD_Init();
	
	analog_port_ADC_init();
  TIM2_Init();

	while (1)
	{
		if(GPIOA->IDR & 0x00000080){
    sample = 0;
    __disable_irq();

    wave = 3;
		delay(100);

			//get freq
		set_parameters();
    delay(500);

			//get duration
		set_parameters();
    delay(500);
			
    TIM2_Init();
    delay(500);     
		}
	}
}

void set_parameters(void)
{
	    if(is_duration == 0){
	    	frequency_global = 500;
	    	is_duration = 1;
        delay(1250);

	    }else{
	    	duration_global = 10000;
	    	is_duration = 0;
        delay(1250);
	    }
}

void analog_port_ADC_init(void) {
    /* set up pin PA1-POT for analog input */
    RCC->AHB1ENR |=  1;                    
    GPIOA->MODER &=  ~0x0000000C;
    GPIOA->MODER |=  0x0000000C;           

    /* setup ADC1 */
    RCC->APB2ENR |= 0x00000100;            
    ADC1->CR2 = 0;                         
    ADC1->CR2 |= 1;                        
}


/* delay n milliseconds (8 MHz CPU clock) */ 
void delay(int n) {
	for (; n > 0; n--)
	for (int i = 0; i < 3200; i++) ;   
}

void TIM2_Init()
{
    RCC->APB1ENR |= 1;                  /* enable TIM2 clock */
    TIM2->PSC = (((8000000) / (frequency_global * 200))) - 1;        	//TIM2->PSC = (Input Clock Frequency) / (Desired Output Frequency)    ?
    TIM2->ARR = 200 - 1;     						//TIM2->ARR = (desired_period * input_clock_frequency) - 1            ?
    TIM2->CNT = 0;                      /* clear timer counter */
    TIM2->DIER|= TIM_DIER_UIE;
    TIM2->CR1 = 1;                      /* enable TIM2 */
    NVIC_EnableIRQ(TIM2_IRQn);
    __enable_irq();                     /* global enable IRQs */
}

void show_sin(void)
{
	while (time < duration_global){
		GPIOC->ODR = (int)(10000*(sin((M_TWOPI/360)*frequency_global*time / 1000)+1));
		time++;}
}
	
void show_square(void)
{
	while (time < duration_global){
		GPIOC->ODR = (64 * sign(sin(frequency_global * M_TWOPI * time / 1000))) ;
		time++;}
}

void show_fabs_sin(void)
{
	while(time < duration_global *100) {
		GPIOC->ODR = (int)(16384*(fabs(sin((M_TWOPI/360)*time*frequency_global/100))));	
		time++;}
}

void show_triangle(void)
{
}

void show_ramp(void)
{
}

void show_sawtooth(void)
{
}

void TIM2_IRQHandler(void) {
	TIM2->SR = 0;								// CLEAR THE UIF
	
	switch(wave) {
		case 1:
			GPIOC->ODR = sine_lookup[sample++];break;
			//show_sin();break;
		case 2:
			GPIOC->ODR = square_lookup[sample++];break;
			//show_square();break;
		case 3:
			GPIOC->ODR = triangle_lookup[sample++];break;
		 //show_triangle();break;
		case 4:
			GPIOC->ODR = fabs_sin_lookup[sample++];break;
			//show_fabs_sin();break;
		case 5:
			GPIOC->ODR = ramp_lookup[sample++];break;
			//show_ramp();break;
		case 6:
			GPIOC->ODR = sawtooth_lookup[sample++];break;
			//show_sawtooth();break;
	}

  if(sample == 200){
      sample = 0;
  }
}

int sign(double input)
{
	if (input > 0) 
		return 2;
	if (input < 0) 
		return 0;
	return 1;
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

void SysTick_Handler(void)
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

