#include "lcd_init.h"
#include "lcd.h"
#include "delay.h"
#include "usart.h"
#include "stm32f1xx.h"


void SPI2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_HandleTypeDef SPI_HandleTypeDefStruct;
	__HAL_RCC_SPI2_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();			//ʹ��GPIOBʱ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��GPIOB

	GPIO_InitStructure.Pin =GPIO_PIN_13|GPIO_PIN_15;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;//�ٶ�50MHz
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;	 //�����������
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ��GPIOB
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13|GPIO_PIN_15,GPIO_PIN_SET);
	
	SPI_HandleTypeDefStruct.Instance = SPI2;
	SPI_HandleTypeDefStruct.Init.Direction = SPI_DIRECTION_1LINE;
	SPI_HandleTypeDefStruct.Init.Mode = SPI_MODE_MASTER;
	SPI_HandleTypeDefStruct.Init.DataSize = SPI_DATASIZE_8BIT;
	SPI_HandleTypeDefStruct.Init.CLKPolarity = SPI_POLARITY_HIGH;
	SPI_HandleTypeDefStruct.Init.CLKPhase = SPI_PHASE_2EDGE;
	SPI_HandleTypeDefStruct.Init.NSS = SPI_NSS_SOFT;
	SPI_HandleTypeDefStruct.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
	SPI_HandleTypeDefStruct.Init.FirstBit = SPI_FIRSTBIT_MSB;
	SPI_HandleTypeDefStruct.Init.CRCPolynomial =7;
	
	HAL_SPI_Init(&SPI_HandleTypeDefStruct);//��ʼ��SPI
	//SPI_Cmd(SPI2, ENABLE);//ʹ��SPI
	assert_param(IS_SPI_ALL_PERIPH(SPI2));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	SPI2->CR1 |=  ((uint16_t)0x0040);
}



void LCD_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	__HAL_RCC_GPIOB_CLK_ENABLE();	
	__HAL_RCC_GPIOA_CLK_ENABLE();	//ʹ��A�˿�ʱ��
	__HAL_RCC_GPIOC_CLK_ENABLE();	
	GPIO_InitStructure.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;	 
 	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 		 //�������
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;//�ٶ�50MHz
 	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8,GPIO_PIN_SET);	
	
	GPIO_InitStructure.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15;
 	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);	 
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	

}

/******************************************************************************
      ����˵����LCD��������д�뺯��
      ������ݣ�dat  Ҫд��Ĵ�������
      ����ֵ��  ��
******************************************************************************/
void LCD_Writ_Bus(u8 dat) 
{	
	int i;
		LCD_CS_Clr();
	for(i=0;i<8;i++)
	{			  
		LCD_SCLK_Clr();
		if(dat&0x80)
		{
		   LCD_MOSI_Set();
		}
		else
		{
		   LCD_MOSI_Clr();
		}
		LCD_SCLK_Set();
		dat<<=1;
	}	
  LCD_CS_Set();	
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//д����
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//д����
}


/******************************************************************************
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//������д
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1+80);
		LCD_WR_DATA(y2+80);
		LCD_WR_REG(0x2c);//������д
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//������д
	}
	else
	{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1+80);
		LCD_WR_DATA(x2+80);
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//������д
	}
}

void LCD_Init(void)
{
	SPI2_Init();
	LCD_GPIO_Init();//��ʼ��GPIO

	LCD_RES_Clr();//��λ
	delay_ms(100);
	LCD_RES_Set();
	delay_ms(100);
	
	LCD_BLK_Set();//�򿪱���
    delay_ms(100);

	//************* Start Initial Sequence **********//
	LCD_WR_REG(0x11); //Sleep out 
	delay_ms(120);              //Delay 120ms 
	//************* Start Initial Sequence **********// 
	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
	else LCD_WR_DATA8(0xA0);

	LCD_WR_REG(0x3A);			
	LCD_WR_DATA8(0x05);

	LCD_WR_REG(0xB2);			
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x0C); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x33); 
	LCD_WR_DATA8(0x33); 			

	LCD_WR_REG(0xB7);			
	LCD_WR_DATA8(0x35);

	LCD_WR_REG(0xBB);			
	LCD_WR_DATA8(0x32); //Vcom=1.35V
					
	LCD_WR_REG(0xC2);
	LCD_WR_DATA8(0x01);

	LCD_WR_REG(0xC3);			
	LCD_WR_DATA8(0x15); //GVDD=4.8V  ��ɫ���
				
	LCD_WR_REG(0xC4);			
	LCD_WR_DATA8(0x20); //VDV, 0x20:0v

	LCD_WR_REG(0xC6);			
	LCD_WR_DATA8(0x0F); //0x0F:60Hz        	

	LCD_WR_REG(0xD0);			
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1); 

	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0xD0);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x0E);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x31);   
	LCD_WR_DATA8(0x33);   
	LCD_WR_DATA8(0x48);   
	LCD_WR_DATA8(0x17);   
	LCD_WR_DATA8(0x14);   
	LCD_WR_DATA8(0x15);   
	LCD_WR_DATA8(0x31);   
	LCD_WR_DATA8(0x34);   

	LCD_WR_REG(0xE1);     
	LCD_WR_DATA8(0xD0);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x0E);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x15);   
	LCD_WR_DATA8(0x31);   
	LCD_WR_DATA8(0x33);   
	LCD_WR_DATA8(0x48);   
	LCD_WR_DATA8(0x17);   
	LCD_WR_DATA8(0x14);   
	LCD_WR_DATA8(0x15);   
	LCD_WR_DATA8(0x31);   
	LCD_WR_DATA8(0x34);
	LCD_WR_REG(0x21); 

	LCD_WR_REG(0x29);
    //add   ������Ļ��Ӱ
    LCD_Fill(0,0,LCD_W,LCD_H,BACKGROUND);

} 








