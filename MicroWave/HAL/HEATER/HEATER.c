/******************************************************************************/
#ifndef HEATER_H
#include "HEATER.h"
#endif
/******************************************************************************/
HEATER_STATE_t HEATER_State = HEATER_OFF;
/******************************************************************************/
void HEATER_Init(void){
     GPIO_SetPinDirection(HEATER_PORT_ID, HEATER_PIN_ID, HEATER_DIRECTION_ID);
}
/******************************************************************************/
void HEATER_Update(void){
     switch(HEATER_State){
            case HEATER_OFF:
                 GPIO_SetPinValue(HEATER_PORT_ID, HEATER_PIN_ID, HEATER_OFF);
                 break;
            case HEATER_ON:
                 GPIO_SetPinValue(HEATER_PORT_ID, HEATER_PIN_ID, HEATER_ON);
                 break;
            default:
                 /* Error: Undefined HEATER State */
                 break;

     }
}
/******************************************************************************/