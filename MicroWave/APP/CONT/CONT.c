/******************************************************************************/
#ifndef CONT_H
#include "CONT.h"
#endif
/******************************************************************************/
#ifndef KEYPAD_H
#include "KEYPAD.h"
#endif
/******************************************************************************/
#define PERIODE_1_SEC 50
/******************************************************************************/
typedef enum{
        CONT_OFF_MODE = 0,
        CONT_SETTING_MODE,
        CONT_ON_MODE
}CONT_MODE_t;
typedef enum{
        FAN_OFF = 0,
        FAN_ON
}FAN_STATE_t;
typedef enum{
        LED_OFF = 0,
        LED_ON
}LED_STATE_t;
typedef enum{
        HEATER_OFF = 0,
        HEATER_ON
}HEATER_STATE_t;
typedef enum{
        WEIGHT_NOT_EXIST = 0,
        WEIGHT_EXIST
}WEIGHT_STATE_t;
typedef enum{
        DOOR_CLOSED = 0,
        DOOR_OPENED
}DOOR_STATE_t;
typedef enum{
        MINUTES_TENS_MODE = 0,
        MINUTES_UNITS_MODE
}DIGIT_t;
/******************************************************************************/
extern WEIGHT_STATE_t WEIGHT_State;
extern DOOR_STATE_t DOOR_State;
extern FAN_STATE_t FAN_State;
extern HEATER_STATE_t HEATER_State;
extern LED_STATE_t LED_State;
extern u8_t Minutes_Tens, Minutes_Units, Seconds_Tens, Seconds_Units;
static CONT_MODE_t CONT_Mode = CONT_OFF_MODE;
/******************************************************************************/
void CONT_Update(void){
     static DIGIT_t Digit = MINUTES_TENS_MODE;
     static u16_t Cnt = PERIODE_1_SEC;
     switch(CONT_Mode){
            case CONT_OFF_MODE:
                 Minutes_Tens = 0;
                 Minutes_Units = 0;
                 Seconds_Tens = 0;
                 Seconds_Units = 0;
                 Cnt = PERIODE_1_SEC;
                 FAN_State = FAN_OFF;
                 HEATER_State = HEATER_OFF;
                 LED_State = LED_OFF;
                 Digit = MINUTES_TENS_MODE;
                 CONT_Mode =  CONT_SETTING_MODE;
                 break;
            case CONT_ON_MODE:
                 if(KEY_STOP == Key_Pressed_g ||
                    DOOR_OPENED == DOOR_State ||
                    WEIGHT_NOT_EXIST == WEIGHT_State ||
                    (0 == Minutes_Tens && 0 == Minutes_Units && 0 == Seconds_Tens && 0 == Seconds_Units)){
                    
                    CONT_Mode = CONT_OFF_MODE;
                 }
                 else{
                    HEATER_State = HEATER_ON;
                    FAN_State = FAN_ON;
                    LED_State = LED_ON;
                    Cnt--;
                    if(0 == Cnt){
                       if(0 == Seconds_Units){
                          if(0 == Seconds_Tens){
                             if(0 == Minutes_Units){
                                if(0 == Minutes_Tens){
                                   /* Time Out */
                                }else{
                                   Minutes_Tens--;
                                   Minutes_Units = 9;
                                   Seconds_Tens = 5;
                                   Seconds_Units = 9;
                                }
                             }else{
                                Minutes_Units--;
                                Seconds_Tens = 5;
                                Seconds_Units = 9;
                             }
                          }else{
                             Seconds_Tens--;
                             Seconds_Units = 9;
                          }
                       }else{
                          Seconds_Units--;
                       }
                       Cnt = PERIODE_1_SEC;
                    }
                 }
                 break;
            case CONT_SETTING_MODE:
                 if(NULL_KEY == Key_Pressed_g){
                    /* Do Nothing */
                 }
                 else if(KEY_STOP == Key_Pressed_g){
                    Minutes_Tens = 0;
                    Minutes_Units = 0;
                    Seconds_Tens = 0;
                    Seconds_Units = 0;
                    Digit = MINUTES_TENS_MODE;
                 }
                 else if(KEY_START == Key_Pressed_g &&
                          DOOR_CLOSED == DOOR_State &&
                          WEIGHT_EXIST == WEIGHT_State&&
                          (0 != Minutes_Tens || 0 != Minutes_Units)){
                          
                    CONT_Mode = CONT_ON_MODE;
                 }
                 else{
                    if(KEY_START != Key_Pressed_g){
                       switch(Digit){
                          case MINUTES_TENS_MODE:
                               Minutes_Tens = Key_Pressed_g;
                               Digit = MINUTES_UNITS_MODE;
                               break;
                          case MINUTES_UNITS_MODE:
                               Minutes_Units = Key_Pressed_g;
                               Digit = MINUTES_TENS_MODE;
                               break;
                       }
                    }
                 }
                 break;
            default:
                 /* Error: Undefined CONT Mode */
                 break;
     }
     Key_Pressed_g = NULL_KEY;
}
/******************************************************************************/