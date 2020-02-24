// Dop_1
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
# define str_len 30
# define size 30
int choice;
using namespace std;
struct Student
{
	string name;
	int number_of_exams;
	int mark[size];
};

struct Student list_of_student[size];
struct Student bad;
int current_size = 0;
char check[str_len];

void out();
void enter_new();
void check_exams(); // Проверяет сданы ли у студента все экзамены на 4 и 5
int search(string); // Ищит студента по Ф.И.О. и возвращает их номер в структуре
void success(); // Выводит успеваемость в процентах
double success_help(); // ф-ция подсчета кол-во успешных студентов

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "3-для проверки на оценки 4 и 5" << endl;
	cout << "4-для проверки успеваемости студентов" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{


		switch (choice)
		{
		case 0: main(); break;
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: check_exams(); break;
		case 4: success(); break;
		}
	} while (choice != 5);
}



void out()
{

	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;

	if (sw == 1)
	{
		cout << "Номер выводимой строки - ";
		cin >> n;
		cout << endl << "Ф.И.О. студента: ";
		cout << list_of_student[n - 1].name << endl;
		cout << "Количество экзаменов: ";
		cout << list_of_student[n - 1].number_of_exams << endl;
		cout << "Оценки: ";
		for (int i = 0; i < list_of_student[n - 1].number_of_exams; i++)
		{
			cout << list_of_student[n - 1].mark[i] << "  ";
		}
		cout << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Ф.И.О. студента: ";
			cout << list_of_student[i].name << endl;
			cout << "Количество экзаменов: ";
			cout << list_of_student[i].number_of_exams << endl;
			cout << "Оценки: ";
			for (int b = 0; b < list_of_student[i].number_of_exams; b++)
			{
				cout << list_of_student[i].mark[b] << "  ";
			}
			cout << endl;
		}
	}
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void enter_new()
{

	if (current_size < size)
	{
		cout << "Ввод новой информации" << endl;
		cout << "Строка номер - " << current_size + 1 << endl;
		cout << "Ф.И.О. студента: ";
		getline(cin >> ws, list_of_student[current_size].name);
		cout << "Количество экзаменов: ";
		do
		{
			cin >> check;
			if (isdigit(check[0]))													//	Проверка вводимых
				list_of_student[current_size].number_of_exams = atoi(check);		//		данных
			else
				cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
		} while (!isdigit(check[0]));
		for (int i = 0; i < list_of_student[current_size].number_of_exams; i++)
		{
			cout << "\nВведите оценку по " << i + 1 << " экзамену: ";
			do
			{
				cin >> check;
				if (isdigit(check[0]))													//	Проверка вводимых
					list_of_student[current_size].mark[i] = atoi(check);				//		данных
				else
					cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
			} while (!isdigit(check[0]));
		}
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

void check_exams()
{
	if (current_size)
	{
		int n;
		string poisk;
		cout << "Введите Ф.И.О. студента: ";
		getline(cin >> ws, poisk);
		if (search(poisk) + 1)
		{
			int count = 0;
			n = search(poisk);
			for (int i = 0; i < list_of_student[n].number_of_exams; i++)
			{
				if (list_of_student[n].mark[i] != 4 && list_of_student[n].mark[i] != 5)
				{
					count++;
					cout << "У студента есть экзамены сданные ниже 4" << endl;
					break;
				}
			}
			if (count == 0)
			{
				cout << "У студента все экзамены сданы на 4 и 5" << endl;
			}
		}

	}
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

int search(string x)
{
	for (int i = 0; i < current_size; i++)
		if (x == list_of_student[i].name)
			return i;
	return -1;
}

void success()
{

	if (current_size)
	{
		cout << "Процент успеваемости - " << (((double)current_size - success_help()) / (double)current_size) * 100 << "%" << endl;
	}
	cout << "Что дальше?(0-вывод меню)" << endl;
	cin >> choice;
}

double success_help()
{
	if (current_size)
	{
		int count = 0;
		for (int i = 0; i < current_size; i++)
		{
			int mark_count = 0;
			for (int j = 0; j < list_of_student[i].number_of_exams; j++)
			{
				if (list_of_student[i].mark[j] != 4 && list_of_student[i].mark[j] != 5)
					mark_count++;
			}
			if (mark_count > 0)
				count++;
		}
		return count;
	}
}