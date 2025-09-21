#include "Boot.h"
#include "CanRx.h"










void Boot()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
	HAL_Delay(10);
	Init();


	while(1)
	{

		CAN_CheckReceive();



	}
}
