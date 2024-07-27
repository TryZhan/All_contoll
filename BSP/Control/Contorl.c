#include "Control.h"

float Velocity_D = 0,Velocity_I = 0;					//�ٶȻ�KP��KI

int Velocity_out,PWM_out;								//�ٶȻ������
int Moto1,Moto2;												//��������������
int Encoder_Left,Encoder_Right;

//void EXTI9_5_IRQHandler(void)								//�жϷ������
//{
//	if(EXTI_GetITStatus(EXTI_Line5) != 0)				//��IT��־λ��Ϊ0����ʾ�����ж�
//	{
//		if(PBin(5) == 0)										//�ж�Ϊ�½��ش�������������Ϊ�͵�ƽ���ɴ��ٴ��ж�
//		{
//			EXTI_ClearITPendingBit(EXTI_Line5);		
//			
//			//1.�ɼ�����������ֵ
//			Encoder_Left = -Read_Speed(2);				//���������԰�װ��������������ת180�㣬��ֵ�෴��Ϊ���ñ������������һ�£���Ҫȡ��
//			Encoder_Right = Read_Speed(4);
//			
//			//2.�Ѳɼ���������ѹ���ٶȱջ������С��������������
//			Velocity_out = Velocity_Con(Encoder_Left,Encoder_Right);
//			
//			PWM_out = Vertical_out + Vertical_P * Velocity_out;			//�������
//			//3.����������ص��������ɿ���
//			Moto1 = PWM_out - Turn_out;							//����
//			Moto2 = PWM_out + Turn_out;							//�ҵ��
//			M1 = Moto1;
//			M2 = Moto2;
//			Limit(&Moto1,&Moto2);
//			Load(Moto1,Moto2);
//		}
//	}	
//}

/*************
*Ѳ��λ��ʽPID
*��ʽΪ��
*��ڲ�����opencv���
*���ز�����������ٴ��
*************/




/*************
*�ٶȻ�����
*��ʽΪ��Velocity_out =Kp2*(Encoder_ real- Encoder_ expect)+Ki*S(Encoder_ real- Encoder_ expect)
*��ڲ��������ұ��������ٶ�
*���ز������ٶȻ�pid���
*************/
int Velocity_Con(int Encoder_Left,int Encoder_Right)
{
	static int PWM_out,Enc_ERR,Enc_ERR_Lowout,Enc_ERR_Lowout_Last,Enc_ERR_S;
	float a = 0.7;																		//���ϵ���������ڵ�ͨ�˲����ϵģ�Ҫͻ������һ���ֵ��źţ�һ�����0.5����
	//1.�����ٶ����
	Enc_ERR = (Encoder_Left + Encoder_Right) - 0;							//�����0��Ԥ��ֵ�����ٶ�Ϊ�㾲ֹ�������ֵ��Ϊ�˷�ֹ�������			
	//2.�ٶȻ����������ֱ�����ȶ������һ����ͨ�˲�����ֹ��Ƶ����
	//LPF��ʽ���˲����=a*��һ�β���ֵ+(1-a)�����˲��Ľ��
	Enc_ERR_Lowout = (1 - a) * Enc_ERR + a * Enc_ERR_Lowout_Last;
	Enc_ERR_Lowout_Last = Enc_ERR_Lowout;
	//3.���ٶȽ��л��֣��ó�λ��
	Enc_ERR_S += Enc_ERR_Lowout;													//������
	//4.�Ի��ֽ����޷�
	Enc_ERR_S = Enc_ERR_S > 10000 ? 10000 : (Enc_ERR_S < (-10000) ? (-10000) : Enc_ERR_S);
	//5.�ٶȻ������������
	PWM_out = Velocity_D * Enc_ERR_Lowout + Velocity_I * Enc_ERR_S;
	
	return PWM_out;
}

