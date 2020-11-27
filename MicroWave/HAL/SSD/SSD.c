/******************************************************************************/
#ifndef SSD_H
#include "SSD.h"
#endif
/******************************************************************************/
typedef enum{
        SSD_MINUTES_TENS = 0,
        SSD_MINUTES_UNITS,
        SSD_SECONDS_TENS,
        SSD_SECONDS_UNITS
}SSD_t;
/******************************************************************************/
static void SSD_On(const SSD_t SSD_ID);
static void SSD_Off(const SSD_t SSD_ID);
static void SSD_Refesh(void);
static void SSD_Time(const u8_t TIME);
/******************************************************************************/
u8_t Minutes_Tens = 0, Minutes_Units = 0, Seconds_Tens = 0, Seconds_Units = 0;
static SSD_t SSD_Id = SSD_MINUTES_TENS;
/******************************************************************************/
void SSD_Init(void){
                    /* Init Data Lines */
     GPIO_SetPinDirection(SSD_A_PORT_ID, SSD_A_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_B_PORT_ID, SSD_B_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_C_PORT_ID, SSD_C_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_D_PORT_ID, SSD_D_PIN_ID, SSD_DIRECTION);
                    /* Init Control Lines */
     GPIO_SetPinDirection(SSD_MINUTES_TENS_PORT_ID, SSD_MINUTES_TENS_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_MINUTES_UNITS_PORT_ID, SSD_MINUTES_UNITS_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_SECONDS_TENS_PORT_ID, SSD_SECONDS_TENS_PIN_ID, SSD_DIRECTION);
     GPIO_SetPinDirection(SSD_SECONDS_UNITS_PORT_ID, SSD_SECONDS_UNITS_PIN_ID, SSD_DIRECTION);

}
static void SSD_On(const SSD_t SSD_ID){
       switch(SSD_ID){
              case SSD_MINUTES_TENS:
                   GPIO_SetPinValue(SSD_MINUTES_TENS_PORT_ID, SSD_MINUTES_TENS_PIN_ID, SSD_STATE_ON);
                   break;
              case SSD_MINUTES_UNITS:
                   GPIO_SetPinValue(SSD_MINUTES_UNITS_PORT_ID, SSD_MINUTES_UNITS_PIN_ID, SSD_STATE_ON);
                   break;
              case SSD_SECONDS_TENS:
                   GPIO_SetPinValue(SSD_SECONDS_TENS_PORT_ID, SSD_SECONDS_TENS_PIN_ID, SSD_STATE_ON);
                   break;
              case SSD_SECONDS_UNITS:
                   GPIO_SetPinValue(SSD_SECONDS_UNITS_PORT_ID, SSD_SECONDS_UNITS_PIN_ID, SSD_STATE_ON);
                   break;
              default:
                   /* Error: Undefined SSD */
                   break;
       }
} 
static void SSD_Off(const SSD_t SSD_ID){
       switch(SSD_ID){
              case SSD_MINUTES_TENS:
                   GPIO_SetPinValue(SSD_MINUTES_TENS_PORT_ID, SSD_MINUTES_TENS_PIN_ID, SSD_STATE_OFF);
                   break;
              case SSD_MINUTES_UNITS:
                   GPIO_SetPinValue(SSD_MINUTES_UNITS_PORT_ID, SSD_MINUTES_UNITS_PIN_ID, SSD_STATE_OFF);
                   break;
              case SSD_SECONDS_TENS:
                   GPIO_SetPinValue(SSD_SECONDS_TENS_PORT_ID, SSD_SECONDS_TENS_PIN_ID, SSD_STATE_OFF);
                   break;
              case SSD_SECONDS_UNITS:
                   GPIO_SetPinValue(SSD_SECONDS_UNITS_PORT_ID, SSD_SECONDS_UNITS_PIN_ID, SSD_STATE_OFF);
                   break;
              default:
                   /* Error: Undefined SSD */
                   break;
       }
}
static void SSD_Time(const u8_t TIME){
       GPIO_SetPinValue(SSD_A_PORT_ID, SSD_A_PIN_ID, GET_BIT(TIME, 0));
       GPIO_SetPinValue(SSD_B_PORT_ID, SSD_B_PIN_ID, GET_BIT(TIME, 1));
       GPIO_SetPinValue(SSD_C_PORT_ID, SSD_C_PIN_ID, GET_BIT(TIME, 2));
       GPIO_SetPinValue(SSD_D_PORT_ID, SSD_D_PIN_ID, GET_BIT(TIME, 3));
}
void SSD_Update(void){
     SSD_Refesh();
}
static void SSD_Refesh(void){
       SSD_Off(SSD_MINUTES_TENS);
       SSD_Off(SSD_MINUTES_UNITS);
       SSD_Off(SSD_SECONDS_TENS);
       SSD_Off(SSD_SECONDS_UNITS);
       switch(SSD_Id){
              case SSD_MINUTES_TENS:
                   SSD_Time(Minutes_Tens);
                   SSD_On(SSD_MINUTES_TENS);
                   SSD_Id = SSD_MINUTES_UNITS;
                   break;
              case SSD_MINUTES_UNITS:
                   SSD_Time(Minutes_Units);
                   SSD_On(SSD_MINUTES_UNITS);
                   SSD_Id = SSD_SECONDS_TENS;
                   break;
              case SSD_SECONDS_TENS:
                   SSD_Time(Seconds_Tens);
                   SSD_On(SSD_SECONDS_TENS);
                   SSD_Id = SSD_SECONDS_UNITS;
                   break;
              case SSD_SECONDS_UNITS:
                   SSD_Time(Seconds_Units);
                   SSD_On(SSD_SECONDS_UNITS);
                   SSD_Id = SSD_MINUTES_TENS;
                   break;
              default:
                   /* Error: Undefined SSD */
                   break;
       }
}