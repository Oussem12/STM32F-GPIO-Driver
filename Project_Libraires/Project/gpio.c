
/* Includes ------------------------------------------------------------------*/ 
#include "gpio.h"
// Ajouter define pour RCC clock 
volatile unsigned short int *RCC_AHB1ENR = (unsigned short int *) 0x40023830; 
// Ajouter define pour RCC  reste 
volatile unsigned short int *RCC_AHB1RST= (unsigned short int *) 0x40023810;  
/**
  * @brief  Enable the gpio_x peripheral clock.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{
 if (gpio_x == GPIO_A) 
 {
 *RCC_AHB1ENR |= (1 << 0);
 }
 else if (gpio_x == GPIO_B)
 {
 *RCC_AHB1ENR |= (1 << 1);
 }

 else if (gpio_x == GPIO_C)
 {
  *RCC_AHB1ENR |= (1 << 2);
 }
 else if (gpio_x == GPIO_D) {
  *RCC_AHB1ENR |= (1 << 3);
} else if (gpio_x == GPIO_E) {
  *RCC_AHB1ENR |= (1 << 4);
} else if (gpio_x == GPIO_F) {
    *RCC_AHB1ENR |= (1 << 5);
} else if (gpio_x == GPIO_G) {
    *RCC_AHB1ENR |= (1 << 6);
} else if (gpio_x == GPIO_H) {
    *RCC_AHB1ENR |= (1 << 7);
} else if (gpio_x == GPIO_I) {
    *RCC_AHB1ENR |= (1 << 8);
} else if (gpio_x == GPIO_J) {
    *RCC_AHB1ENR |= (1 << 9);
} else {
  if(gpio_x == GPIO_K){
    
     *RCC_AHB1ENR |= (1 << 10);
} 
}
}




/**
* @brief Deinitializes the gpio_x peripheral registers to their default reset values.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval None
*/
void GPIO_DeInit(unsigned int * gpio_x)
 {
    if (gpio_x == GPIO_A) 
 {
    *RCC_AHB1RST |= (1 << 0);
    *RCC_AHB1RST &= ~(1 << 0);
 }
 else if (gpio_x == GPIO_B)
 {
    *RCC_AHB1RST |= (1 << 1);
    *RCC_AHB1RST &= ~(1 << 1);
 }

 else if (gpio_x == GPIO_C)
 {
    *RCC_AHB1RST |= (1 << 2);
    *RCC_AHB1RST &= ~(1 << 2);
 }
 else if (gpio_x == GPIO_D) {
    *RCC_AHB1RST |= (1 << 3);
    *RCC_AHB1RST &= ~(1 << 3);
} else if (gpio_x == GPIO_E) {
    *RCC_AHB1RST |= (1 << 4);
    *RCC_AHB1RST &= ~(1 << 4);
} else if (gpio_x == GPIO_F) {
    *RCC_AHB1RST |= (1 << 5);
    *RCC_AHB1RST &= ~(1 << 5);
} else if (gpio_x == GPIO_G) {
    *RCC_AHB1RST |= (1 << 6);
    *RCC_AHB1RST &= ~(1 << 6);
} else if (gpio_x == GPIO_H) {
    *RCC_AHB1RST |= (1 << 7);
    *RCC_AHB1RST &= ~(1 << 7);
} else if (gpio_x == GPIO_I) {
    *RCC_AHB1RST |= (1 << 8);
    *RCC_AHB1RST &= ~(1 << 8);
} else if (gpio_x == GPIO_J){
    *RCC_AHB1RST |= (1 << 9);
    *RCC_AHB1RST &= ~(1 << 9);
} else {
  if(gpio_x == GPIO_K){
    
     *RCC_AHB1RST |= (1 << 10);
     *RCC_AHB1RST &= ~(1 << 10);
} 
}
   
   
   
   
   
 }












/**
* @brief Configure the gpio_x
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param Mode: can be INPUT, OUTPUT, AF or AN
* @param typeOutput: can be PP or OD
* @param pin: can be 0...15
* @retval None
*/


void GPIO_Init(unsigned int *gpio_x, char Mode, char typeOutput, short int pin) {
    unsigned int mask =~(0x03 << ( pin *2)); 
    unsigned int   mask2 =~(0x01 << ( pin *2) ); 
    *(gpio_x + MODER)&= mask ; 
    *(gpio_x + MODER) |=(Mode <<( pin *2)); 

    if(typeOutput==PP){
    *(gpio_x +OTYPER )&= mask2 ; 
    }else{
      *(gpio_x + OTYPER)|=  ~ mask2 ;
      
    }

}













































/**
* @brief Sets or clears the selected data port bit.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to be written.
* This parameter can be one of GPIO_Pin_x where x can be (0..15).
* @param BitVal: specifies the value to be written to the selected bit.
* This parameter can be one of the BitAction enum values:
* @arg Bit_RESET: to clear the port pin
* @arg Bit_SET: to set the port pin
* @retval None
*/
void GPIO_WriteBit(unsigned int *gpio_x, unsigned short int GPIO_Pin, char BitVal) {

  if( BitVal != 0 ){
  * (gpio_x + ODR) |= GPIO_Pin ;  
  }else{
   *(gpio_x + ODR) &=~  GPIO_Pin ;   
  
  }
  
       
    }








/**
* @brief Writes data to the specified GPIO data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param PortVal: specifies the value to be written to the port output data register.
* @retval None
*/
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal){

     unsigned  char mask = ~ (0xFFFF) ; 
     *(gpio_x + ODR ) &=  mask  ; 
     *(gpio_x + ODR ) |= PortVal ; 

}














/**
* @brief Reads the specified GPIO input data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval GPIO input data port value.
*/
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x){



return *(gpio_x + IDR) ; 
}



/**
* @brief Reads the specified input port pin.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to read.
* This parameter can be GPIO_Pin_x where x can be (0..15).
* @retval The input port pin value.
*/
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)
{
return *(gpio_x + GPIO_Pin +  IDR) ;
}









