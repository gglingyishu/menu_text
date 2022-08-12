#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "gg_menu.h"
#include "menu1.h"
#include "menu2.h"
#include "menu3.h"
#include "lcd.h"
#include "lcd_init.h"
#include "Key.h"
#include "flash.h"


#define KEY1_PIN  GPIO_PIN_13
#define KEY2_PIN  GPIO_PIN_14

void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}
GG_MENU_TypeDef  MENUMAIN;
GG_MENUPAGE_TypeDef MENU1;
GG_MENUPAGE_TypeDef MENU2;
GG_MENUPAGE_TypeDef MENU3;

extern GG_MENU_StateTypeDef g_MENU_MainSta;


int main(void)
{
	//u8 temp;
		u8 datatemp[2];
    HAL_Init();                    	 			//初始化HAL库    
		delay_init(72/8);
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//设置时钟,72M
    uart_init(115200);
		
		LCD_Init();
		KEY_Init();
		
    GG_MENU_Init(&MENUMAIN);
    GG_MENU1_Init(&MENU1); 
    GG_MENU2_Init(&MENU2);   
		GG_MENU3_Init(&MENU3);
	//datatemp[0]=4;
	// STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)datatemp,1);
	//delay_ms(3000);
STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)datatemp,1);
	//datatemp
   
		if(1 == (datatemp[0]&0x01))
		{
			MENU1.show(&MENU1);
		}
		else if(2==(datatemp[0]&0x02))
		{
			MENU2.show(&MENU2);
		}
		else if(4==(datatemp[0]&0x04))
		{
			MENU3.show(&MENU3);
		}
		else
		{
				MENU1.show(&MENU1);
		}

	
	while(1)
	{
        delay_ms(5);
      

				 GG_MENU_SendKeySign(keyscan((~HAL_GPIO_ReadPin(GPIOC,KEY1_PIN))&0x01));
				 GG_MENU_LastSignWork();			//处理当前信号函数

	}
    
}










