// 9 вариант
//

#include "pch.h"
#include <iostream>
#include<iomanip>
#include <string>
#include <conio.h>
# define str_len 30  
using namespace std;
enum DAYS { MON = 1, TUE, WED, THU, FRI, SAT, SUN }; // 

struct Train {
	string path;
	int number;
	unsigned int hour_in : 5 ; // 24  это 10111 
	unsigned int minute_in : 6; // 60 это 111100
	unsigned int hour_out : 5; // 24  это 10111 
	unsigned int minute_out : 6; // 60 это 111100
	DAYS day;
};
DAYS temp;
struct Train TrList[8];
struct Train clear;
int position = 0;
string enum_to_string(DAYS t); //Вывод дня недели


void new_tr() {
	if (position < 8) {
		int i;
		cout << "Номер гражданина: " << position + 1 << '\n';
		cout << "Введите место назначения поезда: ";
		cin >> TrList[position].path;
		cout << "Номер поезда: ";
		cin >> TrList[position].number;
		cout << "Время отправки: " << endl;
		cout << "Часы ";
		cin >> i;
		TrList[position].hour_in = i;
		cout << "Минуты ";
		cin >> i;
		TrList[position].minute_in = i;
		cout << "Время прибытия: " << endl;
		cout << "Часы ";
		cin >> i;
		TrList[position].hour_out = i;
		cout << "Минуты ";
		cin >> i;
		TrList[position].minute_out = i;
		cout << "Введите день следования(1-Понедельник): ";
		int input;
		cin >> input;
		TrList[position].day = static_cast<DAYS>(input); //присваевание значения enum
		position++;
	}
	else cout << "База данных переполнена!\n";
}

void sorttime() // Сортировка по дате отправления 
{
	for (int i = 0; i < position; i++)
		for (int j = i; j < position; j++)
			if (TrList[i].hour_in*60 + TrList[i].minute_in > TrList[j].hour_in * 60 + TrList[j].minute_in) {
				swap(TrList[j], TrList[i]);
			}
}
void sort() // Соритировка по месту назначения
{
	for (int i = 0; i < position; i++)
		for (int j = i; j < position; j++)
			if (TrList[i].path> TrList[j].path){
				swap(TrList[j], TrList[i]);
			}
}

void searchingNumber() //Вывод по месту назначения и дате 
{
	if (position == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	char mesto[30];
	cout << "Введите место назначения: ";
	cin >> mesto;
	cout << "Введите день недели от 1(Понедельник) до 7: ";
	int input;
	cin >> input;
	temp = static_cast<DAYS>(input); //присваевание значения enum
	
	cout << "\n\t       Место назначения \t   Номер поезда \t     Время отправки \t     Время прибытия\t     Дни следования\n";
	for (int i = 0; i < position; i++) {
			
		if ((temp == TrList[i].day) && (mesto == TrList[i].path))
		{
			cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
			if (TrList[i].hour_in < 10) cout << '0';
			cout << TrList[i].hour_in << ':';
			if (TrList[i].minute_in < 10) cout << '0';
			cout << TrList[i].minute_in << "\t" << setw(15);
			if (TrList[i].hour_in < 10) cout;
			cout << TrList[i].hour_out << ':';
			if (TrList[i].minute_in < 10) cout << '0';
			cout << TrList[i].minute_out << "\t" << setw(15);
			cout << enum_to_string(TrList[i].day) << endl;
		}
	}
}
string enum_to_string(DAYS t) {
	switch (t) {
	case MON:
		return "Понедельник";
	case TUE:
		return "Вторник";
	case WED:
		return "Среда";
	case THU:
		return "Четверг";
	case FRI:
		return "Пятница";
	case SAT:
		return "Суббота";
	case SUN:
		return "Воскресенье";
	default:
		return "INVALID ENUM";
	}
}
void infoshow() {
	if (position == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int choosehere;
	cout << "Сортировка по: " << endl;
	cout << "1) Месту назначинию " << endl;
	cout << "2) Времени отправления " << endl;
	cin >> choosehere;
	switch (choosehere) {
	case 1:
		sort();break;
	case 2:
		sorttime();break;
	}
	cout << "\n\t       Место назначения \t   Номер поезда \t     Время отправки \t     Время прибытия\t     День следования\n";
	for (int i = 0; i < position; i++) {
		cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
		if (TrList[i].hour_in < 10) cout << '0';
		cout << TrList[i].hour_in << ':';
		if (TrList[i].minute_in < 10) cout << '0';
		cout << TrList[i].minute_in <<"\t" << setw(15);
		if (TrList[i].hour_in < 10) cout;
		cout << TrList[i].hour_out << ':';
		if (TrList[i].minute_in < 10) cout << '0';
		cout << TrList[i].minute_out <<"\t" << setw(15);
		cout << enum_to_string(TrList[i].day) << endl;
	}
}


void searchingTrain() {
	if (position == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int th, tm,n=0;
	cout << "Введите время, после которого должен отправиться поезд(часы + минуты): ";
	cin >> th; cin >> tm;
	cout << "\n\t       Место назначения \t   Номер поезда \t    Время отправки\n";
	for (int i = 0; i < position; i++) {
		if ((th * 60) + tm <= (TrList[i].hour_in * 60) + TrList[i].minute_in) 
		{
			cout << "\t\t" << setw(15) << TrList[i].path << "\t\t" << setw(15) << TrList[i].number << "\t\t" << setw(15);
			if (TrList[i].hour_in < 10) cout << '0';
			cout << TrList[i].hour_in << ':';
			if (TrList[i].minute_in < 10) cout << '0';
			cout << TrList[i].minute_in << endl;
			n++;
		}
	}
	if (!n)
	{
		cout << "\t\tНет поездов отправляющихся в ближайший час " << endl;
	}
}

void automat() {
	position = 5;
	TrList[0] = { "Molodechno",32, 8 , 14 , 10 , 23 , MON };
	TrList[1] = { "Gomel",42, 11 , 45, 18, 12 , WED};
	TrList[2] = { "Minsk",18, 10, 25, 16, 58 , THU};
	TrList[3] = { "Arbelsk",10, 19 , 22, 23 , 30, SAT };
	TrList[4] = { "Gomel",92, 17 , 14 , 20 , 23 , SUN };
}
void del()
{
	if (position == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < position; de1++)
			TrList[de1] = TrList[de1 + 1];
		position = position - 1;
	}
	if (d == 99)
	{
		for (int i = 0; i < 8; i++)
			TrList[i] = clear;
		position = 0;
	}
	system("pause");
}

void main() {
	setlocale(LC_CTYPE, "Rus");
	int k;
	automat();
	do
	{
		cout << "1) Ввод данных в базу\n";
		cout << "2) Вывод данных всей базы\n";
		cout << "3) Выборка по пункту назначения и дате\n";
		cout << "4) Расписание поездов по времени\n";
		cout << "5) Удаление записей\n";
		cout << "6) Выход из терминала\n";
		cout << "Ввод номера комады: ";
		cin >> k;
		cout << "\n---------------------------------\n";
		switch (k)
		{
		case 1: new_tr(); break;
		case 2: infoshow(); break;
		case 3: searchingNumber(); break;
		case 4: searchingTrain(); break;
		case 5: del(); break;
		}
		cout << "\n---------------------------------\n";
	} while (k != 6);
	system("pause");
}

