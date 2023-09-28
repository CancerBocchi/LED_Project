#include "LED_Project.h"

void Task_Init()
{
    System_Init();
    System_OLED_Start(1);
    System_OLED_Start(2);
    System_OLED_Start(3);
    System_OLED_Start(4);
    System_LED_VoltCon(1,99*0.01f);
    System_LED_VoltCon(2,99*0.01f);
    System_LED_VoltCon(3,99*0.01f);
    System_LED_VoltCon(4,99*0.01f);

}

void Task_Do()
{
    // static int temp[4] = {1,2,3,4};
    // int duty[4];
    // for(int i = 0 ; i<4 ; i++)
    // {
    //     duty[i] = temp[i]%100 + 1;
    //     temp[i]++;
    // }
    // System_LED_VoltCon(1,duty[0]*0.01f);
    // System_LED_VoltCon(2,duty[1]*0.01f);
    // System_LED_VoltCon(3,duty[2]*0.01f);
    // System_LED_VoltCon(4,duty[3]*0.01f);
    // LED_Func_SwitchCon();
    // HAL_Delay(100);
    if(HAL_GPIO_ReadPin(Key1_GPIO_Port,Key1_Pin))
    {
        System_OLED_Start(1);
    }
    else
    {
        System_OLED_Stop(1);
    }
    OLED_Screen();

}