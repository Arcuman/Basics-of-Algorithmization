
#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#define size 30 
#define kol_sanat 5

using namespace std;
struct MyStruct
{
	char name[size];
	char locale[size];
	int profile;
	int putevki;
}sanator[kol_sanat];

int current_size = 0;  //переменная, которя запоминает кол-во санаториев при заполнении
int choise;     //выбор, для switch

void sort()           // сортировка через swap по названию санатория
{
	for (int i = 0; i < current_size; i++)
		for (int j = 0; j < current_size - i- 1; j++)
		{
			if (sanator[j].name[0] > sanator[j + 1].name[0])
			{
				swap(sanator[j], sanator[j + 1]);

			}
		}
}

void in()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Название санатория ";
		cin >> sanator[current_size].name;
		cout << endl << "Место расположения " << endl;
		cin >> sanator[current_size].locale;
		cout << "Лечебный профиль \n1-Дыхательная система\n2-Пищеварительная система\n3-Сердечная система" << endl;
		cin >> sanator[current_size].profile;
		cout << "Количество путёвок " << endl;
		cin >> sanator[current_size].putevki;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во санаториев";
	system("pause");
}
void out()
{
	int sw, n;
	cout << "1-вывод одного санатория" << endl;
	cout << "2-вывод всех санаториев" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимого санатория " << endl;
		cin >> n;
		cout << endl;
		cout << "Название санатория ";
		cout << sanator[n - 1].name << endl;
		cout << "Место расположения ";
		cout << sanator[n - 1].locale << endl;
		cout << "Лечебный профиль ";
		cout << sanator[n - 1].profile << endl;
		cout << "Количество путёвок " << endl;
		cout << sanator[n - 1].putevki;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Название санатория " << sanator[i].name << endl;
			cout << endl << "Место расположения " << sanator[i].locale << endl;
			cout << endl << "Лечебный профиль " << sanator[i].profile << endl;
			cout << endl << "Количество путёвок " << sanator[i].putevki << endl;
		}
	}
	system("pause");
}

void table()
{
	cout << "Start" << endl;
	if (current_size == 0)
	{
		cout << "Нечего выводить" << endl;
		return;
	}
	sort();			//срабатывает только перед выводом таблицы
	cout << "Start" << endl;
	cout << "\n_____________________________\n";
	cout << "Дыхательная система \n--------------------";
	for (int i = 0; i < current_size; i++)
	{

		if (sanator[i].profile == 1)
		{
			cout << "\nНазвание санатория ";
			cout << sanator[i].name << endl;
			cout << "Место расположения ";
			cout << sanator[i].locale << endl;
			cout << "Количество путёвок: ";
			cout << sanator[i].putevki;
			cout << "\n_____________________________\n";

		}
	}

	cout << "\n______________________________\n";
	cout << "|Пищеварительная система| \n------------------";

	for (int i = 0; i < current_size; i++)
	{
		if (sanator[i].profile == 2)
		{
			cout << "\nНазвание санатория ";
			cout << sanator[i].name << endl;
			cout << "Место расположения ";
			cout << sanator[i].locale << endl;
			cout << "Количество путёвок: ";
			cout << sanator[i].putevki;
			cout << "\n_____________________________\n";
		}
	}

	cout << "\n_____________________________\n";
	cout << "|Сердечная система| \n-----------------------------";

	for (int i = 0; i < current_size; i++)
	{
		if (sanator[i].profile == 3)
		{
			cout << "\nНазвание санатория ";
			cout << sanator[i].name << endl;
			cout << "Место расположения ";
			cout << sanator[i].locale << endl;
			cout << "Количество путёвок: ";
			cout << sanator[i].putevki;
			cout << "\n_____________________________\n";
		}
	}
	system("pause");
}
void search()
{
	int m;
	int p;
	char s[size];
	cout << "\n1-поиск по имени\n2-по лечебному профилю\n";
	cin >> m;
	if (m == 1)
	{
		cout << "Введите название: ";
		cin >> s;
		for (int i = 0; i < current_size; i++)
		{
			if (strcmp(sanator[i].name, s) == 0)
			{
				cout << "\nНазвание санатория ";
				cout << sanator[i].name << endl;
				cout << "Место расположения ";
				cout << sanator[i].locale << endl;
				cout << "Лечебный профиль " << sanator[i].profile;
			}
		}
	}

	if (m == 2)
	{
		cout << "Введите профиль[1-3]: ";
		cin >> p;
		for (int i = 0; i < current_size; i++)
		{
			if (sanator[i].profile == p)
			{
				cout << "\nНазвание санатория ";
				cout << sanator[i].name << endl;
				cout << "Место расположения ";
				cout << sanator[i].locale << endl;
				cout << "Лечебный профиль " << sanator[i].profile;
			}
		}
	}

	system("pause");
}

void main()
{
	setlocale(0, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do
	{
		cout << "Что выберем?\n1-запишем в структуру санаторий\n2-выведем санаторий\n3-выведем таблицу\n4-поиск\n5-Выход\n";
		cin >> choise;
		switch (choise)
		{
		case 1:in(); break;
		case 2:out(); break;
		case 3:table(); break;
		case 4:search(); break;
		}
	} while (choise != 5);
	system("pause");
}