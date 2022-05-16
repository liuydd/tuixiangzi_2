#include<bits/stdc++.h>
#include "user.h"
#include<conio.h>
#include<fstream>
using namespace std;
const int M = 10;
User user[M];
User::User() {}
void User::SaveData() {
	ofstream sfile;
	sfile.open("user.txt", ios::out);
	for (int i = 0; i < count; i++) {
		sfile << user[i].name << endl;
		sfile << user[i].password << endl;
	}
	sfile.close();
}

void User::ReadData() {
	ifstream rfile;
	rfile.open("user.txt", ios::in);
	if (!rfile.is_open()) {
		return;
	}
	else {
		for (int i = 0; !rfile.eof(); i++) {
			rfile >> user[i].name;
			rfile >> user[i].password;
			count++;
		}
	}
	count--;
	rfile.close();
}

void User::Register() {
	User::ReadData();
	string name2;
	char pw1, pw2;
	char password1[30];
	char password2[30];
	int x = 0;
	int x1 = 0;
	for (int i = count; i < M; i++) {
	here://有没有什么方法不用goto但是如果不符合注册规则可以重新这一次？
		cout << "Please input your username." << endl;
		cin >> name2;   //这里还要改一下，应该设计成不包括空格
		for (int i = 0; i < count; i++) {
			if (name2 == user[i].name) {
				cout << "The username has been here,please try another." << endl;
				goto here;
			}
		}

		user[i].name = name2;
		cout << "Please input your password." << endl;

		while ((pw1 = _getch()) != '\r' && x <= 30) {  //不是回车和超出范围
			if (pw1 == '\b') {  //退格
				if (x > 0) {
					x--;
					cout << "\b \b";
				}
				else putchar(7);  //发出警告
			}
			else {
				password1[x++] = pw1;
				cout << '*';

			}
		}
		password1[x] = '\0';   //密码输入结束
		cout << endl;
		user[i].password = password1;
		//检查两次密码是否一致
		cout << "Please input your password again." << endl;
		while ((pw2 = _getch()) != '\r' && x1 <= 30) {  //不是回车和超出范围
			if (pw2 == '\b') {  //退格
				if (x1 > 0) {
					x1--;
					cout << "\b \b";
				}
				else putchar(7);  //发出警告
			}
			else {
				password2[x1++] = pw2;
				cout << '*';

			}
		}
		password2[x1] = '\0';   //密码输入结束
		cout << endl;
		if (user[i].password == password2) {   //为什么这里不能写password1==password2？
			count++;
			cout << "Congratulations for your successful register!" << endl;
			User::SaveData();
			break;   
		}
		else {
			cout << "Your password is different from the first one.";
			goto here;
		}
	}
}

void User::LogIn() {        //有什么办法能将注册和登陆统一起来？感觉写两遍代码好麻烦。登陆多一个判断环节，注册多一个循环
	User::ReadData();
	string name_;
	char pw_;
	char password_[30];
	int x = 0;
	int time = 0;
	cout << "Please input your username." << endl;
here:
	cin >> name_;
	cout << "Please input your password." << endl;
	while ((pw_ = _getch()) != '\r' && x <= 30) {  //不是回车和超出范围
		if (pw_ == '\b') {  //退格
			if (x > 0) {
				x--;
				cout << "\b \b";
			}
			else putchar(7);  //发出警告
		}
		else {
			password_[x++] = pw_;
			cout << '*';
		}
	}
	password_[x] = '\0';   //密码输入结束
	cout << endl;
	for (int i = 0; i < count; i++) {
		if (name_ == user[i].name && password_ == user[i].password) {
			time++;
			cout << "Log in successfully!" << endl;
			break;
		}
	}
	if (time == 0) {
		cout << "The name does not exist or the password is wrong." << endl;
		cout << "Please try again." << endl;
		goto here;
	}
}