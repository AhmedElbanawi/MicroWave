/******************************************************************************/
#ifndef GPT2_H
#include "GPT2.h"
#endif
/******************************************************************************/
void GPT2_Start(void){
     SET_BIT(T2CON, 2);
}
/******************************************************************************/
void GPT2_Stop(void){
     CLEAR_BIT(T2CON, 2);
}
/******************************************************************************/
void GPT2_Scaler_Update(const GPT2_Prescaler_t GPT2_PRESCALER,
                        const GPT2_Postscaler_t GPT2_POSTSCALER){

     switch(GPT2_PRESCALER){
            case GPT2_PRESCALER_1_TO_1:
                 T2CON = GPT2_PRESCALER;
                 break;
            case GPT2_PRESCALER_1_TO_4:
                 T2CON = GPT2_PRESCALER;
                 break;
            case GPT2_PRESCALER_1_TO_16:
                 T2CON = GPT2_PRESCALER;
                 break;
            default:
                 /* Error: Undefined Prescaler */
                 break;
     }
     switch(GPT2_POSTSCALER){
            case GPT2_POSTSCALER_1_TO_1:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_2:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_3:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_4:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_5:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_6:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_7:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_8:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_9:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_10:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_11:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_12:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_13:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_14:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_15:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            case GPT2_POSTSCALER_1_TO_16:
                 T2CON |= (GPT2_POSTSCALER << 3);
                 break;
            default:
                 /* Error: Undefined Postscaler */
                 break;
                 
     }
}
/******************************************************************************/
void GPT2_Update_us(const u8_t GPT2_UPDATE_VAL){
     PR2 = GPT2_UPDATE_VAL; /* Reload The Period Register */
}
/******************************************************************************/
void GPT2_Init(void){
     T2CON = 0X00; /* Stop GPT2, Prescaler and PostScaler are 1 : 1 */
     PR2 = 0XFF;   /* Init Period Register With Max Value */
     TMR2 = 0X00;  /* Init Timer2 Register With Min Value */
     CLEAR_BIT(PIR1, 1); /* Clear Timer2 Flag */
     CLEAR_BIT(PIE1, 1); /* Disable Timer2 Interrupt */
}
/******************************************************************************/
void GPT2_Flag_Clear(void){
     CLEAR_BIT(PIR1, 1);
}
/******************************************************************************/
GPT2_Flag_t GPT2_Flag_Read(void){
       GPT2_Flag_t GPT2_Flag;
       if(GPT2_OVERFLOW_OCCURED == GET_BIT(PIR1, 1)){
          GPT2_Flag = GPT2_OVERFLOW_OCCURED;
       }else{
          GPT2_Flag = GPT2_OVERFLOW_NOT_OCCURED;
       }
       return GPT2_Flag;
}
/******************************************************************************/
void GPT2_Interrupt_Disable(void){
     CLEAR_BIT(PIE1, 1);
}
/******************************************************************************/
void GPT2_Interrupt_Enable(void){
     SET_BIT(PIE1, 1);
}
/******************************************************************************/