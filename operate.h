#pragma once
#include<bits/stdc++.h>
using namespace std;
#ifndef _OPERATE_H
#define _OPERATE_H
extern int step;
class Operate {
public:
	bool Judge(int map[10][10]);
	void Move(int map[10][10], int lastmap[2999][10][10], char ch);
	void Print(int map[10][10]);
	void goback(int map[10][10],int lastmap[2999][10][10]);
	void reversepre(int map[10][10], int lastmap[2999][10][10]);
	void remake(int map[10][10],int lastmap[2999][10][10]);
private:
	//int step=0;
	int next;//¹Ø¿¨Êý
	int r, c;//×ø±ê
	char key;
	void Position(int map[10][10]);
};
#endif
