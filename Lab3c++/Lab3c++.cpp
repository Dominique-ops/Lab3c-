#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "Bank.h"
#include "FIO.h"

using namespace std;




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    class Bank* mas = new Bank[4];
    ifstream file;
    file.open("DataBase.txt");
    if (!file.is_open())
    {
        cout << "Файл не обнаружен, создание новой базы данных!" << endl;
        Bank::addperson(mas);
    }
    else {
        Bank::loadperson(mas);
    }
    while (true)
    {
        int  item = 0;
        printf_s("                                     \n");
        printf_s("- Добавить новый счет             1 -\n");
        printf_s("- Информация о счете              2 -\n");
        printf_s("- сортировка по алфавиту          3 -\n");
        printf_s("- добавить к сумме                4 -\n");
        printf_s("- Выход из программы              5 -\n");
        printf_s("                                     \n");
        printf_s("- Введите номер функции: ");
        while (scanf_s("%d", &item) != 1 || item > 6 || item < 1) {
            printf_s("- ошибка\n");
            printf_s("                          \n");
            printf_s("- Введите номер функции: ");
            while (fgetc(stdin) != '\n');
        }
        printf_s("                                   \n\n");
        switch (item)
        {
        case 1:
            Bank::addperson(mas);
            break;
        case 2:
            Bank::display(mas);
            break;
        case 3:
            sort(mas);
            break;
        case 4:
            addsum(mas);
            break;
        case 5:
            Bank::saveperson(mas);
            break;
        }
       
    }
    return 0;
}