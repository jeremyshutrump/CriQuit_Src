#ifndef CRIQ_FUNCTIONS_H
#define CRIQ_FUNCTIONS_H

// includes
#include <stdint.h>
#include <math.h>
#include "stm32f4xx_hal.h"
#include "CRIQ_statemachine.h"
#include "arm_math.h"

// defines
#define MIC_DISTANCE (float)0.0381
#define SERVO_WAIT_MS 2000
#define ATK_PERIOD_MS 3000
#define CENTER_POSITION 1500

// variables
extern ADC_HandleTypeDef hadc1;	// global variable in main.c
extern ADC_HandleTypeDef hadc2;	// global variable in main.c
extern uint32_t DMA_value[512];	// global variable in main.c
//extern float32_t IDdata[4096];	// global variable in main.c
extern TIM_HandleTypeDef htim1;	// global variable in main.c
extern TIM_HandleTypeDef htim2;	// global variable in main.c
extern TIM_HandleTypeDef htim4;	// global variable in main.c
extern TIM_HandleTypeDef htim7;	// global variable in main.c
extern UART_HandleTypeDef huart2;
// function prototypes:
extern void CRIQ_maxisChange(void);
extern char CRIQ_ID(void);
extern float CRIQ_locate(void);
extern void CRIQ_Attack( float angle );
//extern void Error_Handler(void); // in main.c
extern void CRIQ_slowDriveServo(float target, float prev);
extern void CRIQ_driveServo(float target);
#endif // CRIQ_FUNCTIONS_H

