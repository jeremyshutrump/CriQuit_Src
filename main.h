/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define NOISE_WKUP_Pin GPIO_PIN_0
#define NOISE_WKUP_GPIO_Port GPIOA
#define Green_LED_Pin GPIO_PIN_5
#define Green_LED_GPIO_Port GPIOA
#define WEP_EN_Pin GPIO_PIN_7
#define WEP_EN_GPIO_Port GPIOA
#define MAXIS_1_COMP_EXT12_Pin GPIO_PIN_12
#define MAXIS_1_COMP_EXT12_GPIO_Port GPIOB
#define MAXIS_1_COMP_EXT12_EXTI_IRQn EXTI15_10_IRQn
#define MAXIS_2_COMP_EXT13_Pin GPIO_PIN_13
#define MAXIS_2_COMP_EXT13_GPIO_Port GPIOB
#define MAXIS_2_COMP_EXT13_EXTI_IRQn EXTI15_10_IRQn
#define MAXIS_3_COMP_EXT14_Pin GPIO_PIN_14
#define MAXIS_3_COMP_EXT14_GPIO_Port GPIOB
#define MAXIS_3_COMP_EXT14_EXTI_IRQn EXTI15_10_IRQn
#define WEP_PWM_N_Pin GPIO_PIN_15
#define WEP_PWM_N_GPIO_Port GPIOB
#define MAXIS_2_EN_Pin GPIO_PIN_6
#define MAXIS_2_EN_GPIO_Port GPIOC
#define MAXIS_3_EN_Pin GPIO_PIN_8
#define MAXIS_3_EN_GPIO_Port GPIOC
#define REG5V_EN_Pin GPIO_PIN_9
#define REG5V_EN_GPIO_Port GPIOA
#define WEP_PWM_P_Pin GPIO_PIN_10
#define WEP_PWM_P_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
extern short a;
extern float input[4096];
/* USER CODE END Private defines */

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
