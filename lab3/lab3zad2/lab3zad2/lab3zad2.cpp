// Вариант 11
//

#include "pch.h"
#include <iostream>  
#include <Windows.h>
#define str_len 30                               
#define size 30  

int choice;

int Nday = 6;
int Nmonth = 3;
int Nyear = 2019;

bool ok;

using namespace std;

struct Client
{
	char name[str_len];
	char name_of_product[str_len];
	char cost[str_len];
	char sum[str_len];
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
	unsigned int Lday : 5;
	unsigned int Lmonth : 4;
	unsigned int Lyear : 12;
};

struct Client list_of_Client[size];
struct Client bad;
int current_size = 0;
int i;
char ch;
char myFirstName[str_len];

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Фамилия " << endl;
		cin >> list_of_Client[current_size].name;
		cout << "Название товара " << endl;
		cin >> list_of_Client[current_size].name_of_product;
		cout << "Оценочная стоимость " << endl;
		cin >> list_of_Client[current_size].cost;
		cout << "Сумма под залог " << endl;
		cin >> list_of_Client[current_size].sum;
		cout << "Дата сдачи " << endl;
		cout << "День " << endl;
		cin >> i; list_of_Client[current_size].day = i; 
		cout << "Месяц " << endl;
		cin >> i; list_of_Client[current_size].month = i; 
		cout << "Год " << endl;
		cin >> i; list_of_Client[current_size].year = i;
		cout << "Срок хранения " << endl;
		cout << "День " << endl;
		cin >> i; list_of_Client[current_size].Lday = i; 
		cout << "Месяц " << endl;
		cin >> i; list_of_Client[current_size].Lmonth = i;
		cout << "Год " << endl;
		cin >> i; list_of_Client[current_size].Lyear = i;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	system("cls");
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_Client[de1] = list_of_Client[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
	{
		for (int i = 0; i < size; i++)
			list_of_Client[i] = bad;
		current_size == 0;
		
	}
	system("cls");
}

void change()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int n, per;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения фамилии" << endl;
		cout << "2-для изменения даты рождения" << endl;
		cout << "3-для изменения адрес" << endl;
		cout << "4-для изменения Сумма под залог" << endl;
		cout << "5-для изменения Дата сдачи" << endl;
		cout << "6-для изменения Срок хранения" << endl;
		cout << "7-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новая Фамилия ";
			cin >> list_of_Client[n - 1].name;   break;
		case 2: cout << "Новая Название товара ";
			cin >> list_of_Client[n - 1].name_of_product; break;
		case 3: cout << "Новый адрес ";
			cin >> list_of_Client[n - 1].cost; break;
		case 4: cout << "Новая Сумма под залог ";
			cin >> list_of_Client[n - 1].sum;   break;
		case 5: cout << "Новое Дата сдачи ";
			cout << list_of_Client[n - 1].day << ':' << list_of_Client[n - 1].month << ':' << list_of_Client[n - 1].year << endl; break;
		case 6: cout << "Новая Срок хранения ";
		}
	} while (per != 7);
	system("cls");
}

void out()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "===============================================\n";
		cout << "Фамилия ";
		cout << list_of_Client[n - 1].name << endl;
		cout << "-----------------------------------------------\n";
		cout << "Название товара ";
		cout << list_of_Client[n - 1].name_of_product << endl;
		cout << "-----------------------------------------------\n";
		cout << "Оценочная стоимость ";
		cout << list_of_Client[n - 1].cost << endl;
		cout << "-----------------------------------------------\n";
		cout << "Сумма под залог ";
		cout << list_of_Client[n - 1].sum << endl;
		cout << "-----------------------------------------------\n";
		cout << "Дата сдачи ";
		cout << list_of_Client[n - 1].day << ':' << list_of_Client[n - 1].month << ':' << list_of_Client[n - 1].year << endl;
		cout << "-----------------------------------------------\n";
		cout << "Срок хранения ";
		cout << list_of_Client[n - 1].Lday << ':' << list_of_Client[n - 1].Lmonth << ':' << list_of_Client[n - 1].Lyear << endl;
		cout << "===============================================\n";
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "===============================================\n";
			cout << "Фамилия ";
			cout << list_of_Client[i].name << endl;
			cout << "-----------------------------------------------\n";
			cout << "Название товара ";
			cout << list_of_Client[i].name_of_product << endl;
			cout << "-----------------------------------------------\n";
			cout << "Оценочная стоимость ";
			cout << list_of_Client[i].cost << endl;
			cout << "-----------------------------------------------\n";
			cout << "Сумма под залог ";
			cout << list_of_Client[i].sum << endl;
			cout << "-----------------------------------------------\n";
			cout << "Дата сдачи ";
			cout << list_of_Client[i].day << ':' << list_of_Client[i].month << ':' << list_of_Client[i].year << endl;
			cout << "-----------------------------------------------\n";
			cout << "Срок хранения ";
			cout << list_of_Client[i].Lday << ':' << list_of_Client[i].Lmonth << ':' << list_of_Client[i].Lyear << endl;
			cout << "===============================================\n";
		}
	}
	system("pause");
	system("cls");
}

void firstName() {
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	cout << "Ввод фамилии" << endl;
	int good = 0;
	cin >> myFirstName;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < str_len; j++) {
			if (list_of_Client[i].name[j] == myFirstName[j])
				good++;
		}
		if (good > 29) {
			cout << "===============================================\n";
			cout << "Фамилия ";
			cout << list_of_Client[i].name << endl;
			cout << "-----------------------------------------------\n";
			cout << "Название товара ";
			cout << list_of_Client[i].name_of_product << endl;
			cout << "-----------------------------------------------\n";
			cout << "Оценочная стоимость ";
			cout << list_of_Client[i].cost << endl;
			cout << "-----------------------------------------------\n";
			cout << "Сумма под залог ";
			cout << list_of_Client[i].sum << endl;
			cout << "-----------------------------------------------\n";
			cout << "Дата сдачи ";
			cout << list_of_Client[i].day << ':' << list_of_Client[i].month << ':' << list_of_Client[i].year << endl;
			cout << "-----------------------------------------------\n";
			cout << "Срок хранения ";
			cout << list_of_Client[i].Lday << ':' << list_of_Client[i].Lmonth << ':' << list_of_Client[i].Lyear << endl;
			cout << "===============================================\n";
		}
		good = 0;
	}
	system("pause");
	system("cls");
}

void Happy() {
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}

	cout << "Товары с истекшим сроком годности" << endl;

	for (int i = 0; i < current_size; i++)
	{
		if ((list_of_Client[i].day - Nday + 30 * (list_of_Client[i].month - Nmonth) + 355 * (list_of_Client[i].year - Nyear)) > (list_of_Client->Lday + 30 * list_of_Client->Lmonth + 355 * list_of_Client->Lyear)) {
			ok = true;
		}
		else ok = false;
		if (ok == true) {
			cout << "===============================================\n";
			cout << "Фамилия ";
			cout << list_of_Client[i].name << endl;
			cout << "-----------------------------------------------\n";
			cout << "Название товара ";
			cout << list_of_Client[i].name_of_product << endl;
			cout << "-----------------------------------------------\n";
			cout << "Оценочная стоимость ";
			cout << list_of_Client[i].cost << endl;
			cout << "-----------------------------------------------\n";
			cout << "Сумма под залог ";
			cout << list_of_Client[i].sum << endl;
			cout << "-----------------------------------------------\n";
			cout << "Дата сдачи ";
			cout << list_of_Client[i].day << ':' << list_of_Client[i].month << ':' << list_of_Client[i].year << endl;
			cout << "-----------------------------------------------\n";
			cout << "Срок хранения ";
			cout << list_of_Client[i].Lday << ':' << list_of_Client[i].Lmonth << ':' << list_of_Client[i].Lyear << endl;
			cout << "===============================================\n";
			ok = false;
		}
		if (list_of_Client->name[i + 3] == list_of_Client->name[i + 4]) {
			break;
		}

	}

	system("pause");
	system("cls");
}
void automat() {
	current_size = 1;
	list_of_Client[0] = { "Borisov","Ring","1000","800",3,10,2018,3,12,2018 };
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	automat();
	cout << "Данных нет" << endl;
	do {
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для изменения записи" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для поиска по Фамилии" << endl;
		cout << "6-для показа просроченных" << endl;
		cout << "7-для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		case 5:  firstName();	break;
		case 6:  Happy();	break;
		}
	} while (choice != 7);
}
