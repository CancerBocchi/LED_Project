#include "LED_Project.h"

uint8_t Sec;
uint8_t Min;
uint8_t Hour;

LED_Switch LED_Switch_Handle[4] = { {Key1_GPIO_Port,Key1_Pin},
                                    {Key2_GPIO_Port,Key2_Pin},
                                    {Key3_GPIO_Port,Key3_Pin},
                                    {Key4_GPIO_Port,Key4_Pin}  }; 

void LED_Func_SwitchCon()
{
    for(int i = 0; i<4 ; i++)
    {
        if( !LED_KEYJUDGE(i) && LED_State_Flag[i] == ON )
        {
            System_OLED_Stop(i);
        }
        else if( LED_KEYJUDGE(i) && LED_State_Flag[i] == OFF )
        {
            System_OLED_Start(i);
        }
    }
}