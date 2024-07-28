#include "Line_Follow.h"

/**
* Function       GetLineWalking
* @brief         获取巡线状态
* @param[in]     int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2  四路巡线位指针
* @param[out]    void
* @retval        void
* @par History   无
*/
void GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2)
{
		*p_iL1 = DL_GPIO_readPins(GPIO_LineGet_PORT, GPIO_LineGet_PIN_Line_Left1_PIN);
		*p_iL2 = DL_GPIO_readPins(GPIO_LineGet_PORT, GPIO_LineGet_PIN_Line_Left2_PIN);
		*p_iR1 = DL_GPIO_readPins(GPIO_LineGet_PORT, GPIO_LineGet_PIN_Line_Right1_PIN);
		*p_iR2 = DL_GPIO_readPins(GPIO_LineGet_PORT, GPIO_LineGet_PIN_Line_Right2_PIN);	
}

/**
* Function       LineWalking  
* @brief         差速转向
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/


/**
* Function       LineWalking  
* @brief         巡线模式运动
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	//获取黑线检测状态	

	if( (LineL2 == LOW || LineR1 == LOW) && LineR2 == LOW) //右锐角：右大弯,low表示检测到黑线
    {
      	Motor_TurnRight(0.4);
		delay_ms(20);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineL2 == LOW)) //左锐角左大弯
	{ 
      	Motor_Turnleft(0.4);
		delay_ms(20);
    }  
    else if( LineL1 == LOW ) //左最外侧检测
    {  
		Motor_Turnleft(0.4);
		delay_ms(10);
	}
    else if ( LineR2 == LOW) //右最外侧检测
    {  
		Motor_TurnRight(0.4);
		delay_ms(10);
	}
    else if (LineL2 == LOW && LineR1 == HIGH) //中间黑线上的传感器微调车左转
    {   
		Motor_Turnleft(0.4);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW) //中间黑线上的传感器微调车右转
    {   
		Motor_TurnRight(0.4);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // 都是黑色, 加速前进
    {  
		Motor_straight(0.3);
	}	
}
