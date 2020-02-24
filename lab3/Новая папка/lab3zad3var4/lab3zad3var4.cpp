//14 вариант
#include "pch.h"
#include <iostream> 
#include <locale>
#include <Windows.h>
#include <string>
#include <iomanip>
#define str_len 30
#define size 3  
using namespace std;
enum TYPES { sr = 1, lg, vk, st }; // срочный, льготный, вклад, стандартный
struct Bank {
	string name;
	TYPES type;
	int number;
	double sum;
	unsigned int year : 12; // 2100  это 100000110100 
	unsigned int month : 4; // 12 это 1100
	unsigned int day : 5; // 31  это 11111 
};
struct Bank client[size];
struct Bank clear;
int current_size = 0;
int choice;
void del();
void enter_new();
void change();
void out();
void find();
string enum_to_string(TYPES t); //Вывод типа


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-для поиска по номеру и диапазону" << endl;
	cout << "9-для выхода" << endl;
	cin >> choice;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 0: main();
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		case 5:  find();	break;
		}
	} while (choice != 9);
}
void enter_new()
{
	cout << "Ввод информации:" << endl;
	if (current_size < size)
	{
		int tmp;
		cout << "Строка номер: " << current_size + 1 << endl << "Ф.И.О.: ";
		getline(cin >> ws, client[current_size].name);
		cout << "Тип (1-срочный, 2-льготный, 3-вклад, 4-стандартный): ";
		cin >> tmp;
		client[current_size].type = static_cast<TYPES>(tmp); //static_cast < type_to > ( object_from )
		cout << "Номер: ";
		cin >> client[current_size].number;
		cout << "Сумма: ";
		cin >> client[current_size].sum;
		cout << "Дата:\nдень месяц год\n"; //через пробелы
		cin >> tmp;
		client[current_size].day = tmp;
		cin >> tmp;
		client[current_size].month = tmp;
		cin >> tmp;
		client[current_size].year = tmp;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 101)" << endl;
	cin >> d;
	if (d != 101)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			client[de1] = client[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 101)
	{
		for (int i = 0; i < size; i++)
			client[i] = clear;
		current_size = 0;
	}
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void change()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int n, per;
	cout << "\nВведите номер строки" << endl;
	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения Ф.И.О." << endl;
		cout << "2-для изменения типа счета" << endl;
		cout << "3-для изменения номера счета" << endl;
		cout << "4-для изменения суммы" << endl;
		cout << "5-для изменения даты" << endl;
		cout << "9-завершить редактирование строки\n";
		cin >> per;
		int tmp;
		switch (per)
		{
		case 1: cout << "Новое ФИО: ";
			getline(cin >> ws, client[n - 1].name);
			break;
		case 2: cout << "Новый тип: ";
			cin >> tmp;
			client[current_size].type = static_cast<TYPES>(tmp);
			break;
		case 3: cout << "Новый номер: ";
			cin >> client[n - 1].number;
			break;
		case 4: cout << "Новая сумма: ";
			cin >> client[n - 1].sum;
			break;
		case 5: cout << "Новая дата: ";
			cout << "\nдень_месяц_год"; //через пробелы
			cin >> tmp;
			client[current_size].day = tmp;
			cin >> tmp;
			client[current_size].month = tmp;
			cin >> tmp;
			client[current_size].year = tmp;
			break;
		}
	} while (per != 9);
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void out()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int n;
	cout << "Введите номер строки: ";
	cin >> n;
	cout << "ФИО: " << client[n - 1].name << endl;
	cout << "Тип счёта: " << enum_to_string(client[n - 1].type) << endl;
	cout << "Номер счёта: " << client[n - 1].number << endl;
	cout << "Сумма: " << client[n - 1].sum << endl;
	cout << "Дата: " << client[n - 1].day << "." << client[n - 1].month << "." << client[n - 1].year << endl;

	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void find()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	int sw, n;
	cout << "1-поиск по номеру счёта" << endl;
	cout << "2-по диапазону суммы (>a, <b)" << endl;
	cin >> sw;
	if (sw == 1)
	{
		int tmp;
		cout << "Введите номер счёта: ";
		cin >> tmp;
		cout << setw(80) << setfill('*') << "*" << endl;
		cout << setw(45) << setfill(' ') << "Поиск по номеру счёта" << endl;
		cout << setw(80) << setfill('*') << "*" << endl;
		cout << "ФИО\t\tтип\t\tномер\tсумма\tдата\n";
		for (int n = 0; n < current_size; n++)
			if (tmp == client[n].number)
				cout << client[n].name << "\t" << enum_to_string(client[n].type) << "\t" << client[n].number << "\t" << client[n].sum << "\t" << client[n].day << "." << client[n].month << "." << client[n].year << endl;
		cout << setw(80) << setfill('*') << "*" << endl;
	}
	if (sw == 2)
	{
		int a, b;
		cout << "Введите диапазон от a до b через пробел: ";
		cin >> a >> b;
		cout << setw(80) << setfill('*') << "*" << endl;
		cout << setw(45) << setfill(' ') << "Поиск по диапазону" << endl;
		cout << setw(80) << setfill('*') << "*" << endl;
		cout << "ФИО\t\tтип\t\tномер\tсумма\tдата\n";
		for (int n = 0; n < current_size; n++)
			if (client[n].sum >= a && client[n].sum <= b)
				cout << client[n].name << "\t" << enum_to_string(client[n].type) << "\t" << client[n].number << "\t" << client[n].sum << "\t" << client[n].day << "." << client[n].month << "." << client[n].year << endl;
		cout << setw(80) << setfill('*') << "*" << endl;
	}
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

string enum_to_string(TYPES t) {
	switch (t) {
	case sr:
		return "срочный\t";
	case lg:
		return "льготный";
	case vk:
		return "вклад\t";
	case st:
		return "станлартный";
	default:
		return "INVALID ENUM";
	}
}