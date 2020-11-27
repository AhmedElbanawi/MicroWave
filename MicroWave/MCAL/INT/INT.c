/******************************************************************************/
#ifndef INT_H
#include "INT.h"
#endif
/******************************************************************************/
void INT_Global_Init(void){
     CLEAR_BIT(INTCON, 7); /* Disable Global Interrupt */
     SET_BIT(INTCON, 6);  /* Enable Peripherals Interrupt */
}
void INT_Global_Disable(void){
     CLEAR_BIT(INTCON, 7);
}
void INT_Global_Enable(void){
     SET_BIT(INTCON, 7);
}