// @filename: CRIQ_statemachine.h
// @author: Joseph Clements
// @descrip: Header file for statemachine functions and data structures. 
//		SDSU ECE Senior Design SP 2017. Team Criquit. 

#ifndef CRIQ_STATEMACHINE
#define CRIQ_STATEMACHINE
// includes:
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "CRIQ_functions.h"
#include "arm_math.h"

// STATE DEFINITIONS:
#define STANDBY_D 0x20
#define STANDBY_N 0x10
#define ALERT 0x03
#define MAXIS_1_RDY 0X00
#define MAXIS_2_RDY 0X02
#define MAXIS_3_RDY 0X01
#define ATK	0x0C

#define STATECHANGE_RDY(X) (X.bytes.NextState != X.bytes.State)

typedef union{
	uint16_t val;
	
	struct{
		uint8_t NextState;
		uint8_t State;
	} bytes;

	struct{
		uint8_t bit15 : 1;
		uint8_t bit14 : 1;
		uint8_t bit13 : 1;
		uint8_t bit12 : 1;
		uint8_t bit11 : 1;
		uint8_t bit10 : 1;
		uint8_t bit9 : 1;
		uint8_t bit8 : 1;
		
		uint8_t bit7 : 1;
		uint8_t bit6 : 1;
		uint8_t RTC_ALARM : 1;
		uint8_t WKUP_PIN : 1;
		uint8_t WEP_EN : 1;
		uint8_t REG5V_EN : 1;
		uint8_t MAXIS_2_EN : 1;
		uint8_t MAXIS_3_EN : 1;
	} bits; 
} StateUnion;

// External variables:
extern StateUnion SYS_STATE;	// main.c
extern UART_HandleTypeDef huart2;	// main.c
extern TIM_HandleTypeDef htim3;	// main.c
extern TIM_HandleTypeDef htim7; // main.c
// Function Prototypes:
extern void Statemachine_changeState(StateUnion *su);
extern void Statemachine_stateAction(StateUnion *su);
#endif // CRIQ_STATEMACHINE

