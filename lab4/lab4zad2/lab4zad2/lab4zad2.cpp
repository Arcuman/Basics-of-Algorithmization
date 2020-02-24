//Вариант 9
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
	int number_class;
	char letter_class[2];
	int math_mark;
	int physics_mark;
	int IT_mark;
	int average;
};

struct Student list_of_student[size];
struct Student bad;
int current_size = 0,n;
char check[str_len];
FILE *f;
void del(); // Удаление записей
void out();// Вывод ученков в проге 
void enter_new();// Ввод новых в программе
void search(); // Поиск по фамилии
void input(int n);// Ввод в файо
void out_of_file();// Ввод данных из файлов
void outout(int n);//Вывод в консоль

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "3-для удаления записи(ей)" << endl;
	cout << "4-для поиска записи(ей)" << endl;
	cout << "5-для записи(ей) в файл" << endl;
	cout << "6-для записи(ей) из файл" << endl;
	cout << "6-для выхода" << endl;
	do
	{
		cout << "Что дальше?(0-вывод меню)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: main(); break;
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: del(); break;
		case 4: search(); break;
		case 5: cout << "Введите кол-во учеников" << endl;
			cin >> n;
			input(n); break;
		case 6: out_of_file(); break;
		}
		
	} while (choice != 7);
}
void out_of_file() // Ввод данных из файлов
{
	
	if (!fopen_s(&f, "base.txt", "r"))
	{
		fread(&list_of_student[current_size], sizeof(list_of_student), 1, f); // Ввод данных из файлов в массив структур
		current_size++;
		while (!feof(f))
		{
			fread(&list_of_student[current_size], sizeof(list_of_student), 1, f);
			current_size++;
		}
		
		//outout(current_size);
		cout << "Запись успешна"<<endl;
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void input(int n)
{
	cout << "1 -Запись в файл " << endl;
	cout << "2 -Вывод имеющейся информации в файл" << endl;
	int sw;
	cin >> sw;
	if (sw == 1)
	{
		Student buf;
		if (!fopen_s(&f, "base.txt", "w")) // Запись в файл
		{
			for (int p = 0; p < n; p++)
			{
				cout << "Ф.И.О. студента: ";
				getline(cin >> ws, buf.name);
				cout << "Цифра класса ";
				cin >> buf.number_class;
				cout << "Буква класса ";
				cin >> buf.letter_class;
				cout << "Оценка по матем ";
				cin >> buf.math_mark;
				cout << "Оценка по физике ";
				cin >> buf.physics_mark;
				cout << "Оценка по информатике ";
				cin >> buf.IT_mark;
				cout << "Средний балл ";
				cin >> buf.average;
				fwrite(&buf, sizeof(Student), 1, f);
			}
			fclose(f);
		}
		else {
			cout << "Ошибка открытия файла";
			return;
		}
	}
	if (sw == 2)
	{
		if (!fopen_s(&f, "out.txt", "w")) // Запись в файл
		{
			for (int p = 0; p < current_size; p++)
			{
				fwrite(&list_of_student[p], sizeof(Student), 1, f);
			}
			fclose(f);
		}
		else {
			cout << "Ошибка открытия файла";
			return;
		}


	}
}

void outout(int n)
{
	cout << endl << "Ф.И.О. студента: ";
	cout << list_of_student[n].name << endl;
	cout << "Цифра класса: ";
	cout << list_of_student[n].number_class << endl;
	cout << "Буква класса: ";
	cout << list_of_student[n].letter_class << endl;
	cout << "Оценки по ";
	cout << "Матем: ";
	cout << list_of_student[n].math_mark << endl;
	cout << "Физике: ";
	cout << list_of_student[n].physics_mark << endl;
	cout << "Информатике: " << endl;
	cout << list_of_student[n].IT_mark << endl;
	cout << "Средний балл: ";
	cout << list_of_student[n].average << endl;
	cout << endl;
}
void out() // Вывод в консоль
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
		cout << "Номер выводимой строки - ";
		cin >> n;
		n--;
		outout(n);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
		
		cout << endl << "Ф.И.О. студента: ";
		cout << list_of_student[i].name << endl;
		cout << "Цифра класса: ";
		cout << list_of_student[i].number_class << endl;
		cout << "Буква класса: ";
		cout << list_of_student[i].letter_class << endl;
		cout << "Оценки по " << endl;
		cout << "Матем: " ;
		cout << list_of_student[i].math_mark << endl;
		cout << "Физике: " ;
		cout << list_of_student[i].physics_mark << endl;
		cout << "Информатике: " ;
		cout << list_of_student[i].IT_mark << endl;
		cout << "Средний балл: ";
		cout << list_of_student[i].average << endl;
		cout << endl;
		}
	}
	
}

void del()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
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
		for (int i = 0; i < 8; i++)
			list_of_student[i] = bad;
		current_size = 0;
	}
}

void enter_new()
{

	if (current_size < size)
	{
		cout << "Ввод новой информации" << endl;
		cout << "Строка номер - " << current_size + 1 << endl;
		cout << "Ф.И.О. студента: ";
		getline(cin >> ws, list_of_student[current_size].name);
		cout << "Цифра класса ";
		cin >> list_of_student[current_size].number_class;
		cout << "Буква класса ";
		cin >> list_of_student[current_size].letter_class;
		cout << "Оценка по матем ";
		cin >> list_of_student[current_size].math_mark;
		cout << "Оценка по физике ";
		cin >> list_of_student[current_size].physics_mark;
		cout << "Оценка по информатике ";
		cin >> list_of_student[current_size].IT_mark;
		cout << "Средний балл ";
		cin >> list_of_student[current_size].average;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}
void search()
{
	if (current_size == 0)
	{
		cout << "Данных нет" << endl;
		return;
	}
	string x;
	cout << endl << "Ф.И.О. студента: ";
	getline(cin >> ws, x);
	for (int i = 0; i < current_size; i++)
	{
		if (x == list_of_student[i].name)
			outout(i);
	}
}
