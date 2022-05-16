#include<bits/stdc++.h>
#include<conio.h>
#include "game.h"
#include "operate.h"
#include "map.h"
#include "user.h"
#include "menu.h"
using namespace std;

int main() {
	Menu menu;
	menu.ShowRegisterlogin();
	menu.ShowMenu1();
	int map[8][8] = { 0 };
	int lastmap[][8][8] = { 0 };
	int num=0;
		while (num < 5) {
			Operate operate;
			Map map_;
			bool is_map = 1;
			if (vis == 1) {//简单难度
				string map_num = "map/map_0" + to_string(num) + ".txt";
				const char* map_filename = map_num.c_str();
				map_.ReadMap(map, map_filename);
				
			}
			else if (vis == 2) {//中等难度
				string map_num = "map/map_1" + to_string(num) + ".txt";
				const char* map_filename = map_num.c_str();
				map_.ReadMap(map, map_filename);
				
			}
			else if (vis == 3) {//困难难度
				string map_num = "map/map_2" + to_string(num) + ".txt";
				const char* map_filename = map_num.c_str();
				map_.ReadMap(map, map_filename);
				
			}
			
			if (!is_map)
				return -1;
			
			while (operate.Judge(map)) {
				system("cls");
				operate.Print(map);
				char key;
				key = _getch();
				operate.Move(map,lastmap, key);
				system("cls");
			}
			num++;
			cout << "Congratulations for your successfully passed the " << num << " map！" << endl;
			system("pause");
			
		}
	
	return 0;
}
