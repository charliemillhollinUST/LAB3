#ifndef SYSTEM_H
#define SYSTEM_H

#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern uint32_t adc_buffer;
extern TIM_HandleTypeDef htim14;

void system_init(void);
void system_loop(void);

#endif /* SYSTEM_H */