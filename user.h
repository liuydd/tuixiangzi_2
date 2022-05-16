#pragma once
#include<string>
using namespace std;
#ifndef _USER_H
#define _USER_H
class User {
public:
	User();
	void Register();
	void LogIn();
	void SaveData();
	void ReadData();
private:
	string password;
	string name;
	int count = 0;
};
/*
class LogIn :public User {
	LogIn();
	void login();
private:
	int time = 0;
};
*/
#endif

