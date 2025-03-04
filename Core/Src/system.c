#include "main.h"
#include "system.h"

// Function prototypes
void timer_loop(void);

// Variables
uint32_t adc_buffer;
uint8_t uart_buffer[2];
uint8_t uart_ready = 1;

void system_init(void) {
    HAL_ADC_Start_IT(&hadc1);
    HAL_TIM_Base_Start_IT(&htim14);
}

void system_loop(void) {

}




void timer_loop(void) {
    if (uart_ready) {
        
        uart_buffer[0] = (adc_buffer >> 8);  // bits 8-11
        uart_buffer[1] = adc_buffer;         // bits 0-7
        
        uart_ready = 0;
        HAL_UART_Transmit_IT(&huart2, uart_buffer, 2);
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM14) {
        timer_loop();
    }
}



void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1) {
    adc_buffer = HAL_ADC_GetValue(hadc1);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        uart_ready = 1;
    }
}