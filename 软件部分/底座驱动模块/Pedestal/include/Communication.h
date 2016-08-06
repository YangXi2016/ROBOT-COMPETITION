#ifndef Communication_h
#define Communication_h

#include "Wire.h"

/*
//IIC通讯相关协议
Pedestal做主机，Spectror做从机；
Pedestal运行中实时查询Spector状态；Spector返回格式如下：

AP;AN;BP;BN;

单个巡线模块状态：
CW；CCW；Online；Offline

Pedestal到达一个十字路口时做一次坐标校准。（没必要吧？）

Pedestal在巡直线的过程中，不断询问Spector巡线情况。
Spector全程监控，每当Pedestal询问时，返回状态，其优先级done>bias>offset。

*/

/******************************************************************************
* Definitions
******************************************************************************/
//The position of the Infrared
//[        5 B+ 4         ]
//[2                	 0]
//[A-		 9	 		A+]
//[3					 1]
//[		   7 B- 6		  ]
//
//define the Direction of Robot
#define A_Forward	1
#define A_Backward	2
#define B_Forward	3
#define B_Backward	4
//define the offset of Robot
//the offset is the paralle offset
#define NoneOffset	0
#define A_Positive	1
#define A_Negative	2
#define B_Positive	3
#define B_Negative	4
#define OffCentral	5

//the bias of motor

#define CW	1 			//顺时针(A轴上轮子以向B+运动为顺时针；B轴上轮子以向A+运动为顺时针)
#define CCW 2			//逆时针
#define Online	3
#define Offline 4


#define	Status_Cross			1
#define	Status_Line				0

#define	Slave_Adress	1	//IIC通讯中从机地址
#define	IIC_Bytes		7	//IIC通讯格式	AP;AN;BP;BN


//与上位机通讯协议
//#define	Serial.println()


//与spector通讯协议

int*	splitcommand(String command, char flag, int length);			//通讯中从字符串拆分成int数组。
int*	IICcommand(String command, char flag, int length);

void	Send_Direct(int Adress,int Direct);								//向巡线模块发送前进方向
String	Read_Status(int Adress, int bytes);								//从巡线模块获取当前状态

#endif