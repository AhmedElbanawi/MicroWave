/******************************************************************************/
#ifndef GPIO_H
#define GPIO_H
#endif
/******************************************************************************/
#ifndef SYS_DATA_TYPES_H
#include "Sys_Data_Types.h"
#endif
/******************************************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/******************************************************************************/
typedef enum{
        GPIO_PORTA = 0X0A,
        GPIO_PORTB,
        GPIO_PORTC,
        GPIO_PORTD,
        GPIO_PORTE,
        GPIO_NO_OF_PORTS
}GPIO_Port_ID_t;
typedef enum{
        GPIO_PIN0 = 0,
        GPIO_PIN1,
        GPIO_PIN2,
        GPIO_PIN3,
        GPIO_PIN4,
        GPIO_PIN5,
        GPIO_PIN6,
        GPIO_PIN7,
        GPIO_NO_OF_PINS
}GPIO_Pin_ID_t;
typedef enum{
        GPIO_OUTPUT = 0,
        GPIO_INPUT
}GPIO_Direction_t;
typedef enum{
        GPIO_LOW = 0,
        GPIO_HIGH
}GPIO_PinValue_t;
void GPIO_SetPinDirection(const GPIO_Port_ID_t GPIO_PORT_ID,
                          const GPIO_Pin_ID_t GPIO_PIN_ID,
                          const GPIO_Direction_t GPIO_PIN_DIRECTION);

void GPIO_SetPinValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                      const GPIO_Pin_ID_t GPIO_PIN_ID,
                      const GPIO_PinValue_t GPIO_PIN_VALUE);

GPIO_PinValue_t GPIO_ReadPinValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                                  const GPIO_Pin_ID_t GPIO_PIN_ID);

void GPIO_SetPortDirection(const GPIO_Port_ID_t GPIO_PORT_ID,
                           const GPIO_Direction_t GPIO_PORT_DIRECTION);

void GPIO_SetPortValue(const GPIO_Port_ID_t GPIO_PORT_ID,
                       const u8_t GPIO_PORT_VLAUE);

u8_t GPIO_ReadPortValue(const GPIO_Port_ID_t GPIO_PORT_ID);
void GPIO_Init(void);