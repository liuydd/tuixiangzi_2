#pragma once
#include<bits/stdc++.h>
using namespace std;
#ifndef _MAP_H
#define _MAP_H
class Map {
public:
	Map();
	~Map();
	bool ReadMap(int map[10][10], const char* filename);
};
#endif
