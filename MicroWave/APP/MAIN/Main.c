/******************************************************************************/
#ifndef CO_SCH_H
#include "CO_SCH.h"
#endif
/******************************************************************************/
#ifndef KEYPAD_H
#include "KEYPAD.h"
#endif
/******************************************************************************/
#ifndef SSD_H
#include "SSD.h"
#endif
/******************************************************************************/
#ifndef WEIGHT_H
#include "WEIGHT.h"
#endif
/******************************************************************************/
#ifndef DOOR_H
#include "DOOR.h"
#endif
/******************************************************************************/
#ifndef LED_H
#include "LED.h"
#endif
/******************************************************************************/
#ifndef FAN_H
#include "FAN.h"
#endif
/******************************************************************************/
#ifndef HEATER_H
#include "HEATER.h"
#endif
/******************************************************************************/
#ifndef CONT_H
#include "CONT.h"
#endif
/******************************************************************************/
void main(){
     LED_Init();
     HEATER_Init();
     DOOR_Init();
     FAN_Init();
     WEIGHT_Init();
     KEYPAD_Init();
     SSD_Init();
     CO_SCH_Init();
     CO_SCH_Add_Task(KEYPAD_Update, 0, 1); /* Every 10 ms WCET = 0.492 ms BCET = 0.477 ms */
     CO_SCH_Add_Task(WEIGHT_Update, 0, 2); /* Every 20 ms WCET = 0.107 ms BCET = 0.093 ms */
     CO_SCH_Add_Task(DOOR_Update, 0, 2);   /* Every 20 ms WCET = 0.107 ms BCET = 0.090 ms */
     CO_SCH_Add_Task(CONT_Update, 0, 2);   /* Every 20 ms WCET = 0.096 ms BCET = 0.031 ms */
     CO_SCH_Add_Task(SSD_Update, 0, 1);    /* Every 10 ms WCET = 0.767 ms BCET = 0.767 ms */
     CO_SCH_Add_Task(HEATER_Update, 0, 2); /* Every 20 ms WCET = 0.108 ms BCET = 0.108 ms */
     CO_SCH_Add_Task(FAN_Update, 0, 2);    /* Every 20 ms WCET = 0.103 ms BCET = 0.103 ms */
     CO_SCH_Add_Task(LED_Update, 0, 2);    /* Every 20 ms WCET = 0.099 ms BCET = 0.099 ms */
     CO_SCH_Start();
     while(1){
              CO_SCH_Dispatch_Tasks();
     }
}