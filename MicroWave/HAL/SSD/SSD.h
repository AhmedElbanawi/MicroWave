/******************************************************************************/
#ifndef SSD_H
#define SSD_H
#endif
/******************************************************************************/
#ifndef GPIO_H
#include "GPIO.h"
#endif
/******************************************************************************/
typedef enum{
        SSD_A_PIN_ID = GPIO_PIN0,
        SSD_B_PIN_ID = GPIO_PIN1,
        SSD_C_PIN_ID = GPIO_PIN2,
        SSD_D_PIN_ID = GPIO_PIN3,
        SSD_MINUTES_TENS_PIN_ID = GPIO_PIN4,
        SSD_MINUTES_UNITS_PIN_ID = GPIO_PIN5,
        SSD_SECONDS_TENS_PIN_ID = GPIO_PIN6,
        SSD_SECONDS_UNITS_PIN_ID = GPIO_PIN7
}SSD_Pin_ID_t;
typedef enum{
        SSD_DIRECTION = GPIO_OUTPUT
}SSD_Direction_t;
typedef enum{
        SSD_A_PORT_ID = GPIO_PORTB,
        SSD_B_PORT_ID = GPIO_PORTB,
        SSD_C_PORT_ID = GPIO_PORTB,
        SSD_D_PORT_ID = GPIO_PORTB,
        SSD_MINUTES_TENS_PORT_ID = GPIO_PORTB,
        SSD_MINUTES_UNITS_PORT_ID = GPIO_PORTB,
        SSD_SECONDS_TENS_PORT_ID = GPIO_PORTB,
        SSD_SECONDS_UNITS_PORT_ID = GPIO_PORTB
}SSD_Port_ID_t;
typedef enum{
        SSD_STATE_ON = 0,
        SSD_STATE_OFF
}SSD_State_t;
/******************************************************************************/
void SSD_Init(void);
void SSD_Update(void);