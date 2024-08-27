#include "gpio.h"      
/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned short i ; 
unsigned  int counter = 0x00;  
/*Activer l'horloge pour le Port D */
GPIO_ClockEnable(GPIO_D); 
/*re-intialiser les registers de port C */
GPIO_DeInit(GPIO_D); 
/*--- Configure PD12 et PD13 en mode Output Push pull */ 
GPIO_Init(GPIO_D,OUTPUT,PP,Pin12); 
GPIO_Init(GPIO_D,OUTPUT,PP,Pin13);

for(counter; counter< NOMBRE_BOUCLES ; counter++){

GPIO_WriteBit(GPIO_D, GPIO_PIN_12, 1) ;
GPIO_WriteBit(GPIO_D, GPIO_PIN_13, 1) ;


Delay(0x3FFFFF) ; 

GPIO_WriteBit(GPIO_D, GPIO_PIN_12, 0) ;
GPIO_WriteBit(GPIO_D, GPIO_PIN_13, 0) ;
Delay(0x3FFFFF) ;
}


while( 1 ) ; 
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--); 
}
