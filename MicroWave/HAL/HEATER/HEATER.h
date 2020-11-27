/******************************************************************************/
#ifndef HEATER_H
#define HEATER_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        HEATER_OFF = 0,
        HEATER_ON
}HEATER_STATE_t;
typedef enum{
        HEATER_PIN_ID = GPIO_PIN7
}HEATER_PIN_ID_t;
typedef enum{
        HEATER_PORT_ID = GPIO_PORTD
}HEATER_PORT_ID_t;
typedef enum{
        HEATER_DIRECTION_ID = GPIO_OUTPUT
}HEATER_DIRECTION_ID_t;
/******************************************************************************/
void HEATER_Init(void);
void HEATER_Update(void);
/******************************************************************************/