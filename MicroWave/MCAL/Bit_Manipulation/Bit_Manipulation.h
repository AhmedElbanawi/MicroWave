/***************************************************/
#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H
#endif
/*************************************************/
#define SET_BIT(REG, PIN) ( REG |= (1 << (PIN)) )
#define CLEAR_BIT(REG, PIN) ( REG &= ~(1 << (PIN)) )
#define SET_WORD(REG) (REG = 0XFF)
#define CLEAR_WORD(REG) (REG = 0X00)
#define GET_BIT(REG, PIN) ( ( (REG) & ( 1 << (PIN) ) ) >> (PIN) )
/*************************************************/