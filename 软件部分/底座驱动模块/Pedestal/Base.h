
#ifndef Base_h
#define Base_h

//#include <inttypes.h>
#include <Arduino.h>

/*编码器输出频率范围为在0~220HZ，为保险取250Hz为上限；时间间隔在4ms以上,即4000us;
输出频率对应转速为0~3转/s。试验中测得比值在70附近（主要测量范围在150mm/s到最大速度660mm/s）。

当PWM波占空比小于25/255时已无法转动，考虑到负载，应该在40左右，待测。
*/
#define Wheel_Radius		35
#define Max_Rotating_Speed	3
#define Max_Speed			(2 * 3.14*Wheel_Radius*Max_Rotating_Speed) //最大速度为659.4mm/s
#define Min_PWM				50
#define	Min_Speed			(Min_PWM*Max_Speed/255)
#define	Encoder_Rate		70
#define	Encoder_Max_Freq	230
#define	Encoder_Min_Freq	(Min_PWM*Encoder_Max_Freq/255)	//
/******************************************************************************
* Definitionss
******************************************************************************/

//The position of the Infrared
//[        5 B+ 4         ]
//[2                	 0]
//[A-					A+]
//[3					 1]
//[		   7 B- 6		  ]
//
//define the Direction of Robot
#define A_Forward	1
#define A_Backward	2
#define B_Forward	3
#define B_Backward	4

//the position of the Motors
//the offset of the Base
//the rotate of the Base
#define A_Positive	1
#define A_Negative	2
#define B_Positive	3
#define B_Negative	4

//the DCMotor's
#define CW	1 			//顺时针
#define CCW 2			//逆时针
/*
class Encoder
{
private:
	int 	_S1Pin;		//传感器数据输出口
	//int 	_S2Pin;因为IO口不够，不测量正反转

public:
	//boolean 	Direction;		//正反转
	float 		Speed;			//速度
	Encoder(int S1Pin);		//初始化
	int Read_status();						//读取状态

	
};
直接写入MOtor类
*/
class DCMotor
{
private:
	int 	_IN1,_IN2;					//IN1=0,IN2=1 正转；IN1=1，IN2=0 反转；
	int 	_ControlPin;				//根据PWM占空比与转速的对应来控制速度；
	int		_EncoderPin;
public:
	boolean 	Direction;		//正反转
	float 		Speed;			//速度

	void init(int IN1, int IN2, int ControlPin, int EncoderPin);
	int DC_Control(byte Direct, float Speed);	//直流电机驱动,返回pwm值
	void DC_Control(byte Direct);
	int DC_Control(float Speed);
	
	int Read_Speed();						//读取状态
};




class Base
{
private:
	
	//int 	_pin[4];
	//int 	Path[4][2] = { { 0, 1 },{ 1, 1 }, { 1, 2 }, { 2, 2 } };


	//float 	Encoder(int Motor);								//码表读取函数
	//boolean Ired_Status(void);								//将红外数据读入ired
	

public:
	int		Direction;
	int 	RobotA, RobotB;										//当前世界坐标
	int		GoalA, GoalB;										//下一个目标点

	DCMotor _DCMotorA_Positive;
	DCMotor _DCMotorA_Negative;
	DCMotor _DCMotorB_Positive;
	DCMotor _DCMotorB_Negative;
	Base(int* DC_IN1, int* DC_IN2, int* DC_ENABLE,int* Encoder_PIN);
	boolean Walk(byte Direct, int Speed, int Time);				//底座行走函数
	boolean Walk(byte Direct, int Speed);
	boolean Rotate(byte Direct, int Speed, int time);			//底座转动函数

	boolean Basic_Walk(byte offset);							//平动一丁点
	boolean Basic_Rotate(byte offset);							//转动一丁点

	int		Detect_Direct();									//根据当前坐标与目的坐标判断运动方向

	//boolean	AimWalk();											//走到目标坐标

	int*	splitcommand(String command, char flag,int length);			//通讯中从字符串拆分成int数组。
	//boolean Robot_Location(void);

};



// Arduino 0012 workaround
#undef int
#undef char
#undef long
#undef byte
#undef float
#undef abs
#undef round

#endif