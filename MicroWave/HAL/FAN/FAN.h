/******************************************************************************/
#ifndef FAN_H
#define FAN_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        FAN_OFF = 0,
        FAN_ON
}FAN_STATE_t;
typedef enum{
        FAN_PIN_ID = GPIO_PIN6
}FAN_PIN_ID_t;
typedef enum{
        FAN_PORT_ID = GPIO_PORTD
}FAN_PORT_ID_t;
typedef enum{
        FAN_DIRECTION_ID = GPIO_OUTPUT
}FAN_DIRECTION_ID_t;
/******************************************************************************/
void FAN_Init(void);
void FAN_Update(void);
/******************************************************************************/