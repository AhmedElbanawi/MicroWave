/******************************************************************************/
#ifndef SYS_DATA_TYPES_H
#define SYS_DATA_TYPES_H
#endif
/******************************************************************************/
#define NULL_PTR ((void*)0)
/******************************************************************************/
typedef unsigned short  u8_t;
typedef unsigned int   u16_t;
typedef unsigned long int  u32_t;
typedef u8_t wordsize_t;
typedef volatile wordsize_t* const memoryaddress_t;
typedef enum{
        FALSE = 0,
        TRUE
}Bool_t;
/******************************************************************************/
typedef signed short  s8_t;
typedef signed int s16_t;
typedef signed long int  s32_t;
/******************************************************************************/