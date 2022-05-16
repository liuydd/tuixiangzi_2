#include<bits/stdc++.h>
#include<conio.h>
#include "menu.h"
#include "user.h"
#include "operate.h"
using namespace std;
int vis = 0;
int step = 0;
int v = 0;
void Menu::ShowChosemap(int map[10][10], int lastmap[2999][10][10]) {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << chosemap[i][j];
		}
	}
	char ans;
	ans = _getch();
	switch (ans) {
	case 'q':case 'Q'://回到当前游戏界面
		break;
	case 'a':case 'A'://重开搞定了！
		Operate o;
			o.remake(map, lastmap);
		break;
	}
}
void Menu::ShowMenu1() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << menu1[i][j];
		}
	}
	char ans;
	ans = _getch();
	switch (ans) {
	case's':case'S':
		ShowStyle();
		break;
	case'c':case'C':
		ShowInstruction();
		break;
	}

}
void Menu::ShowInstruction() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			cout << instruction[i][j];
		}
	}
	char ans;
	ans = _getch();
	if (ans == 'q') {
		ShowMenu1();
	}
}
void Menu::ShowRegisterlogin() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << register_login[i][j];
		}
	}
	User myuser;
	char ans;
	ans = _getch();
	switch (ans) {
	case 'r':case 'R':
		system("cls");
		myuser.Register();
		break;
	case 'l':case 'L':
		system("cls");
		myuser.LogIn();
		break;
	}
}
void Menu::ShowStyle() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << style[i][j];
		}
	}
	char ans;
	ans = _getch();
	switch (ans) {
	case 'c':case 'C':
		v = 1;
		ShowDegree();
		break;
	case 'i':case 'I':
		v = 2;
		break;
	}
}
void Menu::ShowDegree() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << degree[i][j];
		}
	}
	char ans;
	ans = _getch();
	switch (ans) {
	case 'e':case 'E':
		vis = 1;
		break;
	case 'n':case 'N':
		vis = 2;
		break;
	case 'd':case 'D':
		vis = 3;
		break;
	}
};
