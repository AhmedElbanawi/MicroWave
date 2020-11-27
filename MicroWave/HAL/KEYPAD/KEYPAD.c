/******************************************************************************/
#ifndef KEYPAD_H
#include "KEYPAD.h"
#endif
/******************************************************************************/
typedef enum{
        ROW0 = 0,
        ROW1,
        ROW2,
        ROW3,
        MAX_ROWS
}ROW_t;
typedef enum{
        COL0 = 0,
        COL1,
        COL2,
        MAX_COLS
}COL_t;
/******************************************************************************/
static KEY_t Key[MAX_NO_OF_KEYS] = { {KEY_STATE_OFF, FALLING} };
KEY_ID_t Key_Pressed_g = NULL_KEY;
/******************************************************************************/
static void KEYPAD_Update_Key(const KEY_ID_t KEY_ID);
static void KEYPAD_Seclect_Key(const ROW_t ROW,
                               const COL_t COL,
                               const KEY_ID_t KEY_ID);
/******************************************************************************/
void KEYPAD_Init(void){
                       /* Init ROWS */
     GPIO_SetPinDirection(KEYPAD_ROW0_PORT_ID, KEYPAD_ROW0_PIN_ID, KEYPAD_ROWS_DIRECTION_ID);
     GPIO_SetPinDirection(KEYPAD_ROW1_PORT_ID, KEYPAD_ROW1_PIN_ID, KEYPAD_ROWS_DIRECTION_ID);
     GPIO_SetPinDirection(KEYPAD_ROW2_PORT_ID, KEYPAD_ROW2_PIN_ID, KEYPAD_ROWS_DIRECTION_ID);
     GPIO_SetPinDirection(KEYPAD_ROW3_PORT_ID, KEYPAD_ROW3_PIN_ID, KEYPAD_ROWS_DIRECTION_ID);
                       /* Init COLS */
     GPIO_SetPinDirection(KEYPAD_COL0_PORT_ID, KEYPAD_COL0_PIN_ID, KEYPAD_COLS_DIRECTION_ID);
     GPIO_SetPinDirection(KEYPAD_COL1_PORT_ID, KEYPAD_COL1_PIN_ID, KEYPAD_COLS_DIRECTION_ID);
     GPIO_SetPinDirection(KEYPAD_COL2_PORT_ID, KEYPAD_COL2_PIN_ID, KEYPAD_COLS_DIRECTION_ID);
}
/******************************************************************************/
static void KEYPAD_Update_Key(const KEY_ID_t KEY_ID){
       switch(KEY_ID){
              case KEY_1_ID:
                   KEYPAD_Seclect_Key(ROW0, COL0, KEY_1_ID);
                   break;
              case KEY_4_ID:
                   KEYPAD_Seclect_Key(ROW1, COL0, KEY_4_ID);
                   break;
              case KEY_7_ID:
                   KEYPAD_Seclect_Key(ROW2, COL0, KEY_7_ID);
                   break;
              case KEY_START:
                   KEYPAD_Seclect_Key(ROW3, COL0, KEY_START);
                   break;
                   
              case KEY_2_ID:
                   KEYPAD_Seclect_Key(ROW0, COL1, KEY_2_ID);
                   break;
              case KEY_5_ID:
                   KEYPAD_Seclect_Key(ROW1, COL1, KEY_5_ID);
                   break;
              case KEY_8_ID:
                   KEYPAD_Seclect_Key(ROW2, COL1, KEY_8_ID);
                   break;
              case KEY_0_ID:
                   KEYPAD_Seclect_Key(ROW3, COL1, KEY_0_ID);
                   break;
                   
              case KEY_3_ID:
                   KEYPAD_Seclect_Key(ROW0, COL2, KEY_3_ID);
                   break;
              case KEY_6_ID:
                   KEYPAD_Seclect_Key(ROW1, COL2, KEY_6_ID);
                   break;
              case KEY_9_ID:
                   KEYPAD_Seclect_Key(ROW2, COL2, KEY_9_ID);
                   break;
              case KEY_STOP:
                   KEYPAD_Seclect_Key(ROW3, COL2, KEY_STOP);
                   break;
                   
              default:
                   /* Error: Undefined KEY */
                   break;
       }
}
/******************************************************************************/
static void KEYPAD_Seclect_Key(const ROW_t ROW,
                               const COL_t COL,
                               const KEY_ID_t KEY_ID){
                               
       GPIO_PinValue_t PinVal = GPIO_LOW;
                               /* Init COLS as LOW */
       GPIO_SetPinValue(KEYPAD_COL0_PORT_ID, KEYPAD_COL0_PIN_ID, GPIO_LOW);
       GPIO_SetPinValue(KEYPAD_COL1_PORT_ID, KEYPAD_COL1_PIN_ID, GPIO_LOW);
       GPIO_SetPinValue(KEYPAD_COL2_PORT_ID, KEYPAD_COL2_PIN_ID, GPIO_LOW);
       switch(COL){
              case COL0:
                   GPIO_SetPinValue(KEYPAD_COL0_PORT_ID, KEYPAD_COL0_PIN_ID, GPIO_HIGH);
                   break;
              case COL1:
                   GPIO_SetPinValue(KEYPAD_COL1_PORT_ID, KEYPAD_COL1_PIN_ID, GPIO_HIGH);
                   break;
              case COL2:
                   GPIO_SetPinValue(KEYPAD_COL2_PORT_ID, KEYPAD_COL2_PIN_ID, GPIO_HIGH);
                   break;
              default:
                   /* Error: Undefined COL */
                   return;
       }
       switch(ROW){
              case ROW0:
                   PinVal = GPIO_ReadPinValue(KEYPAD_ROW0_PORT_ID, KEYPAD_ROW0_PIN_ID);
                   break;
              case ROW1:
                   PinVal = GPIO_ReadPinValue(KEYPAD_ROW1_PORT_ID, KEYPAD_ROW1_PIN_ID);
                   break;
              case ROW2:
                   PinVal = GPIO_ReadPinValue(KEYPAD_ROW2_PORT_ID, KEYPAD_ROW2_PIN_ID);
                   break;
              case ROW3:
                   PinVal = GPIO_ReadPinValue(KEYPAD_ROW3_PORT_ID, KEYPAD_ROW3_PIN_ID);
                   break;
              default:
                   /* Error: Undefined ROW */
                   return;
       }
      if(FALLING == Key[KEY_ID].Time){
          Key[KEY_ID].State = KEY_STATE_OFF;
          if(GPIO_LOW == PinVal){
              Key[KEY_ID].Time = RISING;
          }
      }
     else if(RISING == Key[KEY_ID].Time){
          if(GPIO_HIGH == PinVal){
              Key[KEY_ID].State = KEY_STATE_ON;
              Key[KEY_ID].Time = FALLING;
              Key_Pressed_g = KEY_ID;
           }
     }
     else{
           /* Error: Undefined Pressing Timing State */
     }
}
/******************************************************************************/
void KEYPAD_Update(void){
     static KEY_ID_t Index = KEY_0_ID;
     if(MAX_NO_OF_KEYS == Index){
        Index = KEY_0_ID;
     }
     KEYPAD_Update_Key(Index);
     Index++;
}