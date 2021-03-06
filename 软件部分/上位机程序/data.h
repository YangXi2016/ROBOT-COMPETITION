#pragma once
//包含了一些常量和场上的策略信息
//包含了必要的信息转换函数
#include <iostream>
#include <sstream>
using namespace std;
using namespace cv;
///////////////////////////////////////////////////////////////////////////
//常量定义

//物品抓取时机器人应该处于的位置所处的位置的信息
//编号为A1到A12,B1到B12以此类推,这个是各自的uni_ID,查看uni_ID请转data.h最下角
int posi_A[48] = { 0,	0,	1,	1,	2,	2,	3,	3,	4,	4,	5,	5,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	9,	9,	8,	8,	7,	7,	6,	6,	5,	5,	4,	4,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1};
int posi_B[48] = { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1,	2,	2,	3,	3,	4,	4,	5,	5,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	8,	9,	9,	8,	8,	7,	7,	6,	6,	5,	5,	4,	4};

//目标物品的存放信息,物品所对应的存放信息,通过uni_ID来存储
//目标物品对应的情况请查看data.h底的obj_ID
int dest_obj_posi[15] = {1,2,4,5,9,10,12,19,21,24,28,35,39,45,46};//////////////////////////////////假数据
//int dest_obj_posi[15] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, };

//购物车放位置信息
//编号为0到14
int chart_A[15] = { 4,	4,	4,	4,	4,	4,	7,	7,	7,	6,	5,	4,	2,	2,	2};
int chart_B[15] = { 2,	2,	2,	2,	2,	2,	3,	4,	5,	7,	7,	7,	6,	5,	4};
int chart_C[15] = { 2,	2,	2,	2,	2,	2,	3,	4,	5,	7,	7,	7,	5,	5,	5};///////////////////////////////////////////瞎写的

//抓取物品的顺序信息
//对应于obj_ID
int sequence[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

//可能存放的物品的信息

//绕场一周的XY坐标顺序及个数
int round_A[12] = { 2,	4,	6,	8,	8,	8,	7,	5,	3,	1,	1,	1};
int round_B[12] = { 1,	1,	1,	2,	4,	6,	8,	8,	8,	7,	5,	3};
int rount_total = 12;

int round_D_A[6] = { 0,0,0,0,0,0 };
int round_D_B[6] = { 3,4,5,6,7,8 };

//目标物体的图像存储,其中存储顺序按照OBJ_ID
Mat obj_modA[17];
Mat obj_modB[17];
Mat obj_modC[17];
Mat obj_modD[17];
///////////////////////////////////////////////////////////////////////////


//每个格子的uni_ID
/*
A1	0
A2	1
A3	2
A4	3
A5	4
A6	5
A7	6
A8	7
A9	8
A10	9
A11	10
A12	11
B1	12
B2	13
B3	14
B4	15
B5	16
B6	17
B7	18
B8	19
B9	20
B10	21
B11	22
B12	23
C1	24
C2	25
C3	26
C4	27
C5	28
C6	29
C7	30
C8	31
C9	32
C10	33
C11	34
C12	35
D1	36
D2	37
D3	38
D4	39
D5	40
D6	41
D7	42
D8	43
D9	44
D10	45
D11	46
D12	47
*/

//每个目标物品的obj_ID
/*
黄色方砖	0
黄色方砖	1
黄色方砖	2
黄色方砖	3
黄色方砖	4
黄色方砖	5
红色方砖	6
绿色方砖	7
蓝色方砖	8
美年达	9
健怡可乐	10
雪碧		11
养乐多	12
QQ星		13
蒙牛纯牛奶	14
////////
纯牛奶字	15
*/