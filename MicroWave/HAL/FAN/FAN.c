/******************************************************************************/
#ifndef FAN_H
#include "FAN.h"
#endif
/******************************************************************************/
FAN_STATE_t FAN_State = FAN_OFF;
/******************************************************************************/
void FAN_Init(void){
     GPIO_SetPinDirection(FAN_PORT_ID, FAN_PIN_ID, FAN_DIRECTION_ID);
}
/******************************************************************************/
void FAN_Update(void){
     switch(FAN_State){
            case FAN_OFF:
                 GPIO_SetPinValue(FAN_PORT_ID, FAN_PIN_ID, FAN_OFF);
                 break;
            case FAN_ON:
                 GPIO_SetPinValue(FAN_PORT_ID, FAN_PIN_ID, FAN_ON);
                 break;
            default:
                 /* Error: Undefined FAN State */
                 break;

     }
}
/******************************************************************************/