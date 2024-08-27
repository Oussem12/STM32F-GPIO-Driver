/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************

/*Includes ------------------------------------------------------------------*/
//les adress du GPIO : 

#define GPIO_A (unsigned int*)(0x40020000)
#define GPIO_B (unsigned int*)(0x40020400)
#define GPIO_C (unsigned int*)(0x40020800)
#define GPIO_D (unsigned int*)(0x40020C00)
#define GPIO_E (unsigned int*)(0x40021000)
#define GPIO_F (unsigned int*)(0x40021400)
#define GPIO_G (unsigned int*)(0x40021800)
#define GPIO_H (unsigned int*)(0x40021C00)
#define GPIO_I (unsigned int*)(0x40022000)
#define GPIO_J (unsigned int*)(0x40022400)
#define GPIO_K (unsigned int*)(0x40022800)


/* les offset  du Moder et ord et RCCENABL */


#define MODER   (0x00)/4
#define ODR     (0x14)/4
#define IDR     (0x10)/4
#define RCC     (0x30)/4
#define OTYPER  (0x04)/4
















/*  mode de fonctionnement : */
#define INPUT  0x00 // Mode d'entrée 00
#define OUTPUT 0x01 // Mode de sortie 01
#define AN     0x02// Mode analogique 10 
#define AF     0x03 // Mode alternatif 11



#define PP 0x00
#define OD 0X01
//tout les pins 
#define GPIO_PIN_0  ((unsigned short)0x0001)
#define GPIO_PIN_1  ((unsigned short)0x0002)
#define GPIO_PIN_2  ((unsigned short)0x0004)
#define GPIO_PIN_3  ((unsigned short)0x0008)
#define GPIO_PIN_4  ((unsigned short)0x0010)
#define GPIO_PIN_5  ((unsigned short)0x0020)
#define GPIO_PIN_6  ((unsigned short)0x0040)
#define GPIO_PIN_7  ((unsigned short)0x0080)
#define GPIO_PIN_8  ((unsigned short)0x0100)
#define GPIO_PIN_9  ((unsigned short)0x0200)
#define GPIO_PIN_10 ((unsigned short)0x0400)
#define GPIO_PIN_11 ((unsigned short)0x0800)
#define GPIO_PIN_12 ((unsigned short)0x1000)
#define GPIO_PIN_13 ((unsigned short)0x2000)
#define GPIO_PIN_14 ((unsigned short)0x4000)
#define GPIO_PIN_15 ((unsigned short)0x8000)

/* Nombre de pin */
#define Pin0   00
#define Pin1   01
#define Pin2   02
#define Pin3   03
#define Pin4   04
#define Pin5   05
#define Pin6   06
#define Pin7   07
#define Pin8   08
#define Pin9   09
#define Pin10  10
#define Pin11  11
#define Pin12  12
#define Pin13  13
#define Pin14  14
#define Pin15  15






/* -----------------ajouter les protopyes des fonctions----------------------*/


/* GPIO enable function */  
void GPIO_ClockEnable (unsigned int * gpio_x);

/* GPIO Resete function */

void GPIO_DeInit(unsigned int * gpio_x);
/* Config function */

void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);
/* Read functions */

unsigned short int GPIO_ReadInputData(unsigned int * gpio_x) ; 
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin);
/* Write functions */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal) ; 
/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/