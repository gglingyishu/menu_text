#ifndef __GG_MENU_H	
#define __GG_MENU_H	
#include "stm32f1xx.h"
#include "sys.h"

//���������ļ�����

#include "gg_menu.h"

#define BACKSTAGE_THREAD         1   //���û�н���������ʱ�����⴦����Թر�
#define MENU_SUMPAGE             3   //�ܽ����� GG@

//Ҫд�뵽STM32 FLASH���ַ�������

#define SIZE sizeof(TEXT_Buffer)		//���鳤��
#define FLASH_SAVE_ADDR  0X08070000		//����FLASH �����ַ(����Ϊż��������ֵҪ���ڱ�������ռ��FLASH�Ĵ�С+0X08000000)

typedef enum
{
  Menu1,
  Menu2,
	Menu3

} GG_MenuPageName;//�������ƶ�Ӧÿ�������PAGE_ID  GG@

typedef struct
{
    void (*sendSign)();//���ݽ����ź�
    void (*lastSignWork)();//��������
    void (*lastSign_ThreadWork)(GG_MenuPageName menu, int sign);//��̨�������¼������������������ʱ���Լ������������淢��ģ���ź�

}GG_MENU_TypeDef;//���������ܽӿ�

typedef enum
{
  CLOSE = 0,
  NORMAR_ON,
  HIDE

} GG_MenuWorkSta;//���浱ǰ״̬

typedef struct
{
    uint8_t Menu_PowerSta;//�����ϵ��־(ĿǰΪԤ����־)
    uint8_t KeyLastSignSta;//�����ź�ֵ
    uint8_t Menu_LastPage;//���½���   
    
}GG_MENU_StateTypeDef;

typedef struct GG_MENUPAGE_TypeDef
{
    uint8_t Menu_PowerSta;//����״̬��־ ��ӦGG_MenuWorkSta
    
    void (*keyupdate)();
    void (*show)();
    void (*hide)();
    void (*close)();

}GG_MENUPAGE_TypeDef;//�������

void GG_MENU_Init(GG_MENU_TypeDef  *MENUx);//��ʼ��
void GG_MENU_SendKeySign(int  keysignsta);//�źŽ���
void GG_MENU_LastSignWork(void);//�ź�֪ͨ����

void GG_MENU_BackThreadSignWork(GG_MenuPageName menu, int sign);//�����Ժ�̨�ź�֪ͨ����(���Ը��ݶ�ʱ��ʱ����ڶ�Ӧ��������)
void GG_MENU_MenuStaUpdate(uint8_t menu, uint8_t worksta);//�ź�֪ͨ����


#endif




