/******************************************************************************/
#ifndef CO_SCH_H
#define CO_SCH_H
#endif
/******************************************************************************/
#ifndef SYS_DATA_TYPES_H
#include "Sys_Data_Types.h"
#endif
/******************************************************************************/
#define CO_SCH_MAX_TASKS 8
/******************************************************************************/
typedef struct{
        void (*pTask)(void);
        u8_t Period, Delay, Id, Run;
}TASK_t;
/******************************************************************************/
void CO_SCH_Init(void);
void CO_SCH_Dispatch_Tasks(void);
void CO_SCH_Add_Task(void (*const PTASK)(void),
                     const u8_t DELAY,
                     const u8_t PERIOD);
void CO_SCH_Delete_Task(const u8_t ID);
void CO_SCH_Start(void);
#if 0
void CO_SCH_Sleep(void);
#endif
/******************************************************************************/