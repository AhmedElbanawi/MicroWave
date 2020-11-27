/******************************************************************************/
#ifndef DOOR_H
#define DOOR_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        DOOR_CLOSED = 0,
        DOOR_OPENED
}DOOR_STATE_t;
typedef enum{
        DOOR_PIN_ID = GPIO_PIN3
}DOOR_PIN_ID_t;
typedef enum{
        DOOR_PORT_ID = GPIO_PORTD
}DOOR_PORT_ID_t;
typedef enum{
        DOOR_DIRECTION_ID = GPIO_INPUT
}DOOR_DIRECTION_ID_t;
/******************************************************************************/
void DOOR_Init(void);
void DOOR_Update(void);
/******************************************************************************/