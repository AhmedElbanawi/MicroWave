/******************************************************************************/
#ifndef CO_SCH_H
#include "CO_SCH.h"
#endif
/******************************************************************************/
#ifndef INT_H
#include "INT.h"
#endif
/******************************************************************************/
#ifndef GPT2_H
#include "GPT2.h"
#endif
/******************************************************************************/
#define ENDED 0
/******************************************************************************/
static void CO_SCH_Update_Tasks(void);
/******************************************************************************/
TASK_t CO_SCH_Task[CO_SCH_MAX_TASKS];
volatile Bool_t CO_SCH_Update = TRUE;
/******************************************************************************/
void CO_SCH_Delete_Task(const u8_t ID){
     if(ID < CO_SCH_MAX_TASKS && CO_SCH_Task[ID].pTask != NULL_PTR){
        CO_SCH_Task[ID].pTask = NULL_PTR;
        CO_SCH_Task[ID].Run = 0;
        CO_SCH_Task[ID].Delay = 0;
        CO_SCH_Task[ID].Period = 0;
     }
     else{
        /* Error: Undefined Task */
     }
}
/******************************************************************************/
void CO_SCH_Init(void){
     u8_t Id;
     for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
         CO_SCH_Delete_Task(Id);
     }
     /* To Do: Init Timer Here */
     INT_Global_Init();
     GPT2_Init();
                 /* Tick = 10 Ms */
     GPT2_Scaler_Update(GPT2_PRESCALER_1_TO_4, GPT2_POSTSCALER_1_TO_10);
     GPT2_Update_us(250);
}
/******************************************************************************/
void CO_SCH_Add_Task(void (*const PTASK)(void),
                     const u8_t DELAY,
                     const u8_t PERIOD){

     static u8_t Id = 0;
     if(Id < CO_SCH_MAX_TASKS){
        CO_SCH_Task[Id].pTask = PTASK;
        CO_SCH_Task[Id].Delay = 1 + DELAY;
        CO_SCH_Task[Id].Period = PERIOD;
        CO_SCH_Task[Id].Run = 0;
        CO_SCH_Task[Id].Id = Id;
        Id++;
     }
     else{
        /* Error: Scheduler is Fulled */
     }
}
/******************************************************************************/
void CO_SCH_Dispatch_Tasks(void){
     u8_t Id;
     if(TRUE == CO_SCH_Update){
        CO_SCH_Update_Tasks();
        for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
            if(CO_SCH_Task[Id].Run > 0){
               CO_SCH_Task[Id].pTask();
               CO_SCH_Task[Id].Run--;
               if(0 == CO_SCH_Task[Id].Period){
                  CO_SCH_Delete_Task(Id);
               }
            }
            else{
               /* Task is not Ready */
            }
        }
        CO_SCH_Update = 0;
     }
}
/******************************************************************************/
static void CO_SCH_Update_Tasks(void){
       u8_t Id;
       for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
           if(CO_SCH_Task[Id].pTask != NULL_PTR){
              CO_SCH_Task[Id].Delay--;
              if(ENDED == CO_SCH_Task[Id].Delay){
                 CO_SCH_Task[Id].Run++;
                 CO_SCH_Task[Id].Delay = CO_SCH_Task[Id].Period;
              }
              else{
                 /* Task is not Ready */
              }
           }
           else{
              /* Error: Undefined Task */
           }
       }
}
/******************************************************************************/
void CO_SCH_Start(void){
     /* To Do: Enable Interrupt Here */
     GPT2_Interrupt_Enable();
     INT_Global_Enable();
     GPT2_Start();
}
/******************************************************************************/
#if 0
void CO_SCH_Sleep(void){
     /* To Do: */
}
#endif
/******************************************************************************/
void Interrupt(void){
     if(GPT2_OVERFLOW_OCCURED == GPT2_Flag_Read()){
        GPT2_Flag_Clear();
        CO_SCH_Update = TRUE;
     }
}
/******************************************************************************/