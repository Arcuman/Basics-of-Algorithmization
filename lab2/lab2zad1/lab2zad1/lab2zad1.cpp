#include "pch.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
# define str_len 30                               
# define size 30  
int choice;
using namespace std;
struct Student
{
	char first_name[str_len];
	char second_name[str_len];
	char dad_name[str_len];
	char faculty[str_len];
	char specialty[str_len];
	int year_of_enter;
	int group_number;
	double average_ball;
};

struct Student list_of_student[size];
struct Student bad;
int current_size = 0;

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Имя " << endl;
		cin >> list_of_student[current_size].first_name;
		cout << "Фамилия " << endl;
		cin >> list_of_student[current_size].second_name;
		cout <<  "Отчество " << endl;
		cin >> list_of_student[current_size].dad_name;
		cout << "Год поступления " << endl;
		cin >> list_of_student[current_size].year_of_enter;
		cout << "Cпециальность " << endl;
		cin >> list_of_student[current_size].specialty;
		cout << "Группу" << endl;
		cin >> list_of_student[current_size].group_number;
		cout << "Факультет" << endl;
		cin >> list_of_student[current_size].faculty;
		cout << "Средний балл" << endl;
		cin >> list_of_student[current_size].average_ball;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	system("pause");
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
	{
		for (int i = 0; i < size; i++)
			list_of_student[i] = bad;
		current_size = 0;
	}
	system("pause");
}

void change()
{
	if (current_size == 0)
	{
		cout << "Данных нет";
		return;
	}
	int n, per;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения фамилии" << endl;
		cout << "2-для изменения года поступления" << endl;
		cout << "3-для изменения группы" << endl;
		cout << "4-для изменения факультета" << endl;
		cout << "5-для изменения среднего балла" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новая Фамилия";
			cin >> list_of_student[n - 1].first_name;   break;
		case 2: cout << "Новый год поступления";
			cin >> list_of_student[n - 1].year_of_enter; break;
		case 3: cout << "Новая группа ";
			cin >> list_of_student[n - 1].group_number; break;
		case 4: cout << "Новый факультет  ";
			cin >> list_of_student[n - 1].faculty; break;
		case 5: cout << "Новый факультет ";
			cin >> list_of_student[n - 1].average_ball; break;
		}
	} while (per != 6);
	system("pause");
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
		cout << "Номер выводимой строки " << endl;   
		cin >> n; 
		cout << endl;
		cout << "Имя ";
		cout << list_of_student[n - 1].first_name << endl;
		cout << "Фамилия ";
		cout << list_of_student[n - 1].second_name << endl;
		cout << "Отчество ";
		cout << list_of_student[n - 1].dad_name << endl;
		cout << "Год поступления ";
		cout << list_of_student[n - 1].year_of_enter << endl;
		cout << "Факультет ";
		cout << list_of_student[n - 1].faculty << endl;
		cout << "Специальность ";
		cout << list_of_student[n - 1].specialty << endl;
		cout << "Группа ";
		cout << list_of_student[n - 1].group_number << endl;
		cout << "Средний балл ";
		cout << list_of_student[n - 1].average_ball << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Имя ";
			cout << list_of_student[i].first_name << endl;
			cout << "Фамилия ";
			cout << list_of_student[i].second_name << endl;
			cout << "Отчество ";
			cout << list_of_student[i].dad_name << endl;
			cout << "Год поступления ";
			cout << list_of_student[i].year_of_enter << endl;
			cout << "Факультет ";
			cout << list_of_student[i].faculty << endl;
			cout << "Специальность ";
			cout << list_of_student[i].specialty << endl;
			cout << "Группа ";
			cout << list_of_student[i].group_number << endl;
			cout << "Средний балл ";
			cout << list_of_student[i].average_ball << endl;
		}
	}
	system("pause");
}
int fun_out(int i)
{
	cout << "Имя ";
	cout << list_of_student[i].first_name << endl;
	cout << "Фамилия ";
	cout << list_of_student[i].second_name << endl;
	cout << "Отчество ";
	cout << list_of_student[i].dad_name << endl;
	cout << "Год поступления ";
	cout << list_of_student[i].year_of_enter << endl;
	cout << "Факультет ";
	cout << list_of_student[i].faculty << endl;
	cout << "Специальность ";
	cout << list_of_student[i].specialty << endl;
	cout << "Группа ";
	cout << list_of_student[i].group_number << endl;
	cout << "Средний балл ";
	cout << list_of_student[i].average_ball << endl;
	return 0;
}
void fun_year()
{
	int years;
	cout << "Введите год поступления" << endl;
	cin >> years;
	for (int i = 0; i < current_size; i++) {
		if (list_of_student[i].year_of_enter == years)
			fun_out(i);
	}
}
void fun_secondname()
{
	cout << "Введите фамилию" << endl;
	char secondname[30];
	cin >> secondname;
	for (int i = 0; i < current_size; i++) {
		if (_stricmp(secondname, list_of_student[i].second_name) == 0)
			fun_out(i);
	}
}
void fun_average()
{
	double average;
	cout << "Введите средний балл" << endl;
	cin >> average;
	for (int i = 0; i < current_size; i++) {
		if (list_of_student[i].average_ball == average)
			fun_out(i);
	}
}
void fun_group()
{
	double group;
	cout << "Введите группу" << endl;
	cin >> group;
	for (int i = 0; i < current_size; i++) {
		if (list_of_student[i].group_number == group)
			fun_out(i);
	}
}
void sort()
{
	if (current_size)
	{
		double average;
		cout << "Выберите параметр: " << endl;

		cout << " 1) Год поступления" << endl;
		cout << " 2) Фамилия" << endl;
		cout << " 3) Средний балл" << endl;
		cout << " 4) Группа" << endl;
		cout << " 5) Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  fun_year();	break;
		case 2:  fun_secondname();  break;
		case 3:  fun_average();  break;
		case 4:  fun_group();	break;
		case 5: 	break;
		}

	}

	system("pause");
}
void automat() {
	current_size = 1;
	strcpy_s(list_of_student[0].first_name, "Anton");strcpy_s(list_of_student[0].second_name, "Borisov");
	strcpy_s(list_of_student[0].dad_name, "Andreevich"); list_of_student[0].year_of_enter = 2018;
	strcpy_s(list_of_student[0].faculty, "FIT");strcpy_s(list_of_student[0].specialty, "POIT");
	list_of_student[0].group_number = 4;list_of_student[0].average_ball = 8.4;
	
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	automat();
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для изменения записи" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для вывода записи(ей) по параметрам" << endl;
		cout << "6-для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		case 5: sort();	break;
		}
	} while (choice != 6);
}
