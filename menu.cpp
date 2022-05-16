#include<bits/stdc++.h>
#include<conio.h>
#include "menu.h"
#include "user.h"
using namespace std;
bool ft = true;
int vis = 0;
void Menu::ShowChosemap() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			cout << chosemap[i][j];
		}
	}
	char ans;
	ans = _getch();
	switch (ans) {
	case 'q':case 'Q':
		ShowMenu1();
		break;
	case 'a':case 'A'://这里实现不了orz
		//to do!!!（怎样重新开始这一局）
		ft = false;
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
		ShowDegree();
		break;
	case 'i':case 'I':
		//to do!!!
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
