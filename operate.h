#pragma once
#include<bits/stdc++.h>
using namespace std;
#ifndef _OPERATE_H
#define _OPERATE_H
extern int step;
class Operate {
public:
	bool Judge(int map[8][8]);
	void Move(int map[8][8], int lastmap[][8][8], char ch);
	void Print(int map[8][8]);
	void goback(int map[8][8],int lastmap[][8][8]);
	void reversepre(int map[8][8], int lastmap[][8][8]);
	void remake(int map[8][8],int lastmap[][8][8]);
private:
	//int step=0;
	int next;//¹Ø¿¨Êý
	int r, c;//×ø±ê
	char key;
	void Position(int map[8][8]);
};
#endif
