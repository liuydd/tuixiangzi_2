#pragma once
#include<bits/stdc++.h>
using namespace std;
#ifndef _OPERATE_H
#define _OPERATE_H
class Operate {
public:
	bool Judge(int map[8][8]);
	void Move(int map[8][8],char ch);
	void Print(int map[8][8]);
	void Regret();
private:
	int step=0;
	int scene;//场景数
	int next;//关卡数
	int end;
	int r, c;//坐标
	char key;
	void Position(int map[8][8]);
};
#endif
