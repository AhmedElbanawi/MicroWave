/******************************************************************************/
#ifndef KEYPAD_H
#define KEYPAD_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        KEY_0_ID = 0,
        KEY_1_ID,
        KEY_2_ID,
        KEY_3_ID,
        KEY_4_ID,
        KEY_5_ID,
        KEY_6_ID,
        KEY_7_ID,
        KEY_8_ID,
        KEY_9_ID,
        KEY_START,
        KEY_STOP,
        MAX_NO_OF_KEYS,
        NULL_KEY
}KEY_ID_t;
typedef enum{
        KEYPAD_ROW0_PIN_ID = GPIO_PIN0,
        KEYPAD_ROW1_PIN_ID = GPIO_PIN1,
        KEYPAD_ROW2_PIN_ID = GPIO_PIN2,
        KEYPAD_ROW3_PIN_ID = GPIO_PIN3
}KEYPAD_ROW_PIN_ID_t;
typedef enum{
        KEYPAD_ROW0_PORT_ID = GPIO_PORTC,
        KEYPAD_ROW1_PORT_ID = GPIO_PORTC,
        KEYPAD_ROW2_PORT_ID = GPIO_PORTC,
        KEYPAD_ROW3_PORT_ID = GPIO_PORTC
}KEYPAD_ROW_PORT_ID_t;
typedef enum{
        KEYPAD_COL0_PIN_ID = GPIO_PIN0,
        KEYPAD_COL1_PIN_ID = GPIO_PIN1,
        KEYPAD_COL2_PIN_ID = GPIO_PIN2
}KEYPAD_COL_PIN_ID_t;
typedef enum{
        KEYPAD_COL0_PORT_ID = GPIO_PORTD,
        KEYPAD_COL1_PORT_ID = GPIO_PORTD,
        KEYPAD_COL2_PORT_ID = GPIO_PORTD
}KEYPAD_COL_PORT_ID_t;
typedef enum{
        KEYPAD_ROWS_DIRECTION_ID = GPIO_INPUT
}KEYPAD_ROWS_DIRECTION_ID_t;
typedef enum{
        KEYPAD_COLS_DIRECTION_ID = GPIO_OUTPUT
}KEYPAD_COLS_DIRECTION_ID_t;
typedef enum{
        KEY_STATE_OFF = 0,
        KEY_STATE_ON
}KEY_STATE_t;
typedef enum{
        FALLING = 0,
        RISING
}READING_TIME_t;
typedef struct{
        KEY_STATE_t State;
        READING_TIME_t Time;
}KEY_t;
/******************************************************************************/
extern KEY_ID_t Key_Pressed_g;
/******************************************************************************/
void KEYPAD_Init(void);
void KEYPAD_Update(void);
/******************************************************************************/