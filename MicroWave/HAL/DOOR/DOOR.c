/******************************************************************************/
#ifndef DOOR_H
#include "DOOR.h"
#endif
/******************************************************************************/
typedef enum{
        FALLING = 0,
        RISING
}READING_TIME_t;
/******************************************************************************/
DOOR_STATE_t DOOR_State = DOOR_OPENED;
/******************************************************************************/
void DOOR_Init(void){
     GPIO_SetPinDirection(DOOR_PORT_ID, DOOR_PIN_ID, DOOR_DIRECTION_ID);
}
/******************************************************************************/
void DOOR_Update(void){
     static READING_TIME_t Time = FALLING;
     if(FALLING == Time){
        if(GPIO_LOW == GPIO_ReadPinValue(DOOR_PORT_ID, DOOR_PIN_ID)){
           Time = RISING;
        }
     }
     else if(RISING == Time){
        if(GPIO_HIGH == GPIO_ReadPinValue(DOOR_PORT_ID, DOOR_PIN_ID)){
           if(DOOR_OPENED == DOOR_State){
              DOOR_State = DOOR_CLOSED;
           }
           else if(DOOR_CLOSED == DOOR_State){
              DOOR_State = DOOR_OPENED;
           }
           else{
              /* Error: Undefined DOOR State */
           }
           Time = FALLING;
        }
     }
     else{
        /* Error: Undefined TIME READING */
     }
}
/******************************************************************************/