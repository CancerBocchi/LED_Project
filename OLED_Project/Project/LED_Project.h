#ifndef __OLED_PROJECT_H__
#define __OLED_PROJECT_H__

#include "mylib.h"
#include "OLEDUI.h"
#include "oled.h"

#define PWM_VOLTCON_1 htim1.Instance->CCR1
#define PWM_VOLTCON_2 htim1.Instance->CCR2
#define PWM_VOLTCON_3 htim1.Instance->CCR3
#define PWM_VOLTCON_4 htim1.Instance->CCR4
#define PWM_ARR       htim1.Instance->ARR
//按键判断宏定义

#define Switch_Detect(num) HAL_GPIO_ReadPin(Key1_GPIO_Port);

typedef enum
{
    System_Run  = 0x00,
    System_Stop = 0x01,
}Sys_State;

//开关
typedef enum
{
    ON  = 0x01,
    OFF = 0x00,
}Switch;


typedef struct 
{
    GPIO_TypeDef * Port;
    uint16_t Pin;
}LED_Switch;

extern LED_Switch LED_Switch_Handle[4];
extern Switch Time_Set_Flag;
extern Switch LED_State_Flag[4];
extern uint32_t PWM_Channel[4];

#define LED_KEYJUDGE(num) HAL_GPIO_ReadPin(LED_Switch_Handle[num].Port,LED_Switch_Handle[num].Pin)

void System_Init();
void System_DeInit();
bool System_OLED_Start(int NUM);
bool System_OLED_Stop(int NUM);
void System_LED_VoltCon(int NUM,float brightness);

void LED_Func_SwitchCon();

void Task_Do();
void Task_Init();



#endif // DEBUG
