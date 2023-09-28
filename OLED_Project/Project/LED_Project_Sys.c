#include "LED_Project.h"
#include "math.h"

//定时打开功能标志位
Switch LED_Time_Set_Flag;
//LED状态标志位
Switch LED_State_Flag[4];

uint32_t PWM_Channel[4] = { TIM_CHANNEL_1,
                            TIM_CHANNEL_2,
                            TIM_CHANNEL_3,
                            TIM_CHANNEL_4};


void System_Init()
{
    LED_State_Flag[0] = OFF;
    LED_State_Flag[1] = OFF;
    LED_State_Flag[2] = OFF;
    LED_State_Flag[3] = OFF;

    HAL_TIM_Base_Start(&htim1);
    OLED_Init();

}

void System_DeInit()
{
    HAL_TIM_Base_Stop(&htim1);
}

/**
 * @brief LED 开关接口函数
 * 
 * @param NUM 
 * @return true  开关成功
 * @return false 已经开/关 避免重复操作
 */
bool System_OLED_Start(int NUM)
{
    if(!LED_State_Flag[NUM-1])
    {
        HAL_TIM_PWM_Start(&htim1,PWM_Channel[NUM-1]);
        LED_State_Flag[NUM-1] = ON;
        return true;
    }
    return false;
}

bool System_OLED_Stop(int NUM)
{
    if(LED_State_Flag[NUM-1])
    {
        HAL_TIM_PWM_Stop(&htim1,PWM_Channel[NUM-1]);
        LED_State_Flag[NUM-1] = OFF;
        return true;
        
    }
    return false;
}

/**
 * @brief 电压控制接口函数
 * 
 * @param NUM 通道序号
 * @param brightness 亮度（0.1-0.9） 
 */
void System_LED_VoltCon(int NUM,float brightness)
{
    switch (NUM)
    {
    case 1:
        PWM_VOLTCON_1 = (int)(brightness * (float)PWM_ARR);
        break;
    case 2:
        PWM_VOLTCON_2 = (int)(brightness * (float)PWM_ARR);
        break;
    case 3:
        PWM_VOLTCON_3 = (int)(brightness * (float)PWM_ARR);
        break;
    case 4:
        PWM_VOLTCON_4 = (int)(brightness * (float)PWM_ARR);
        break;
    }
}