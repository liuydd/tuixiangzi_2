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
	int scene;//������
	int next;//�ؿ���
	int end;
	int r, c;//����
	char key;
	void Position(int map[8][8]);
};
#endif
