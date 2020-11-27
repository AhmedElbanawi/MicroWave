/******************************************************************************/
#ifndef GPT2_H
#define GPT2_H
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
        GPT2_PRESCALER_1_TO_1 = 0,
        GPT2_PRESCALER_1_TO_4,
        GPT2_PRESCALER_1_TO_16
}GPT2_Prescaler_t;
typedef enum{
        GPT2_POSTSCALER_1_TO_1 = 0,
        GPT2_POSTSCALER_1_TO_2,
        GPT2_POSTSCALER_1_TO_3,
        GPT2_POSTSCALER_1_TO_4,
        GPT2_POSTSCALER_1_TO_5,
        GPT2_POSTSCALER_1_TO_6,
        GPT2_POSTSCALER_1_TO_7,
        GPT2_POSTSCALER_1_TO_8,
        GPT2_POSTSCALER_1_TO_9,
        GPT2_POSTSCALER_1_TO_10,
        GPT2_POSTSCALER_1_TO_11,
        GPT2_POSTSCALER_1_TO_12,
        GPT2_POSTSCALER_1_TO_13,
        GPT2_POSTSCALER_1_TO_14,
        GPT2_POSTSCALER_1_TO_15,
        GPT2_POSTSCALER_1_TO_16
}GPT2_Postscaler_t;
typedef enum{
        GPT2_OVERFLOW_NOT_OCCURED = 0,
        GPT2_OVERFLOW_OCCURED
}GPT2_Flag_t;
/******************************************************************************/
void GPT2_Start(void);
void GPT2_Stop(void);
void GPT2_Init(void);
void GPT2_Interrupt_Enable(void);
void GPT2_Interrupt_Disable(void);
void GPT2_Update_us(const u8_t GPT2_UPDATE_VAL);
GPT2_Flag_t GPT2_Flag_Read(void);
void GPT2_Flag_Clear(void);
void GPT2_Scaler_Update(const GPT2_Prescaler_t GPT2_PRESCALER,
                        const GPT2_Postscaler_t GPT2_POSTSCALER);
/******************************************************************************/