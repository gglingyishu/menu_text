#include "Key.h"
            

#define KEY1_PIN  GPIO_PIN_13
#define KEY2_PIN  GPIO_PIN_14
#define KEY3_PIN  GPIO_PIN_1
#define KEY4_PIN  GPIO_PIN_2


#define KEY3_MIN_TIME 0
#define KEY3_MAX_TIME 500

u8  keyscan(u8 mode)
{
	static u16 time = 0;
	static u8 lock = 0;

	
	
		if((time > KEY3_MIN_TIME)&&(time < KEY3_MAX_TIME)&&(0==mode))
		{
			printf("1");
			time = 0;
			return 1;
		}
		else if((time > KEY3_MAX_TIME)&&(0 == lock))
		{
			printf("2");
			time = 0;
			lock = 1;
			return 5;
		}
	if(1 == mode)
		time++;
	else
	{
		lock = 0;
		time = 0;
	}
		
		return 0;

	

}	

void KEY_Init(void)
{
	
    GPIO_InitTypeDef  GPIO_InitStructure;
		__HAL_RCC_GPIOA_CLK_ENABLE();	//使能A端口时钟
		__HAL_RCC_GPIOB_CLK_ENABLE();		
		__HAL_RCC_GPIOC_CLK_ENABLE();	
		__HAL_RCC_GPIOD_CLK_ENABLE();
    

    
    GPIO_InitStructure.Pin  = KEY2_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT; //设置上拉输入
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.Pin  = KEY3_PIN|KEY4_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT; //设置上拉输入
    HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);



}
