#include "lcd.h"
#include "menu3.h"

//extern const u8 TEXT_Buffer[]={"STM32F103 FLASH TEST"};
//extern SIZE sizeof(TEXT_Buffer);
//extern FLASH_SAVE_ADDR ;

#define PAGE_ID        Menu3//����ź�GG_MenuPageName��Ӧ GG@
#define PAGE_SUMSIGN   6//���ź�����ͳ��һ�£��������������һ��Ԥ����NULL��

//���ؿ�ܽṹ��
extern GG_MENU_StateTypeDef g_MENU_MainSta;
//�û����ýӿ�
static void GG_MENU_Show(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_Close(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_KeyUpdate(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_Hide(GG_MENUPAGE_TypeDef  *MENUx);

static void GG_MENU_KeyUpdate(GG_MENUPAGE_TypeDef  *MENUx);
//�û��޸���ӻص��ʹ�����
static void GG_MenuDefShowCallback(void);//�򿪽���ӿ�   GG@
static void GG_MenuDefCloseCallback(void);//�رս���ӿ�
static void GG_MenuDefHideCallback(void);//���ؽ��棬�λ������ݲɼ������ݴ���ȹ���
static void GG_MenuSignChangeCallback(void);//�ź�ת�������ӽ�������źŲ������������ת��

static void KeyUpLongAction(void);
static void KeyUpAction(void);
static void KeyDownAction(void);
static void KeySelectAction(void);
static void KeyModeAction(void);

typedef enum
{
  KEY_UP = 1,
  KEY_DOWN,
  KEY_SELECT,
	KEY_MODE,
	KEY_UP_LONG
	
} GG_KeySignSta;//��ǰ�������ź��¼� GG@

typedef struct
{
    uint8_t sign;//�ź�
    void (*action)(void);//�ź���Ϊ
    
} GG_MenuBobyHandle;

static const GG_MenuBobyHandle s_menuBobyHandleMap[] = 
{
    {NULL,NULL},
    {KEY_UP,KeyUpAction},
    {KEY_DOWN,KeyDownAction},
    {KEY_SELECT,KeySelectAction},
		{KEY_MODE,KeyModeAction},
		{KEY_UP_LONG,KeyUpLongAction},

};

static void GG_MenuDefShowCallback(void)//����Ĭ�ϴ���
{
	u8 temp[2]={0x04,0x01};
			LCD_ShowChinese(80,48*0,"Ŀ��",BLACK,BACKGROUND,40,0);
			LCD_ShowString(150,48*3,"II",BLUE,BACKGROUND,48,0);
			LCD_ShowString(60,48*3,"I",BLUE,BACKGROUND,48,0);
		  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)temp,1);
			
	
}

static void GG_MenuDefCloseCallback(void)//����Ĭ�ϴ���
{
		LCD_ALL_Clear();
    
}

static void GG_MenuDefHideCallback(void)
{
		LCD_ALL_Clear();

}

static void GG_MenuSignChangeCallback(void)
{
    if(g_MENU_MainSta.KeyLastSignSta > 100)//��̨�ź�
        g_MENU_MainSta.KeyLastSignSta = g_MENU_MainSta.KeyLastSignSta % 100;
        
    
}

void GG_MENU3_Init(GG_MENUPAGE_TypeDef  *MENUx)
{
    MENUx->close = GG_MENU_Close;
    MENUx->keyupdate = GG_MENU_KeyUpdate;
    MENUx->show = GG_MENU_Show;
    MENUx->hide = GG_MENU_Hide;

}

static void GG_MENU_Show(GG_MENUPAGE_TypeDef  *MENUx)
{
    g_MENU_MainSta.Menu_LastPage = PAGE_ID;
    MENUx->Menu_PowerSta = NORMAR_ON;
    GG_MenuDefShowCallback();     
#ifdef BACKSTAGE_THREAD    
    GG_MENU_MenuStaUpdate(PAGE_ID, NORMAR_ON);
#endif

}

static void GG_MENU_Hide(GG_MENUPAGE_TypeDef  *MENUx)
{
    MENUx->Menu_PowerSta = HIDE;
    GG_MenuDefHideCallback();
#ifdef BACKSTAGE_THREAD    
    GG_MENU_MenuStaUpdate(PAGE_ID, HIDE);
#endif

}

static void GG_MENU_Close(GG_MENUPAGE_TypeDef  *MENUx)
{
    if(PAGE_ID == g_MENU_MainSta.Menu_LastPage)
        g_MENU_MainSta.Menu_LastPage = 0;
    MENUx->Menu_PowerSta = CLOSE;
    GG_MenuDefCloseCallback();
#ifdef BACKSTAGE_THREAD    
    GG_MENU_MenuStaUpdate(PAGE_ID, CLOSE);
#endif
}

static void GG_MENU_KeyUpdate(GG_MENUPAGE_TypeDef  *MENUx)
{
    if((MENUx->Menu_PowerSta != CLOSE)&&(g_MENU_MainSta.KeyLastSignSta % 100 < PAGE_SUMSIGN))
    {
        if((NORMAR_ON == MENUx->Menu_PowerSta)||(g_MENU_MainSta.KeyLastSignSta > 100))
        {
            GG_MenuSignChangeCallback();
            s_menuBobyHandleMap[g_MENU_MainSta.KeyLastSignSta].action();   
        }
    }
    g_MENU_MainSta.KeyLastSignSta = 0;
  
}


static void KeyUpAction(void)
{
    printf("2-111\r\n");

  
    
}

static void KeyDownAction(void)
{
    printf("2-222\r\n");  
  

    
} 

static void KeySelectAction(void)
{
    printf("2-333\r\n");   

} 
static void KeyModeAction(void)
{
    printf("2-444\r\n");   
		MENU3.close(&MENU3);
		MENU1.show(&MENU1);
	
} 

static void KeyUpLongAction(void)
{
    printf("2-555\r\n");  
		MENU3.close(&MENU3);
		MENU1.show(&MENU1);
	
}








