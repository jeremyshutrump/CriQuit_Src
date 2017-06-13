// @filename: CRIQ_statemachine.c
// @author: Joseph Clements, Jeremy Shutrump
// @descrip: Driver file for statemachine functions and datastructures. 
//		SDSU ECE Senior Design SP 2017. Team Criquit. 

#include "CRIQ_statemachine.h"
#include "arm_math.h"

// Global Statemachine variable:
StateUnion SYS_STATE;

void Statemachine_stateAction(StateUnion *su){
	uint8_t a;
	static float angle;
	static float ang;
	switch (su->bytes.State){
		case STANDBY_D:
			// add code here
			break;
		
		case STANDBY_N:
			// add code here
			break;
		
		case ALERT:
			// add code here
			break;
	
		case MAXIS_1_RDY:
			// Change ADC channels
			CRIQ_maxisChange();
			ang = CRIQ_locate();
		su->bytes.NextState = ALERT;
			if(CRIQ_ID()){
				a = 0x11;
				HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
				su->bytes.NextState = ATK;
				angle = ang;
			}
//			else{
//			su->bytes.NextState = ALERT;
//			}
			break;
		
		case MAXIS_2_RDY:
			// Change ADC Channels:
			CRIQ_maxisChange();
			ang= CRIQ_locate();
		su->bytes.NextState = ALERT;
		if(CRIQ_ID()){
				a = 0x12;
				HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
				su->bytes.NextState = ATK;
				angle = ang;
			}
//		else{
//			su->bytes.NextState = ALERT;
//			}
			break;
			
		case MAXIS_3_RDY:
			// Change ADC channels:
			CRIQ_maxisChange();
			ang= CRIQ_locate();
		su->bytes.NextState = ALERT;
			if(CRIQ_ID()){
				a = 0x13;
				HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
				su->bytes.NextState = ATK;
				angle = ang;
			}
//			else{
//			su->bytes.NextState = ALERT;
//			}
			break;
		
		case ATK:
			// Attack Routine:
			CRIQ_Attack(angle);
			su->bytes.NextState = ALERT;
			break;
		
		//default: // same as case: STANDBY_N:
			// add code here
	}

}

void Statemachine_changeState(StateUnion *su){
	uint8_t a;
	switch (su->bytes.NextState){	
		case STANDBY_D:
			//HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
			// ENABLE RTC
		  //HAL_GPIO_WritePin(GPIOA, Green_LED_Pin|WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_RESET);	
			//HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin|MAXIS_3_EN_Pin, GPIO_PIN_RESET);
			break;
		
		case STANDBY_N:
//			a = 0x65;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		HAL_TIM_Base_Stop_IT(&htim3);
		
			HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
			//HAL_PWR_EnterSTANDBYMode();
			HAL_PWR_EnterSTANDBYMode();
			a = 0x66;
			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
			break;
		
		case ALERT:
//			a = 0x75;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		//Reset timer for TIMEOUT event
			HAL_TIM_Base_Stop_IT(&htim3);
		//Reset:
			HAL_GPIO_WritePin(GPIOA, WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_RESET);
		//Set:	
			HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin|MAXIS_3_EN_Pin, GPIO_PIN_SET);
		//Start timer for TIMEOUT event
			//HAL_TIM_Base_Start_IT(&htim3);
		
			break;
		
		case MAXIS_1_RDY:
//			a = 0x85;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		//Reset timer for TIMEOUT event
			HAL_TIM_Base_Stop_IT(&htim3);
		
		//Reset:
			HAL_GPIO_WritePin(GPIOA, WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_RESET);	
			HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin|MAXIS_3_EN_Pin, GPIO_PIN_RESET);	
		//Set:
		//Start timer for TIMEOUT event
			//HAL_TIM_Base_Start_IT(&htim3);
			break;
		
		case MAXIS_2_RDY:
//			a = 0x95;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		//Reset timer for TIMEOUT event
			HAL_TIM_Base_Stop_IT(&htim3);
		
		//Reset:
			HAL_GPIO_WritePin(GPIOA, WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, MAXIS_3_EN_Pin, GPIO_PIN_RESET);	
		//Set:
			HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin, GPIO_PIN_SET);
		//Start timer for TIMEOUT event
			//HAL_TIM_Base_Start_IT(&htim3);
			break;
			
		case MAXIS_3_RDY:
//			a = 0xA5;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		//Reset timer for TIMEOUT event
			HAL_TIM_Base_Stop_IT(&htim3);
	
		//Reset:
			HAL_GPIO_WritePin(GPIOA, WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin, GPIO_PIN_RESET);	
		//Set:
			HAL_GPIO_WritePin(GPIOC, MAXIS_3_EN_Pin, GPIO_PIN_SET);
		//Start timer for TIMEOUT event
			//HAL_TIM_Base_Start_IT(&htim3);
			break;
		
		case ATK:
//			a = 0xB5;
//			HAL_UART_Transmit(&huart2, &a, 1, 0xFFFF);
		//Reset timer for TIMEOUT event
			HAL_TIM_Base_Stop_IT(&htim3);
		
		//Reset:
			HAL_GPIO_WritePin(GPIOC, MAXIS_2_EN_Pin|MAXIS_3_EN_Pin, GPIO_PIN_RESET);	
		//Set:
			HAL_GPIO_WritePin(GPIOA, WEP_EN_Pin|REG5V_EN_Pin, GPIO_PIN_SET);
			break;
		
		default: // same as case: STANDBY_N:
			HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
			HAL_PWR_EnterSTANDBYMode();
	}
	
	// Update the current state variable
	su->bytes.State = su->bytes.NextState;
}
