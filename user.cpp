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
	here://��û��ʲô��������goto�������������ע��������������һ�Σ�
		cout << "Please input your username." << endl;
		cin >> name2;   //���ﻹҪ��һ�£�Ӧ����Ƴɲ������ո�
		for (int i = 0; i < count; i++) {
			if (name2 == user[i].name) {
				cout << "The username has been here,please try another." << endl;
				goto here;
			}
		}

		user[i].name = name2;
		cout << "Please input your password." << endl;

		while ((pw1 = _getch()) != '\r' && x <= 30) {  //���ǻس��ͳ�����Χ
			if (pw1 == '\b') {  //�˸�
				if (x > 0) {
					x--;
					cout << "\b \b";
				}
				else putchar(7);  //��������
			}
			else {
				password1[x++] = pw1;
				cout << '*';

			}
		}
		password1[x] = '\0';   //�����������
		cout << endl;
		user[i].password = password1;
		//������������Ƿ�һ��
		cout << "Please input your password again." << endl;
		while ((pw2 = _getch()) != '\r' && x1 <= 30) {  //���ǻس��ͳ�����Χ
			if (pw2 == '\b') {  //�˸�
				if (x1 > 0) {
					x1--;
					cout << "\b \b";
				}
				else putchar(7);  //��������
			}
			else {
				password2[x1++] = pw2;
				cout << '*';

			}
		}
		password2[x1] = '\0';   //�����������
		cout << endl;
		if (user[i].password == password2) {   //Ϊʲô���ﲻ��дpassword1==password2��
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

void User::LogIn() {        //��ʲô�취�ܽ�ע��͵�½ͳһ�������о�д���������鷳����½��һ���жϻ��ڣ�ע���һ��ѭ��
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
	while ((pw_ = _getch()) != '\r' && x <= 30) {  //���ǻس��ͳ�����Χ
		if (pw_ == '\b') {  //�˸�
			if (x > 0) {
				x--;
				cout << "\b \b";
			}
			else putchar(7);  //��������
		}
		else {
			password_[x++] = pw_;
			cout << '*';
		}
	}
	password_[x] = '\0';   //�����������
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