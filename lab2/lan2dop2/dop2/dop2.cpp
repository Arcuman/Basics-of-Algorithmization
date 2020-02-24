#include "pch.h"
#include <iostream>
#include<iomanip>
#include <string>
# define str_len 30  
using namespace std;

struct Train {
	char path[str_len];
	int number;
	int hour;
	int minute;
};

struct Train TrList[8];
struct Train clear;
int position = 0;

void new_tr() {
	if (position < 8) {
		cout << "Номер Поезда: " << position + 1 << '\n';
		cout << "Введите место назначения поезда: ";
		cin >> TrList[position].path;
		cout << "Номер поезда: ";
		cin >> TrList[position].number;
		cout << "Время отправки(часы + минуты): ";
		cin >> TrList[position].hour;
		cin >> TrList[position].minute;

		position++;
	}
	else cout << "База данных переполнена!\n";
}

void infoshow() {
	cout << "\n\t       Место назначения \t   Номер поезда \t     Время отправки\n";
	for (int i = 0; i < position; i++) {
		cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
		if (TrList[i].hour < 10) cout << '0';
		cout << TrList[i].hour << ':';
		if (TrList[i].minute < 10) cout << '0';
		cout << TrList[i].minute << endl;
	}
}

void searchingTrain() {
	int th, tm,n =0;
	cout << "Введите время, после которого должен отправиться поезд в течении часа(часы + минуты): ";
	cin >> th; cin >> tm;
	cout << "\n\t       Место назначения \t   Номер поезда \t    Время отправки\n";
	for (int i = 0; i < position; i++)
	{
		if (((th * 60) + tm <= (TrList[i].hour * 60) + TrList[i].minute) && ((th * 60) + tm + 60 >= (TrList[i].hour * 60) + TrList[i].minute)) 
			{
		cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
			if (TrList[i].hour < 10) cout << '0';
			cout << TrList[i].hour << ':';
			if (TrList[i].minute < 10) cout << '0';
			cout << TrList[i].minute << endl;
			n++;
		}
	}
	if (!n)
	{
		cout << "\t\tНет поездов отправляющихся в ближайший час "<<endl;
	}
}

void automat() {
	position = 4;
	TrList[0] = { "Molodechno",32, 8 , 14 };
	TrList[1] = { "Gomel",42, 11 , 45 };
	TrList[2] = { "Minsk",18, 15, 25 };
	TrList[3] = { "Arbelsk",10, 19 , 22 };
}

void main() {
	setlocale(LC_CTYPE, "Rus");
	int k;
	automat();
	do
	{
		cout << "1) Ввод данных в базу\n";
		cout << "2) Вывод данных всей базы\n";
		cout << "3) Поиск поезда по времени\n";
		cout << "4) Выход из терминала\n";
		cout << "Ввод номера комады: ";
		cin >> k;
		cout << "\n---------------------------------\n";
		switch (k)
		{
		case 1: new_tr(); break;
		case 2: infoshow(); break;
		case 3: searchingTrain(); break;
		default: cout << "Неверная команда!";  break;
		}
		cout << "\n---------------------------------\n";
	} while (k != 4);
	system("pause");
}