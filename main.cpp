#include<bits/stdc++.h>
#include<conio.h>
#include "operate.h"
#include "map.h"
#include "user.h"
#include "menu.h"
using namespace std;

int main() {
	Menu menu;
	menu.ShowRegisterlogin();
	menu.ShowMenu1();
	int map[10][10] = { 0 };
	int lastmap[2999][10][10] = { 0 };
	int num=0;
	switch (v) {
	case 1://闯关模式
		while (num < 5) {
			h:
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
				if (key == 't') {
					if (num < 4) {
						num++;
						step = 0;
						goto h;
					}
					else if (num == 4) {
						num = 0;
						step = 0;
						goto h;
					}
				}
				operate.Move(map, lastmap, key);
				system("cls");
			}
			num++;
			step = 0;
			cout << "Congratulations for your successfully passed the " << num << " map！" << endl;
			system("pause");
		}
		menu.ShowMenu1();
		break;
	case 2://无限模式
		while (num < 20) {
			h2:
			Operate operate;
			Map _map;
			bool is_map = 1;
			string map_num = "map/map" + to_string(num) + ".txt";
			const char* map_filename = map_num.c_str();
			_map.ReadMap(map, map_filename);
			if (!is_map)
				return -1;
			while (operate.Judge(map)) {
				system("cls");
				operate.Print(map);
				char key;
				key = _getch();
				if (key == 't') {
					if (num < 19) {
						num++;
						step = 0;
						goto h2;
					}
					else if (num == 19) {
						num = 0;
						step = 0;
						goto h2;
					}
				}
				operate.Move(map, lastmap, key);
				system("cls");
			}
			num++;
			step = 0;
			cout << "Congratulations for your successfully passed the " << num << " map！" << endl;
			system("pause");
		}
		menu.ShowMenu1();
		break;
	}
	return 0;
}
