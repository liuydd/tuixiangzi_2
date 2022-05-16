#include<bits/stdc++.h>
#include<fstream>
#include <sstream>
#include "map.h"
#include "operate.h"
using namespace std;
Map::Map(){}
Map::~Map() {}
bool Map::ReadMap(int map[10][10], const char* filename) {
	ifstream read;
	read.open(filename, ios::in);
	if (!read.is_open()) {
		cout << "fail to open the file." << endl;
		return false;
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				read >> map[i][j];
		}
		return true;
	}
}