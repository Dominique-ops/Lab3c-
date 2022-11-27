#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "FIO.h"
using namespace std;

class Bank {
private:
    friend void sort(Bank*);
    friend void addsum(Bank*);
    FIO client;
    int id;
    double sum;
public:
    static int counter;

    Bank();
    Bank(int, int, FIO);
    Bank(Bank*);
    static void addperson(Bank*);
    static void saveperson(Bank*);
    static void loadperson(Bank*);
    static void display(Bank*);
    int Getid();
    double Getsum();
    char* Getname();
    char* Getsurname();
    char* Getoname();
    ~Bank();

    void operator+(int value)
    {
        this->sum += value;
    }

};