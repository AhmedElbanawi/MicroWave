/******************************************************************************/
#ifndef WEIGHT_H
#include "WEIGHT.h"
#endif
/******************************************************************************/
typedef enum{
        FALLING = 0,
        RISING
}READING_TIME_t;
/******************************************************************************/
WEIGHT_STATE_t WEIGHT_State = WEIGHT_NOT_EXIST;
void WEIGHT_Init(void){
     GPIO_SetPinDirection(WEIGHT_PORT_ID, WEIGHT_PIN_ID, WEIGHT_DIRECTION_ID);
}
void WEIGHT_Update(void){
     static READING_TIME_t Time = FALLING;
     if(FALLING == Time){
        if(GPIO_LOW == GPIO_ReadPinValue(WEIGHT_PORT_ID, WEIGHT_PIN_ID)){
           Time = RISING;
        }
     }
     else if(RISING == Time){
        if(GPIO_HIGH == GPIO_ReadPinValue(WEIGHT_PORT_ID, WEIGHT_PIN_ID)){
           if(WEIGHT_NOT_EXIST == WEIGHT_State){
              WEIGHT_State = WEIGHT_EXIST;
           }
           else if(WEIGHT_EXIST == WEIGHT_State){
              WEIGHT_State = WEIGHT_NOT_EXIST;
           }
           else{
              /* Error: Undefined WEIGHT State */
           }
           Time = FALLING;
        }
     }
     else{
        /* Error: Undefined TIME READING */
     }
}