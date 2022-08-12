#include "gg_menu.h"
/*
*   ����: GG
*   ����: guotaoyuan1998@163.com
*   VX: qingya_1998
*   ��������: 22/07/20
*   ��������: 22/07/22
*   �汾: V1.4
*           ����˵��:
*           (BETA):�����˽��洫�ݺ��źŴ��ݷ����������            
*           (BETA):�޸���HIDE״̬�Ĵ���ʽ   
*           (BETA):�����˽��洫�ݺ��źŴ��ݷ���������� 
*           (V1.4):�����˲��ֵط�ע��,���󲿷�Ҫ��ֲ΢���Ĳ��ּ����ʶ GG@
*           (V1.4):�����ܣ���update�����������������źŻ���
*   ps: �ƻ��¸��汾���ݣ��ź����������� GG_MenuBobyHandle����������һ����ǰ����״ֵ̬�����߹��ѡ��ֵ
*                         �����жϹ��λ�ã����ӿ���ʵ�������˵��ȹ���
*       ʹ�÷�ʽ:   ����ϵͳ��ʼ�� -> �����ӽ����ʼ�� -> ��Ӧ�����߼������޸ģ������Ǳ�ʶ����
*/

//������������
extern GG_MENUPAGE_TypeDef MENU1;
extern GG_MENUPAGE_TypeDef MENU2;
extern GG_MENUPAGE_TypeDef MENU3;

static void Menu1Action(void);
static void Menu2Action(void);
static void Menu3Action(void);

GG_MENU_StateTypeDef g_MENU_MainSta={0};

typedef struct
{
    uint8_t page;//���� GG@
    void (*action)(void);//�����Ӧ���ܴ���
    uint8_t worksta;//���浱ǰ����״̬
    
} GG_MenuBobyHandle;

static GG_MenuBobyHandle s_menuBobyHandleMap[] = 
{
    {Menu1,Menu1Action,CLOSE},
    {Menu2,Menu2Action,CLOSE},
		{Menu3,Menu3Action,CLOSE},

};

void GG_MENU_Init(GG_MENU_TypeDef  *MENUx)
{
    MENUx->sendSign = GG_MENU_SendKeySign;  
    MENUx->lastSignWork = GG_MENU_LastSignWork; 
    MENUx->lastSign_ThreadWork = GG_MENU_BackThreadSignWork;   
    
}

static void Menu1Action(void)
{
    MENU1.keyupdate(&MENU1);
    
}

static void Menu2Action(void)
{   
    MENU2.keyupdate(&MENU2); 
    
} 

static void Menu3Action(void)
{   
    MENU3.keyupdate(&MENU3); 
    
} 

void GG_MENU_SendKeySign(int  keysignsta)
{
	 if(keysignsta!=0)
    g_MENU_MainSta.KeyLastSignSta = keysignsta;
      
}


void GG_MENU_LastSignWork(void)
{
//    uint8_t i;
#ifdef BACKSTAGE_THREAD
//    for(i=0; i < MENU_SUMPAGE; i++)�о�����Ϊɶ����Ԥ���Ű�
//    {
				 if(g_MENU_MainSta.KeyLastSignSta > 0)
				 {
//        if(s_menuBobyHandleMap[i].worksta != 0)
              s_menuBobyHandleMap[g_MENU_MainSta.Menu_LastPage].action();
				 }
//            
//    }
    
#else    
    s_menuBobyHandleMap[g_MENU_MainSta.Menu_LastPage].action();
#endif

 
}

void GG_MENU_MenuStaUpdate(uint8_t menu, uint8_t worksta)
{
    if(menu < MENU_SUMPAGE)
        s_menuBobyHandleMap[menu].worksta = worksta;

}

void GG_MENU_BackThreadSignWork(GG_MenuPageName menu, int sign)
{
    if(s_menuBobyHandleMap[menu].worksta != CLOSE)
    {
        g_MENU_MainSta.KeyLastSignSta = sign;
        s_menuBobyHandleMap[menu].action();
    }

}













