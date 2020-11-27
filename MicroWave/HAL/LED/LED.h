/******************************************************************************/
#ifndef LED_H
#define LED_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        LED_OFF = 0,
        LED_ON
}LED_STATE_t;
typedef enum{
        LED_PIN_ID = GPIO_PIN5
}LED_PIN_ID_t;
typedef enum{
        LED_PORT_ID = GPIO_PORTD
}LED_PORT_ID_t;
typedef enum{
        LED_DIRECTION_ID = GPIO_OUTPUT
}LED_DIRECTION_ID_t;
void LED_Init(void);
void LED_Update(void);
/******************************************************************************/