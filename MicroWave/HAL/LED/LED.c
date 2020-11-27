/******************************************************************************/
#ifndef LED_H
#include "LED.h"
#endif
/******************************************************************************/
LED_STATE_t LED_State = LED_OFF;
void LED_Init(void){
     GPIO_SetPinDirection(LED_PORT_ID, LED_PIN_ID, LED_DIRECTION_ID);
}
void LED_Update(void){
     switch(LED_State){
            case LED_OFF:
                 GPIO_SetPinValue(LED_PORT_ID, LED_PIN_ID, LED_OFF);
                 break;
            case LED_ON:
                 GPIO_SetPinValue(LED_PORT_ID, LED_PIN_ID, LED_ON);
                 break;
            default:
                 /* Error: Undefined LED State */
                 break;
                 
     }
}