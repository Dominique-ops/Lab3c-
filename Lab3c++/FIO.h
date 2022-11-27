#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FIO
{
	friend class Bank;
private:
	char* name;
	char* surname;
	char* oname;
public:
	FIO();
	FIO(char*, char*, char*);
};

