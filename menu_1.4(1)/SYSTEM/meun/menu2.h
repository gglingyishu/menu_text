#ifndef __MENU2_H	
#define __MENU2_H	
#include "stm32f1xx.h"
#include "gg_menu.h"



//typedef struct
//{
//    uint8_t Menu_PowerSta;
//    
//    void (*keyupdate)();
//    void (*show)();
//    void (*hide)();
//    void (*close)();

//}GG_MENUPAGE_TypeDef;

//�����ӽ��� GG@
extern GG_MENUPAGE_TypeDef MENU1;
extern GG_MENUPAGE_TypeDef MENU2;
extern GG_MENUPAGE_TypeDef MENU3;

void GG_MENU2_Init(GG_MENUPAGE_TypeDef  *MENUx);




#endif
