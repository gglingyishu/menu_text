#ifndef __PIC_H
#define __PIC_H

//��ת 48*48
const unsigned char pic_1[276] = { /*0X00,0X01,0X30,0X00,0X2D,0X00,*/
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X78,0X00,0X00,0X00,0X00,
0X01,0XF8,0X00,0X00,0X00,0X00,0X07,0XF8,0X00,0X00,0X00,0X00,0X1F,0XFF,0X00,0X00,
0X00,0X00,0X0F,0XFF,0XC0,0X00,0X00,0X06,0X07,0XFF,0XE0,0X00,0X00,0X0F,0X01,0XFF,
0XF8,0X00,0X00,0X0F,0X80,0XF7,0XFC,0X00,0X00,0X1F,0X80,0X71,0XFE,0X00,0X00,0X3F,
0X00,0X10,0X7F,0X00,0X00,0X7E,0X00,0X00,0X3F,0X00,0X00,0X7C,0X00,0X00,0X1F,0X80,
0X00,0XFC,0X00,0X00,0X0F,0XC0,0X00,0XF8,0X00,0X00,0X07,0XC0,0X00,0XF8,0X00,0X00,
0X07,0XE0,0X01,0XF0,0X00,0X00,0X03,0XE0,0X01,0XF0,0X00,0X00,0X01,0XF0,0X01,0XF0,
0X00,0X00,0X01,0XF0,0X01,0XF0,0X00,0X00,0X00,0XC0,0X01,0XE0,0X00,0X00,0X00,0X00,
0X01,0XE0,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,
0X00,0X00,0X01,0XEC,0X00,0X00,0X00,0X00,0X01,0XFC,0X00,0X00,0X00,0X40,0X01,0XFC,
0X00,0X00,0X01,0XC0,0X0F,0XFC,0X00,0X00,0X0F,0XC0,0X07,0XFC,0X00,0X00,0X7F,0XC0,
0X03,0XF8,0X00,0X00,0X7F,0XC0,0X01,0XF8,0X00,0X00,0X3F,0XC0,0X00,0XF8,0X00,0X00,
0X7F,0X80,0X00,0X38,0X00,0X00,0XFF,0X80,0X00,0X18,0X00,0X07,0XFF,0X80,0X00,0X08,
0X7F,0XFF,0XFB,0X80,0X00,0X00,0X7F,0XFF,0XF0,0X80,0X00,0X00,0X7F,0XFF,0XC0,0X00,
0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

//��ת48*48
const unsigned char pic_2[276] = { 
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,0X00,
0X1F,0X80,0X00,0X00,0X00,0X00,0X1F,0XE0,0X00,0X00,0X00,0X00,0XFF,0XF8,0X00,0X00,
0X00,0X03,0XFF,0XF0,0X00,0X00,0X00,0X07,0XFF,0XE0,0X60,0X00,0X00,0X1F,0XFF,0X80,
0XF0,0X00,0X00,0X3F,0XEF,0X01,0XF0,0X00,0X00,0X7F,0X8E,0X01,0XF8,0X00,0X00,0XFE,
0X08,0X00,0XFC,0X00,0X00,0XFC,0X00,0X00,0X7E,0X00,0X01,0XF8,0X00,0X00,0X3E,0X00,
0X03,0XF0,0X00,0X00,0X3F,0X00,0X03,0XE0,0X00,0X00,0X1F,0X00,0X07,0XE0,0X00,0X00,
0X1F,0X00,0X07,0XC0,0X00,0X00,0X0F,0X80,0X0F,0X80,0X00,0X00,0X0F,0X80,0X0F,0X80,
0X00,0X00,0X0F,0X80,0X03,0X00,0X00,0X00,0X0F,0X80,0X00,0X00,0X00,0X00,0X07,0X80,
0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,
0X07,0X80,0X00,0X00,0X00,0X00,0X37,0X80,0X02,0X00,0X00,0X00,0X3F,0X80,0X03,0X80,
0X00,0X00,0X3F,0X80,0X03,0XF0,0X00,0X00,0X3F,0XF0,0X03,0XFE,0X00,0X00,0X3F,0XE0,
0X03,0XFE,0X00,0X00,0X1F,0XC0,0X03,0XFC,0X00,0X00,0X1F,0X80,0X01,0XFE,0X00,0X00,
0X1F,0X00,0X01,0XFF,0X00,0X00,0X1C,0X00,0X01,0XFF,0XE0,0X00,0X18,0X00,0X01,0XDF,
0XFF,0XFE,0X10,0X00,0X01,0X0F,0XFF,0XFE,0X00,0X00,0X00,0X03,0XFF,0XFE,0X00,0X00,
0X00,0X00,0XFF,0XFF,0X00,0X00,0X00,0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

//��˨  96*32
const unsigned char pic_3[384] =  { /* 0X00,0X01,0X5E,0X00,0X20,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X10,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3A,0X1C,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X31,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFE,0X00,0X00,0X00,0X1F,0XFF,0X86,0XEC,0X4C,0XDC,0X88,0X88,0X00,0X00,0X00,
0X00,0X40,0X07,0X02,0X67,0X76,0X6C,0XCE,0XE8,0X31,0X00,0X00,0X00,0X10,0X07,0X03,
0X66,0X67,0X6E,0XEC,0XEE,0X22,0X88,0X00,0X00,0X00,0X06,0X03,0X66,0X66,0X6E,0XEC,
0XEE,0X24,0X18,0X00,0X00,0X20,0X06,0X00,0X14,0X02,0X22,0XAA,0XA6,0X2C,0X98,0X00,
0X00,0X00,0X06,0X00,0X15,0X00,0X02,0XA8,0XE2,0X18,0X00,0X00,0X00,0X00,0X06,0X00,
0X14,0X20,0X00,0X02,0XAA,0X00,0X00,0X00,0X00,0X00,0X06,0X03,0X37,0X54,0X40,0X06,
0XEE,0X3E,0X80,0X00,0X00,0X00,0X06,0X03,0X33,0X76,0X66,0X66,0X6E,0X20,0X00,0X00,
0X00,0X00,0X06,0X03,0XB3,0X76,0X76,0X66,0X6E,0X20,0X00,0X00,0X00,0X00,0X07,0X03,
0X33,0X77,0X66,0X66,0X6E,0X32,0X00,0X00,0X00,0X00,0X07,0X03,0XF3,0X76,0X76,0X66,
0X6E,0X2E,0X00,0X00,0X00,0X00,0X07,0X07,0XBB,0XFF,0XFF,0X77,0X76,0X22,0X00,0X00,
0X00,0X00,0X07,0XFD,0XFB,0XBF,0XFF,0X77,0X76,0X00,0X00,0X00,0X00,0X00,0X07,0XFD,
0XFB,0XBB,0XBB,0XFF,0X76,0X1C,0X18,0X00,0X00,0X00,0X07,0XF9,0X33,0X33,0X37,0X7E,
0X66,0X20,0X18,0X00,0X00,0X5F,0XFF,0XFD,0XB3,0XBA,0X33,0X77,0X76,0X22,0X08,0X00,
0X00,0X5F,0XF8,0X05,0X56,0X62,0X22,0XE6,0XC4,0X04,0X00,0X00,0X00,0X1F,0XF8,0X0F,
0XFF,0XFF,0XFF,0XFF,0XEC,0X00,0X00,0X00,0X00,0X3F,0XF8,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X3F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X1F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};

//��˨  144*48
const unsigned char gImage_2[864] = { /* 0X00,0X01,0X8D,0X00,0X30,0X00, */
0X0F,0XFF,0XD0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X0C,0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X1F,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X10,0X00,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X38,0X00,0X04,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFC,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X38,0X00,0X03,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X5F,0XFF,
0XFF,0XFC,0X1C,0X30,0XE1,0X83,0X0E,0X38,0X70,0X41,0X9B,0XFF,0XFF,0XFF,0XFC,0X00,
0X50,0X00,0X07,0XF8,0X0E,0X58,0XE2,0XC7,0X97,0X2C,0X78,0XE3,0XC7,0X70,0X20,0X00,
0X10,0X00,0X5F,0XFF,0XFF,0XFF,0XCE,0XDD,0X72,0XEF,0XD7,0X4E,0XB9,0X72,0XE5,0XC0,
0X30,0X7C,0X10,0X00,0X48,0X00,0X03,0XE0,0X0F,0X9F,0X7C,0XEB,0XE7,0XCE,0XBD,0X7C,
0XE9,0XD0,0X70,0XFE,0X10,0X00,0X4F,0XFF,0XFF,0XE0,0X0F,0XDE,0XFC,0XF7,0XF7,0XEF,
0X1E,0XFC,0XFD,0XD0,0X70,0XE6,0X30,0X00,0X08,0X00,0X03,0XC0,0X0F,0X9F,0X7E,0XF9,
0XF7,0XCF,0X9F,0X3E,0XF9,0XF0,0X71,0XC6,0X30,0X00,0X98,0X00,0X03,0XC0,0X0F,0X9E,
0X7C,0XF5,0XE7,0XCF,0X1E,0X3C,0XFD,0XF0,0X33,0X86,0X38,0X00,0X90,0X00,0X07,0XC0,
0X0B,0XDE,0X7E,0XF9,0XF7,0XEF,0X9F,0X3C,0XF9,0XF0,0X3F,0X86,0X38,0X00,0X90,0X00,
0X03,0X80,0X04,0X97,0X0C,0X91,0X61,0XCB,0X16,0X3C,0X99,0XF0,0X1F,0X06,0X78,0X00,
0XA0,0X00,0X07,0X80,0X05,0X96,0X34,0XB1,0XA3,0X4D,0X13,0X3C,0XF9,0X30,0X04,0X00,
0X7C,0X00,0XA0,0X00,0X07,0X80,0X07,0X9E,0X2C,0XD1,0X22,0XCD,0X96,0X2C,0X49,0XD0,
0X00,0X00,0X34,0X00,0XA0,0X00,0X07,0X80,0X04,0X9A,0X2C,0X99,0X63,0XCB,0X9A,0X3C,
0X59,0X30,0X3F,0XE4,0X30,0X00,0XA0,0X00,0X07,0X80,0X05,0X92,0X34,0XE9,0XA3,0X4C,
0X93,0X24,0X79,0X70,0X3F,0XEE,0X30,0X00,0X80,0X00,0X07,0X80,0X04,0X8A,0X24,0X99,
0X22,0XC5,0X97,0X2C,0X49,0X90,0X3F,0XE6,0X30,0X00,0X80,0X00,0X07,0X80,0X07,0X8E,
0X3C,0XF9,0XE3,0XC7,0X9F,0X3C,0X79,0XF0,0X00,0X00,0X30,0X00,0X80,0X00,0X07,0X80,
0X07,0X8E,0X3C,0XF9,0XE3,0XC7,0X9F,0X3C,0X78,0XF0,0X00,0X00,0X30,0X00,0XC0,0X00,
0X07,0X80,0X07,0X8E,0X3C,0X79,0XE3,0XC7,0X8F,0X3C,0X7C,0XF0,0X30,0X60,0X30,0X00,
0XC0,0X00,0X07,0X80,0X07,0XCE,0X3E,0X79,0XE3,0XE7,0X8F,0X1E,0X7C,0XF0,0X3C,0X60,
0X30,0X00,0XC0,0X00,0X07,0XC0,0X07,0X8E,0X3C,0X79,0XF3,0XE7,0X8F,0X9F,0X7C,0XF0,
0X3E,0X60,0X30,0X00,0X80,0X00,0X07,0XC0,0X07,0X8E,0X3C,0X78,0XF1,0XE7,0X8F,0X1E,
0X7C,0XF0,0X37,0XE0,0X30,0X00,0XA0,0X00,0X07,0XC0,0X0F,0X8F,0XBE,0X7C,0XF9,0XF7,
0XCF,0X9F,0X7E,0XF0,0X33,0XE0,0X30,0X00,0XA0,0X00,0X07,0XE0,0X17,0XCF,0X1E,0X7C,
0XF1,0XE7,0XCF,0X1E,0X7E,0XF0,0X31,0XE0,0X30,0X00,0XA0,0X00,0X07,0XFF,0XFB,0XEF,
0X9F,0X7E,0XFD,0XF7,0XEF,0X9F,0X3E,0XF0,0X30,0X60,0X30,0X00,0XA0,0X00,0X07,0XF0,
0X1B,0XFF,0XDF,0X7E,0XFD,0XFF,0XEF,0XDF,0XBE,0XF0,0X00,0X00,0X30,0X00,0XA0,0X00,
0X07,0XFF,0XFB,0XFF,0XDF,0X7E,0XFD,0XFB,0XEF,0XDF,0XBF,0XF0,0X07,0X00,0X74,0X00,
0XB0,0X00,0X07,0XFC,0X0B,0XFF,0XDF,0XFE,0XFD,0XFB,0XFF,0XDF,0XBF,0XF0,0X1F,0XC0,
0X7C,0X00,0X90,0X00,0X07,0XFF,0XFB,0XFF,0XDF,0XFE,0XFD,0XFB,0XFF,0XFF,0XBF,0XF0,
0X3F,0XE0,0X78,0X00,0X90,0X00,0X07,0XFF,0XFB,0XF7,0XDF,0XFE,0XFD,0XFB,0XFF,0XFF,
0XBF,0XF0,0X33,0X60,0X38,0X00,0X88,0X00,0X07,0XFF,0XF3,0XD7,0X1E,0XFC,0XF1,0XE3,
0XD7,0XBE,0XBD,0X70,0X63,0X30,0X38,0X00,0X48,0X04,0X87,0XFF,0XFB,0XC7,0X9F,0X7C,
0XF9,0XF3,0XE7,0X8F,0X3C,0X70,0X63,0X70,0X30,0X00,0X4F,0XFF,0XFF,0XFF,0XFB,0XE7,
0X5F,0X3E,0XFD,0XF3,0XA7,0X4F,0X3E,0X70,0X63,0XE0,0X10,0X00,0X4F,0XFF,0XFC,0X00,
0X0B,0X96,0X7C,0XB2,0XE5,0XDB,0XB7,0X6C,0XBA,0X70,0X33,0XC0,0X10,0X00,0X5F,0XFF,
0XFC,0X00,0X0F,0X96,0X38,0XF1,0XE3,0X8B,0X1E,0X2C,0XF9,0X60,0X03,0X00,0X10,0X00,
0X5F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE8,0XC3,0X87,0X0E,0X18,0X71,0XE0,0X00,0X00,
0X10,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF8,0X00,0X3F,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFC,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFC,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
// //��˨ͷ  32*32
//const unsigned char pic_4[108] = { /* 0X00,0X01,0X20,0X00,0X1B,0X00, */
//0X00,0XFF,0XFF,0X00,0X01,0X18,0X18,0X80,0X01,0X40,0X02,0X80,0X02,0X80,0X01,0XC0,
//0X06,0X00,0X00,0X60,0X04,0X00,0X00,0X20,0X0C,0X00,0X00,0X30,0X08,0X78,0X20,0X10,
//0X18,0X2D,0X28,0X08,0X10,0X3A,0XA8,0X0C,0X30,0X2E,0XA8,0X0C,0X50,0X79,0XBC,0X02,
//0X40,0X00,0X00,0X02,0X80,0X00,0X00,0X01,0X40,0X00,0X00,0X02,0X71,0XE0,0X04,0X02,
//0X31,0X0A,0X8C,0X8C,0X13,0X0D,0X55,0X8C,0X19,0X29,0X55,0X08,0X08,0XED,0XDD,0X90,
//0X0C,0X00,0X00,0X30,0X06,0X00,0X00,0X20,0X03,0X00,0X00,0X60,0X02,0X80,0X01,0XC0,
//0X01,0X60,0X02,0X80,0X01,0X1C,0X18,0X80,0X00,0XFF,0XFF,0X00};


 //��˨ͷ  48*48
const unsigned char pic_4[288] = { /* 0X00,0X01,0X30,0X00,0X2A,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,
0XF8,0X00,0X00,0X18,0X7C,0X3E,0X18,0X00,0X00,0X31,0XC0,0X03,0X8C,0X00,0X00,0X37,
0X00,0X00,0X6C,0X00,0X00,0X6C,0X00,0X00,0X36,0X00,0X00,0X58,0X00,0X00,0X0A,0X00,
0X00,0XE0,0X00,0X00,0X07,0X00,0X00,0XC0,0X00,0X00,0X03,0X00,0X01,0XC0,0X00,0X06,
0X01,0X80,0X01,0XBF,0X00,0X06,0X01,0XC0,0X03,0X31,0X80,0X06,0X30,0XC0,0X07,0X31,
0X87,0XC6,0X7C,0X60,0X06,0X3F,0X0C,0XE6,0X30,0X60,0X0E,0X3F,0X98,0X66,0X30,0X30,
0X0C,0X31,0XD8,0X66,0X30,0X30,0X1C,0X31,0XDC,0X66,0X30,0X38,0X1C,0X3F,0X8F,0XC6,
0X3C,0X18,0X38,0X3C,0X03,0X06,0X1C,0X1C,0X28,0X00,0X00,0X00,0X00,0X14,0X68,0X00,
0X00,0X00,0X00,0X16,0X48,0X00,0X00,0X00,0X00,0X12,0XC8,0X00,0X00,0X00,0X00,0X13,
0XC8,0X7C,0X00,0X00,0XC0,0X13,0X48,0XFC,0X00,0X00,0XC0,0X12,0X69,0X80,0X13,0X02,
0XC3,0X16,0X2B,0X00,0XF7,0XCF,0XCF,0X94,0X3B,0X1C,0XC0,0XCC,0XCC,0XDC,0X1F,0X0C,
0XC7,0XD8,0XDF,0XD8,0X1D,0X8C,0XCC,0XD8,0XC8,0X38,0X0D,0XCC,0XCC,0XCD,0XCC,0X30,
0X0E,0XFC,0XC7,0XC7,0XC7,0XB0,0X06,0X00,0X00,0X00,0X00,0X60,0X03,0X00,0X00,0X00,
0X00,0X60,0X03,0X00,0X00,0X00,0X00,0XC0,0X01,0X80,0X00,0X00,0X01,0X80,0X01,0XC0,
0X00,0X00,0X01,0X80,0X00,0XC0,0X00,0X00,0X03,0X00,0X00,0XE0,0X00,0X00,0X07,0X00,
0X00,0X58,0X00,0X00,0X0A,0X00,0X00,0X6C,0X00,0X00,0X36,0X00,0X00,0X37,0X00,0X00,
0X6C,0X00,0X00,0X31,0XC0,0X03,0X8C,0X00,0X00,0X18,0X7C,0X3E,0X18,0X00,0X00,0X1F,
0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

//0
const unsigned char Image_angle[280] = { /* 0X00,0X01,0X30,0X00,0X30,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF0,0X00,0X00,0X00,0X07,
0XFC,0X00,0X00,0X00,0X0E,0X0E,0X00,0X00,0X00,0X1C,0X07,0X00,0X00,0X00,0X18,0X03,
0X00,0X00,0X00,0X38,0X03,0X00,0X00,0X00,0X30,0X03,0X00,0X00,0X00,0X30,0X03,0X00,
0X00,0X00,0X38,0X03,0X00,0X00,0X00,0X18,0X03,0X00,0X00,0X00,0X1C,0X07,0X00,0X00,
0X00,0X0E,0X0E,0X00,0X00,0X00,0X07,0XFC,0X00,0X00,0X00,0X03,0XF0,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

//��
const unsigned char gImage_dusu[200] = { /* 0X00,0X01,0X24,0X00,0X24,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0C,0X00,0X00,
0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X38,0X00,0X00,0X00,
0X00,0X70,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X01,
0XC0,0X00,0X00,0X00,0X03,0X80,0X00,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X0E,0X00,
0X00,0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0X38,0X00,0X00,
0X00,0X00,0X70,0X00,0X00,0X00,0X00,0X70,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,0X00,
0X01,0XC0,0X00,0X00,0X00,0X03,0X80,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X07,
0X00,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0X1C,0X00,
0X00,0X00,0X00,0X38,0X00,0X00,0X00,0X00,0X70,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,
0X00,0X00,0XC0,0X00,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFC,0X00,
0X07,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};
#endif


