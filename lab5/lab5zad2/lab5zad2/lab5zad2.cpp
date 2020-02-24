#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
# define str_len 30
# define size 30
int choice;
using namespace std;
typedef  union Student
{
	char fio[16];
	char number_class;
	char letter_class[2];
	char math_mark;
	char physics_mark;
	char IT_mark;
	char average[2];
} FT;
int num;
using namespace std;
void input();
void output() // Вывод данных
{
	ifstream otf("Data.DAT");
	cout << "\nФамилия    Класс    Математика    Физика    Информатика    Ср.балл\n";
	while (!otf.eof())
	{
		FT buf = { ' ', };
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.fio << "\t    ";
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.number_class;
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.letter_class << "\t\t   ";
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.math_mark << "\t    ";
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.physics_mark << "\t\t    ";
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.IT_mark << "\t     ";
		otf.read((char *)&buf, sizeof(buf));
		cout <<  buf.average << endl;
	}
	cout << endl;
}
void find_average(char fam[2]) // поиск среднего значения
{
	int i = 0; // переменная для подсчета номера среднего балла 
	FT buf = { ' ' };
	ifstream otf("Data.DAT");
	int k = 0; // в какой структуре есть средний балл
	cout << "\nФамилия    Класс    Математика    Физика    Информатика    Ср.балл\n";
	while (!otf.eof())
	{
		otf.read((char*)&buf, sizeof(buf));
		i++;
		if ((i % 7 == 0)&&(i!=0)) {
			if (strcmp(fam, buf.average) == 0)
			{
				otf.seekg(112*k, ios::beg); // перевод указателя на фамилию и вывод этих данных
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.fio<< "\t  ";
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.number_class;
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.letter_class << "\t\t    ";
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.math_mark << "\t    ";
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.physics_mark << "\t\t  ";
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.IT_mark << "\t   ";
				otf.read((char *)&buf, sizeof(buf));
				cout << buf.average << "\t\t    ";
				cout << endl;
				k++;
			}
			else 
			{
				k++;
			}
		}
	}
}
void find_fio(char fam[16]) // поиск по фамилии 
{
	int i = 0;
	FT buf = { ' ' };
	ifstream otf("Data.DAT");
	cout << "\nФамилия    Класс    Математика    Физика    Информатика    Ср.балл\n";
	while (!otf.eof())
	{
		otf.read((char *)&buf, sizeof(buf));
		if (strcmp(fam, buf.fio) == 0)       //сравнение     
		{
			cout << buf.fio << "\t    ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.number_class;
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.letter_class << "\t\t    ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.math_mark << "\t    ";
			otf.read((char *)&buf, sizeof(buf));
			cout  << buf.physics_mark << "\t\t  ";
			otf.read((char *)&buf, sizeof(buf));
			cout  << buf.IT_mark << "\t   ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.average << "\t\t    ";
			i = 1; break;
		}
	}
	if (i == 0)
		cout << "Ничего не найдено\n";
	otf.close();
}
void del() // очистка файла
{
	fstream itf;
	itf.open("Data.DAT", ofstream::out | ofstream::trunc);
	itf.close();
}
void temp()
{
	
	ifstream itf("out.DAT", ios_base::in);
	ofstream otf("DATA.DAT", ios_base::out);
	int m = 0;
	FT buf = { ' ' };
	while (!itf.eof())
	{
		itf.seekg(112 * m, ios::beg);
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));	
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		itf.read((char *)&buf, sizeof(buf));
		otf.write((char *)&buf, sizeof(buf));
		m++;
		itf.seekg(112 * m, ios::beg);
		itf.read((char *)&buf, sizeof(buf));
	}
	otf.close();
	itf.close();
}
void change() //редактирование данных 
{
	int k;
	int m =0; // текущая строка
	cout << "Введите номер строки для редактирования" << endl;
	cin >> k;	
	k--;
	ofstream itf("out.DAT", ios_base::out);
	ifstream otf("DATA.DAT", ios_base::in);
	FT buf = { ' ' };
	while (!otf.eof())
	{
		otf.seekg(112 * m, ios::beg);
		
		if (m != k)
		{
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			otf.read((char *)&buf, sizeof(buf));
			itf.write((char *)&buf, sizeof(buf));
			
		}
		m++;
		otf.seekg(112 * m, ios::beg);
		otf.read((char *)&buf, sizeof(buf));
	}
	otf.close();
	itf.close();
	del();
	temp();
	num = 1;
	input();
}
void input() // добавление записей в файл
{
	ofstream itf;
	itf.open("Data.DAT", ios_base::app);
	FT buf = { ' ' };
	for (int p = 0; p < num; p++)
	{
		cout << "Фамилия: ";
		cin >> buf.fio;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Цифра класса: ";
		cin >> buf.number_class;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Буква класса: ";
		cin >> buf.letter_class;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Оценка по матем: ";
		cin >> buf.math_mark;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Оценка по физике: ";
		cin >> buf.physics_mark;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Оценка по информатике: ";
		cin >> buf.IT_mark;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Средний балл: ";
		cin >> buf.average;
		itf.write((char *)&buf, sizeof(buf));
	}
	itf.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "4.Поиск по среднему баллу\n";
		cout << "5.Удаление записей\n";
		cout << "6.Редактирование записей(для 2 и более записей)\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество  ";
			cin >> num;
			input();
			break;
		case 2: output(); break;
		case 3:char last_name[16];
			cout << "Введите фамилию: ";
			cin >> last_name;
			find_fio(last_name); break;
		case 4: char fam[2];
			cout << "Введите ср.балл: ";
			cin >> fam;
			find_average(fam); break;
		case 5: del(); break;
		case 6: change(); break;
		case 0: exit(0);  break;
		default: cout << "Неверный выбор. Попробуйте снова" << endl; break;
		}
	} while (choice != 0);
}
