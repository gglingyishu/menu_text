#ifndef __KEY_H
#define __KEY_H	


#include "sys.h"             

#define KEY3_PIN  GPIO_Pin_1
#define KEY3_GPIO_Port GPIOA
#define KEY3     GPIO_ReadInputDataBit(KEY3_GPIO_Port,KEY3_PIN) 

#define KEY4_PIN  GPIO_Pin_2
#define KEY4_GPIO_Port GPIOA
#define KEY4     GPIO_ReadInputDataBit(KEY4_GPIO_Port,KEY4_PIN)


void KEY_Init(void);
u8  keyscan(u8 mode);


#endif
