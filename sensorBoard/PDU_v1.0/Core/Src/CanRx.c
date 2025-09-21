#include "CanRx.h"


extern CAN_HandleTypeDef hcan1;

CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;

uint8_t TxData[8];
uint8_t RxData[8];

uint32_t TxMailbox;

bool datacheck = false;



void CAN_CheckReceive()
{


		if(datacheck == true)
				{
						Block_1();
						Block_2();
						Block_3();
						Block_4();
						Block_5();
						Block_6();
						HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5);
						HAL_Delay(100);
						HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, &TxMailbox);


					}
					datacheck = false;


}

void Init()
{
		CanFilterInit();
		HAL_CAN_Start(&hcan1);
		HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO1_MSG_PENDING);

		/**Initialisation**/
		TxHeader.DLC = 8; //data length
		TxHeader.IDE = CAN_ID_STD; //standart
		TxHeader.RTR = CAN_RTR_DATA; //data frame
		TxHeader.StdId = 0x55; // senders ID
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{

	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxHeader, RxData);
	if (RxHeader.DLC == 8)
	{
datacheck = true;
	}
}

void CanFilterInit()
{
CAN_FilterTypeDef canfilterconfig;

canfilterconfig.FilterActivation = CAN_FILTER_ENABLE;
canfilterconfig.FilterBank = 5;
canfilterconfig.FilterFIFOAssignment = CAN_FILTER_FIFO1;
canfilterconfig.FilterIdHigh = 0x44<<5;
canfilterconfig.FilterIdLow = 0;
canfilterconfig.FilterMaskIdHigh = 0x44<<5;
canfilterconfig.FilterMaskIdLow = 0;
canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;

HAL_CAN_ConfigFilter(&hcan1, &canfilterconfig);
}


void Block_1()
{
	if( RxData[0] == 0x0)
			{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
HAL_Delay(10);
TxData[0] = 0x0;

			}
	else if(RxData[0] == 0x1)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
HAL_Delay(10);
TxData[0] = 0x1;
	}
	else if(RxData[0] == 0x2)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
HAL_Delay(10);
TxData[0] = 0x2;
	}
	else if(RxData[0] == 0x3)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
HAL_Delay(10);
TxData[0] = 0x3;
	}
	else if(RxData[0] == 0x4)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
HAL_Delay(10);
TxData[0] = 0x3;
	}
	else
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
HAL_Delay(10);
TxData[0] = 0x0;
	}
}


void Block_2()
{
	if( RxData[1] == 0x0)
			{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
HAL_Delay(10);
TxData[1] = 0x0;
			}
	else if(RxData[1] == 0x1)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
HAL_Delay(10);
TxData[1] = 0x1;
	}
	else if(RxData[1] == 0x2)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
HAL_Delay(10);
TxData[1] = 0x2;
	}
	else if(RxData[1] == 0x3)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
HAL_Delay(10);
TxData[1] = 0x3;
	}
	else
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
HAL_Delay(10);
TxData[1] = 0x0;
	}
}


void Block_3()
{
	if( RxData[2] == 0x0)
			{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
HAL_Delay(10);
TxData[2] = 0x0;
			}
	else if(RxData[2] == 0x1)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
HAL_Delay(10);
TxData[2] = 0x1;
	}
	else if(RxData[2] == 0x2)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
HAL_Delay(10);
TxData[2] = 0x2;
	}
	else if(RxData[2] == 0x3)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
HAL_Delay(10);
TxData[2] = 0x3;
	}
	else
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
HAL_Delay(10);
TxData[2] = 0x0;
	}
}

void Block_4()
{
	if( RxData[3] == 0x0)
			{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
HAL_Delay(10);
TxData[3] = 0x0;
			}
	else if(RxData[3] == 0x1)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
HAL_Delay(10);
TxData[3] = 0x1;
	}
	else if(RxData[3] == 0x2)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);
HAL_Delay(10);
TxData[3] = 0x2;
	}
	else if(RxData[3] == 0x3)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);
HAL_Delay(10);
TxData[3] = 0x3;
	}
	else
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
HAL_Delay(10);
TxData[3] = 0x0;
	}
}

void Block_5()
{
	if( RxData[4] == 0x0)
			{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
HAL_Delay(10);
TxData[4] = 0x0;
			}
	else if(RxData[4] == 0x1)
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
HAL_Delay(10);
TxData[4] = 0x1;
	}
	else if(RxData[4] == 0x2)
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
HAL_Delay(10);
TxData[4] = 0x2;
	}
	else if(RxData[4] == 0x3)
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
HAL_Delay(10);
TxData[4] = 0x3;
	}
	else
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
HAL_Delay(10);
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
HAL_Delay(10);
TxData[4] = 0x0;
	}
}

void Block_6()
{
	if( RxData[5] == 0x0)
			{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);
HAL_Delay(10);
TxData[5] = 0x0;
			}
	else if(RxData[5] == 0x1)
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);
HAL_Delay(10);
TxData[5] = 0x1;
	}

	else
	{
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);
HAL_Delay(10);
TxData[5] = 0x0;
	}
}
