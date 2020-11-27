/******************************************************************************/
#ifndef MEMORY_H
#include "MEMORY.h"
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
#define PORT_ERROR 0X00
/******************************************************************************/
/* --------  Micro-controller C/C's ------- */
typedef enum{
        PIN_OUTPUT = 0,
        PIN_INPUT
}Pin_Direction_State_t;
typedef enum{
        PIN_LOW = 0,
        PIN_HIGH
}Pin_Value_State_t;
typedef enum{
        PORT_OUTPUT = 0X00,
        PORT_INPUT = 0XFF
}Port_Direction_State_t;
typedef struct{
        Pin_Direction_State_t Pin0 : 1;
        Pin_Direction_State_t Pin1 : 1;
        Pin_Direction_State_t Pin2 : 1;
        Pin_Direction_State_t Pin3 : 1;
        Pin_Direction_State_t Pin4 : 1;
        Pin_Direction_State_t Pin5 : 1;
        Pin_Direction_State_t Pin6 : 1;
        Pin_Direction_State_t Pin7 : 1;
}Pin_Direction_t;
typedef struct{
        Pin_Value_State_t Pin0 : 1;
        Pin_Value_State_t Pin1 : 1;
        Pin_Value_State_t Pin2 : 1;
        Pin_Value_State_t Pin3 : 1;
        Pin_Value_State_t Pin4 : 1;
        Pin_Value_State_t Pin5 : 1;
        Pin_Value_State_t Pin6 : 1;
        Pin_Value_State_t Pin7 : 1;
}Pin_Value_t;
/******************************************************************************/
void GPIO_SetPinDirection(const GPIO_Port_ID_t GPIO_PORT_ID,
                          const GPIO_Pin_ID_t GPIO_PIN_ID,
                          const GPIO_Direction_t GPIO_PIN_DIRECTION){

     volatile Pin_Direction_t* Pin_Direction_Ptr;
     switch(GPIO_PORT_ID){
            case GPIO_PORTA:
                 Pin_Direction_Ptr = (volatile Pin_Direction_t*)PORTA_DIRECTION_ADDRESS;
                 break;
            case GPIO_PORTB:
                 Pin_Direction_Ptr = (volatile Pin_Direction_t*)PORTB_DIRECTION_ADDRESS;
                 break;
            case GPIO_PORTC:
                 Pin_Direction_Ptr = (volatile Pin_Direction_t*)PORTC_DIRECTION_ADDRESS;
                 break;
            case GPIO_PORTD:
                 Pin_Direction_Ptr = (volatile Pin_Direction_t*)PORTD_DIRECTION_ADDRESS;
                 break;
            case GPIO_PORTE:
                 Pin_Direction_Ptr = (volatile Pin_Direction_t*)PORTE_DIRECTION_ADDRESS;
                 break;
            default:
                 /* Error: Undefined Port */
                 return;
     }
     switch(GPIO_PIN_ID){
            case GPIO_PIN0:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin0 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin0 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin0 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN1:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin1 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin1 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin1 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN2:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin2 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin2 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin2 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN3:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin3 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin3 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin3 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN4:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin4 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin4 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin4 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN5:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin5 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin5 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin5 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN6:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin6 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin6 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin6 = PIN_INPUT;
                 }
                 break;
            case GPIO_PIN7:
                 if(GPIO_OUTPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin7 = PIN_OUTPUT;
                 }else if(GPIO_INPUT == GPIO_PIN_DIRECTION){
                    Pin_Direction_Ptr->Pin7 = PIN_INPUT;
                 }else{
                    /* Error : Undefined Direction */
                    Pin_Direction_Ptr->Pin7 = PIN_INPUT;
                 }
                 break;
            default:
                 /* Error: Undefined Pin */
                 break;
     }
}
void GPIO_SetPinValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                      const GPIO_Pin_ID_t GPIO_PIN_ID,
                      const GPIO_PinValue_t GPIO_PIN_VALUE){

     volatile Pin_Value_t* Pin_Value_Ptr;
     switch(GPIO_PORT_ID){
            case GPIO_PORTA:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTA_WRITE_ADDRESS;
                 break;
            case GPIO_PORTB:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTB_WRITE_ADDRESS;
                 break;
            case GPIO_PORTC:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTC_WRITE_ADDRESS;
                 break;
            case GPIO_PORTD:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTD_WRITE_ADDRESS;
                 break;
            case GPIO_PORTE:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTE_WRITE_ADDRESS;
                 break;
            default:
                 /* Error: Undefined Port */
                 return;
     }
     switch(GPIO_PIN_ID){
            case GPIO_PIN0:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin0 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin0 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin0 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN1:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin1 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin1 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin1 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN2:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin2 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin2 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin2 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN3:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin3 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin3 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin3 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN4:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin4 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin4 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin4 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN5:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin5 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin5 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin5 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN6:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin6 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin6 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin6 = PIN_LOW;
                 }
                 break;
            case GPIO_PIN7:
                 if(GPIO_HIGH == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin7 = PIN_HIGH;
                 }else if(GPIO_LOW == GPIO_PIN_VALUE){
                    Pin_Value_Ptr->Pin7 = PIN_LOW;
                 }else{
                    /* Error: Undefined Value */
                    Pin_Value_Ptr->Pin7 = PIN_LOW;
                 }
                 break;
            default:
                 /* Error: Undefined Pin */
                 break;
     }
}
GPIO_PinValue_t GPIO_ReadPinValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                                  const GPIO_Pin_ID_t GPIO_PIN_ID){

     volatile Pin_Value_t* Pin_Value_Ptr;
     GPIO_PinValue_t GPIO_PinValue = GPIO_HIGH;
     switch(GPIO_PORT_ID){
            case GPIO_PORTA:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTA_READ_ADDRESS;
                 break;
            case GPIO_PORTB:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTB_READ_ADDRESS;
                 break;
            case GPIO_PORTC:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTC_READ_ADDRESS;
                 break;
            case GPIO_PORTD:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTD_READ_ADDRESS;
                 break;
            case GPIO_PORTE:
                 Pin_Value_Ptr = (volatile Pin_Value_t*)PORTE_READ_ADDRESS;
                 break;
            default:
                 /* Error: Undefined Port */
                 GPIO_PinValue = GPIO_LOW;
                 break;
     }
     if(GPIO_HIGH == GPIO_PinValue){
        switch(GPIO_PIN_ID){
            case GPIO_PIN0:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin0){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN1:
                if(PIN_HIGH == Pin_Value_Ptr->Pin1){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN2:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin2){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN3:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin3){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN4:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin4){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN5:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin5){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN6:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin6){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            case GPIO_PIN7:
                 if(PIN_HIGH == Pin_Value_Ptr->Pin7){
                    GPIO_PinValue = GPIO_HIGH;
                 }else{
                    GPIO_PinValue = GPIO_LOW;
                 }
                 break;
            default:
                 /* Error: Undefined Pin */
                 GPIO_PinValue = GPIO_LOW;
                 break;
        }
     }
     return GPIO_PinValue;
}
void GPIO_SetPortDirection(const GPIO_Port_ID_t GPIO_PORT_ID,
                           const GPIO_Direction_t GPIO_PORT_DIRECTION){

    volatile Port_Direction_State_t* Port_Direction_Ptr;
    switch(GPIO_PORT_ID){
          case GPIO_PORTA:
               Port_Direction_Ptr = (volatile Port_Direction_State_t*)PORTA_DIRECTION_ADDRESS;
               break;
          case GPIO_PORTB:
               Port_Direction_Ptr = (volatile Port_Direction_State_t*)PORTB_DIRECTION_ADDRESS;
               break;
          case GPIO_PORTC:
               Port_Direction_Ptr = (volatile Port_Direction_State_t*)PORTC_DIRECTION_ADDRESS;
               break;
          case GPIO_PORTD:
               Port_Direction_Ptr = (volatile Port_Direction_State_t*)PORTD_DIRECTION_ADDRESS;
               break;
          case GPIO_PORTE:
               Port_Direction_Ptr = (volatile Port_Direction_State_t*)PORTE_DIRECTION_ADDRESS;
               break;
          default:
               /* Error: Undefined Port */
               return;
   }
   if(GPIO_OUTPUT == GPIO_PORT_DIRECTION){
      *Port_Direction_Ptr = PORT_OUTPUT;
   }else if(GPIO_INPUT == GPIO_PORT_DIRECTION){
      *Port_Direction_Ptr = PORT_INPUT;
   }else{
      /* Error: Undefined Direction */
      *Port_Direction_Ptr = PORT_INPUT;
   }
}
void GPIO_SetPortValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                       const u8_t GPIO_PORT_VLAUE){

     volatile u8_t* Port_Value_Ptr;
     switch(GPIO_PORT_ID){
          case GPIO_PORTA:
               Port_Value_Ptr = (volatile u8_t*)PORTA_WRITE_ADDRESS;
               break;
          case GPIO_PORTB:
               Port_Value_Ptr = (volatile u8_t*)PORTB_WRITE_ADDRESS;
               break;
          case GPIO_PORTC:
               Port_Value_Ptr = (volatile u8_t*)PORTC_WRITE_ADDRESS;
               break;
          case GPIO_PORTD:
               Port_Value_Ptr = (volatile u8_t*)PORTD_WRITE_ADDRESS;
               break;
          case GPIO_PORTE:
               Port_Value_Ptr = (volatile u8_t*)PORTE_WRITE_ADDRESS;
               break;
          default:
               /* Error: Undefined Port */
               return;
   }
   *Port_Value_Ptr = GPIO_PORT_VLAUE;
}
u8_t GPIO_ReadPortValue(const GPIO_Port_ID_t GPIO_PORT_ID){
     volatile u8_t* Port_Value_Ptr;
     switch(GPIO_PORT_ID){
          case GPIO_PORTA:
               Port_Value_Ptr = (volatile u8_t*)PORTA_READ_ADDRESS;
               break;
          case GPIO_PORTB:
               Port_Value_Ptr = (volatile u8_t*)PORTB_READ_ADDRESS;
               break;
          case GPIO_PORTC:
               Port_Value_Ptr = (volatile u8_t*)PORTC_READ_ADDRESS;
               break;
          case GPIO_PORTD:
               Port_Value_Ptr = (volatile u8_t*)PORTD_READ_ADDRESS;
               break;
          case GPIO_PORTE:
               Port_Value_Ptr = (volatile u8_t*)PORTE_READ_ADDRESS;
               break;
          default:
               /* Error: Undefined Port */
               return PORT_ERROR;
     }
     return *Port_Value_Ptr;
}
void GPIO_Init(void){
     ADCON1 = 0X06; /* No Analog Channels */
}