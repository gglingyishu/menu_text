#include "lcd.h"
#include "menu2.h"

//extern const u8 TEXT_Buffer[]={"STM32F103 FLASH TEST"};
//extern SIZE sizeof(TEXT_Buffer);
//extern FLASH_SAVE_ADDR ;

#define PAGE_ID        Menu2//界面号和GG_MenuPageName对应 GG@
#define PAGE_SUMSIGN   6//总信号数，统计一下，怕溢出（包含第一个预留的NULL）

//主控框架结构体
extern GG_MENU_StateTypeDef g_MENU_MainSta;
//用户调用接口
static void GG_MENU_Show(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_Close(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_KeyUpdate(GG_MENUPAGE_TypeDef  *MENUx);
static void GG_MENU_Hide(GG_MENUPAGE_TypeDef  *MENUx);

static void GG_MENU_KeyUpdate(GG_MENUPAGE_TypeDef  *MENUx);
//用户修改添加回调和处理函数
static void GG_MenuDefShowCallback(void);//打开界面接口   GG@
static void GG_MenuDefCloseCallback(void);//关闭界面接口
static void GG_MenuDefHideCallback(void);//隐藏界面，任会做数据采集，数据处理等工作
static void GG_MenuSignChangeCallback(void);//信号转换，复杂界面如果信号差异量大可以做转换

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
	
} GG_KeySignSta;//当前界面总信号事件 GG@

typedef struct
{
    uint8_t sign;//信号
    void (*action)(void);//信号行为
    
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

static void GG_MenuDefShowCallback(void)//界面默认窗口
{
	u8 temp[2]={0x02,0x01};
		LCD_ShowChinese(80,48*0,"角度",BLACK,BACKGROUND,40,0);
    LCD_ShowStr(140,48*2+12,"N.m   ",BLUE,BACKGROUND);
		STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)temp,1);
	
}

static void GG_MenuDefCloseCallback(void)//界面默认窗口
{
		LCD_ALL_Clear();
    
}

static void GG_MenuDefHideCallback(void)
{
		LCD_ALL_Clear();

}

static void GG_MenuSignChangeCallback(void)
{
    if(g_MENU_MainSta.KeyLastSignSta > 100)//后台信号
        g_MENU_MainSta.KeyLastSignSta = g_MENU_MainSta.KeyLastSignSta % 100;
        
    
}

void GG_MENU2_Init(GG_MENUPAGE_TypeDef  *MENUx)
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

		MENU2.close(&MENU2);
		MENU3.show(&MENU3);    
}

static void KeyDownAction(void)
{
    printf("2-222\r\n");  
  
		MENU2.close(&MENU2);
		MENU3.show(&MENU3);
    
} 

static void KeySelectAction(void)
{
    printf("2-333\r\n");  
		MENU2.close(&MENU2);
		MENU3.show(&MENU3);	

} 
static void KeyModeAction(void)
{
    printf("2-444\r\n");   
	
 		MENU2.close(&MENU2);
		MENU3.show(&MENU3);

    
} 

static void KeyUpLongAction(void)
{
    printf("2-555\r\n");  
		MENU2.close(&MENU2);
		MENU3.show(&MENU3);
	
}







