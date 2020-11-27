/******************************************************************************/
#ifndef WEIGHT_H
#define WEIGHT_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        WEIGHT_NOT_EXIST = 0,
        WEIGHT_EXIST
}WEIGHT_STATE_t;
typedef enum{
        WEIGHT_PIN_ID = GPIO_PIN4
}WEIGHT_PIN_ID_t;
typedef enum{
        WEIGHT_PORT_ID = GPIO_PORTD
}WEIGHT_PORT_ID_t;
typedef enum{
        WEIGHT_DIRECTION_ID = GPIO_INPUT
}WEIGHT_DIRECTION_ID_t;
void WEIGHT_Init(void);
void WEIGHT_Update(void);
/******************************************************************************/