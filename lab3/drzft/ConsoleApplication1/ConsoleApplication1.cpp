// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<iomanip>
#include <string>

using namespace std;

struct Train {
	string path;
	int number;
	int hour;
	int minute;
};

struct Train TrList[8];
struct Train clear;
int position = 0;

void new_tr() {
	if (position < 8) {
		cout << "Номер гражданина: " << position + 1 << '\n';
		cout << "Введите место назначения поезда: ";
		cin >> TrList[position].path;
		cout << "Номер поезда: ";
		cin >> TrList[position].number;
		cout << "Время отправки(часы + минуты): ";
		cin >> TrList[position].hour;
		cin >> TrList[position].minute;
		position++;
		cout << "\nБлагодарим за данные! Слава Арстоцке!\n";
	}
	else cout << "База данных переполнена!\n";
}

void sort() {
	for (int i = 0; i < position; i++)
		for (int j = i; j < position; j++)
			if (TrList[i].path > TrList[j].path) {
				swap(TrList[j], TrList[i]);
			}
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

void searchingNumber() {
	int c;
	cout << "ID поезда, которого требуется информация для вывода: ";
	cin >> c;
	cout << "Место назначения: " << TrList[c - 1].path;
	cout << "\nНомер поезда: " << TrList[c - 1].number;
	cout << "\nВремя отправки: ";
	if (TrList[c - 1].hour < 10) cout << '0';
	cout << TrList[c - 1].hour << ':';
	if (TrList[c - 1].minute < 10) cout << '0';
	cout << TrList[c - 1].minute;
}

void searchingTrain() {
	int th, tm;
	cout << "Введите время, с которой должен отправиться поезд(часы + минуты): ";
	cin >> th; cin >> tm;
	cout << "\n\t       Место назначения \t   Номер поезда \t    Время отправки\n";
	for (int i = 0; i < position; i++) {
		if ((th * 60) + tm <= (TrList[i].hour * 60) + TrList[i].minute) {
			cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
			if (TrList[i].hour < 10) cout << '0';
			cout << TrList[i].hour << ':';
			if (TrList[i].minute < 10) cout << '0';
			cout << TrList[i].minute << endl;
		}
	}
}

void automat() {
	position = 5;
	TrList[0].path = "Zhigulovsk"; TrList[0].hour = 12; TrList[0].minute = 30;
	TrList[1].path = "Molodechno"; TrList[1].hour = 8; TrList[1].minute = 14;
	TrList[2].path = "Gomel"; TrList[2].hour = 11; TrList[2].minute = 45;
	TrList[3].path = "Minsk"; TrList[3].hour = 15; TrList[3].minute = 25;
	TrList[4].path = "Arbelsk"; TrList[4].hour = 19; TrList[4].minute = 22;
	sort();
}

void main() {
	setlocale(LC_CTYPE, "Rus");
	int k;
	cout << "\t\t\t\t  ROBCO INDUSTRIES UNIFIED OPERATING SYSTEM\n";
	cout << "\t\t\t\t    COPYRIGHT 2075-2077 ROBCO INDUSTRIES\n";
	automat();
	do
	{
		cout << "1) Ввод данных в базу\n";
		cout << "2) Вывод данных всей базы\n";
		cout << "3) Поиск данных\n";
		cout << "4) Поиск поезда по времени\n";
		cout << "5) Выход из терминала\n";
		cout << "Ввод номера комады: ";
		cin >> k;
		cout << "\n---------------------------------\n";
		switch (k)
		{
		case 1: new_tr(); sort(); break;
		case 2: infoshow(); break;
		case 3: searchingNumber(); break;
		case 4: searchingTrain(); break;
		case 5: break;
		default: cout << "Неверная команда!";  break;
		}
		cout << "\n---------------------------------\n";
	} while (k != 5);
	system("pause");
}