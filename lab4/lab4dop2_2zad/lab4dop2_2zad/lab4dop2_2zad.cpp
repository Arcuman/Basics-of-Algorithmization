// lab4dop2_2zad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 14 вариант 2 зад

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
#define str_len 30
#define size 30

enum types
{
	single_room = 1, double_room, triple_room, lux, apartament
};

struct date
{
	unsigned day : 5;	//| 31    11111
	unsigned month : 4;	//| 12    1100
	unsigned year : 12;	//| 2100	100000110100
};

struct hotels
{
	char pasport[str_len];
	int room;
	date arrival_date;
	date departure_date;
	types type;
};

hotels turist[size];
hotels bad;
int current_size = 0;
int choice;
int help_d; // доп. переменная для ввода данных в битовые поля
int help_m; // доп. переменная для ввода данных в битовые поля
int help_y; // доп. переменная для ввода данных в битовые поля
FILE * fp;  // указатель на файловый поток
char filename[] = "hostel.txt";

void display_menu(); // Ф-ция Показа меню
void enter_new(); // Ф-ция Ввода новой информации
void del(); // Ф-ция Удаления
void out(); // Ф-ция Вывода информации
void change(); // Ф-ция Изменения информации
void search(); // Ф-ция Поиска по дате приезда
string enum_to_string(types); // Вспомогательная ф-ция для работы с перечислениями
void save(struct hotels*);
void load();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	load();
	do
	{
		system("cls");
		display_menu();
		switch (choice)
		{
		case 1: enter_new(); break; //Ввод данных
		case 2: del(); break;//Удаление данных
		case 3: out(); break;//Вывод данных
		case 4: change(); break;//Изменение данных
		case 5: search(); break;//Поиск данных
		default: break;
		}
	} while (choice != 6);
	save(turist);
}

void display_menu()
{
	if (current_size == 0)
		cout << "\tДанных нет\n" << endl;
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для удаления записи(ей)" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для изменения записи" << endl;
	cout << "5-для поиска гостей по дате приезда" << endl;
	cout << "6-для выхода" << endl;
	cin >> choice;
}

void enter_new()
{
	system("cls");
	if (current_size < size)
	{
		cout << "Ввод новой информации!" << endl;
		cout << "\tСтрока номер - " << current_size + 1 << endl;
		cout << "Введите паспортные данные: ";
		cin >> turist[current_size].pasport;
		cout << endl << "Дата приезда (DD MM YY): ";
		cin >> help_d; cin >> help_m; cin >> help_y;
		turist[current_size].arrival_date.day = help_d;
		turist[current_size].arrival_date.month = help_m;
		turist[current_size].arrival_date.year = help_y;
		cout << endl << "Дата отъезда (DD MM YY): ";
		cin >> help_d; cin >> help_m; cin >> help_y;
		turist[current_size].departure_date.day = help_d;
		turist[current_size].departure_date.month = help_m;
		turist[current_size].departure_date.year = help_y;
		cout << endl << "Номер комнаты: ";
		cin >> turist[current_size].room;
		cout << endl << "Тип размещения:";
		cout << endl << "1 - Одноместный";
		cout << endl << "2 - Двухместный";
		cout << endl << "3 - Трехместный";
		cout << endl << "4 - Люкс";
		cout << endl << "5 - Апартаменты\n";
		int vibor;
		cin >> vibor;
		turist[current_size].type = (types)vibor;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}

void del()
{
	if (current_size)
	{
		int d;
		cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
		cin >> d;
		if (d != 99)
		{
			if (d <= current_size)
			{
				for (int de1 = (d - 1); de1 < current_size; de1++)
					turist[de1] = turist[de1 + 1];
				current_size--;
			}
			else
				cout << "Такой строки нет!" << endl;
		}
		if (d == 99)
		{
			for (int i = 0; i < size; i++)
				turist[i] = bad;
			current_size = 0;
		}
	}
	else
	{
		cout << "Данных нет! Удалять нечего." << endl;
		system("pause");
	}


}

void out()
{
	if (current_size)
	{
		int sw, n;
		cout << "1-вывод 1 строки" << endl;
		cout << "2-вывод всех строк" << endl;
		cin >> sw;
		if (sw == 1)
		{
			cout << "Номер выводимой строки - ";
			cin >> n;
			if (n <= current_size)
			{
				cout << endl << "Паспортные данные: ";
				cout << turist[n - 1].pasport << endl;
				cout << endl << "Дата приезда: ";
				cout << turist[n - 1].arrival_date.day << "." << turist[n - 1].arrival_date.month << "." << turist[n - 1].arrival_date.year;
				cout << endl << "Дата отъезда: ";
				cout << turist[n - 1].departure_date.day << "." << turist[n - 1].departure_date.month << "." << turist[n - 1].departure_date.year;
				cout << endl << "Номер комнаты: ";
				cout << turist[n - 1].room;
				cout << endl << "Тип размещения: ";
				cout << enum_to_string(turist[n - 1].type);
			}
			else cout << "Строка с номером " << n << " отсутствует!";
		}
		if (sw == 2)
		{
			for (int i = 0; i < current_size; i++)
			{
				cout << endl << "\n\nПаспортные данные: ";
				cout << turist[i].pasport << endl;
				cout << endl << "Дата приезда: ";
				cout << turist[i].arrival_date.day << "." << turist[i].arrival_date.month << "." << turist[i].arrival_date.year;
				cout << endl << "Дата отъезда: ";
				cout << turist[i].departure_date.day << "." << turist[i].departure_date.month << "." << turist[i].departure_date.year;
				cout << endl << "Номер комнаты: ";
				cout << turist[i].room;
				cout << endl << "Тип размещения: ";
				cout << enum_to_string(turist[i].type);
			}
		}
	}
	else
		cout << "Данные отсутствуют!" << endl;
	cout << endl;
	system("pause");
}

void change()
{
	if (current_size)
	{
		int n, per;
		cout << "\nВведите номер строки" << endl;
		cin >> n;
		do
		{
			cout << "Введите: " << endl;
			cout << "1-для изменения Паспортных данных" << endl;
			cout << "2-для изменения Даты приезда" << endl;
			cout << "3-для изменения Даты отъезда" << endl;
			cout << "4-для изменения Номера комнаты" << endl;
			cout << "5-для изменения Типа размещения" << endl;
			cout << "6-конец\n";
			cin >> per;
			switch (per)
			{
			case 1: cout << "Новые Паспортные данные: ";
				cin >> turist[n - 1].pasport; break;
			case 2: cout << "Новая Дата приезда: ";
				cin >> help_d; cin >> help_m; cin >> help_y;
				turist[n - 1].arrival_date.day = help_d;
				turist[n - 1].arrival_date.month = help_m;
				turist[n - 1].arrival_date.year = help_y;
				break;
			case 3: cout << "Новая Дата отъезда: ";
				cin >> help_d; cin >> help_m; cin >> help_y;
				turist[n - 1].departure_date.day = help_d;
				turist[n - 1].departure_date.month = help_m;
				turist[n - 1].departure_date.year = help_y;
				break;
			case 4: cout << "Новый Номер комнаты: ";
				cin >> turist[n - 1].room;
			case 5: cout << "Новый тип размещения: ";
				cout << endl << "1 - Одноместный";
				cout << endl << "2 - Двухместный";
				cout << endl << "3 - Трехместный";
				cout << endl << "4 - Люкс";
				cout << endl << "5 - Апартаменты\n";
				int vibor;
				cin >> vibor;
				turist[n - 1].type = (types)vibor;
			}
		} while (per != 6);
	}
	else
		cout << "Данных нет! Изменять нечего." << endl;
	system("pause");
}

void search()
{
	if (current_size)
	{
		int g = 0; // Переменна отображающая успех поиска
		cout << "\tПоиск гостя по дате приезда" << endl;
		cout << "\n\nВведите дату приезда (DD MM YY): ";
		cin >> help_d; cin >> help_m; cin >> help_y;
		for (int i = 0; i < current_size; i++)
		{
			if (turist[i].arrival_date.day == help_d && turist[i].arrival_date.month == help_m && turist[i].arrival_date.year == help_y)
			{
				cout << endl << "\n\nПаспортные данные: ";
				cout << turist[i].pasport;
				cout << endl << "Дата приезда: ";
				cout << turist[i].arrival_date.day << "." << turist[i].arrival_date.month << "." << turist[i].arrival_date.year;
				cout << endl << "Дата отъезда: ";
				cout << turist[i].departure_date.day << "." << turist[i].departure_date.month << "." << turist[i].departure_date.year;
				cout << endl << "Номер комнаты: ";
				cout << turist[i].room;
				cout << endl << "Тип размещения: ";
				switch (turist[i].type)
				{
				case 1:
					cout << "Одноместный\n"; break;
				case 2:
					cout << "Двухместный\n"; break;
				case 3:
					cout << "Трехместный\n"; break;
				case 4:
					cout << "Люкс\n"; break;
				case 5:
					cout << "Апартаменты\n"; break;
				default:
					break;
				}
				g++;
			}
		}
		if (g == 0)
			cout << "Гостей не было найдено!" << endl;
	}
	else cout << "Искать нечего, структура пуста!" << endl;
	system("pause");
}

string enum_to_string(types x)
{
	switch (x)
	{
	case 1:
		return "Одноместный\n";
	case 2:
		return "Двухместный\n";
	case 3:
		return "Трехместный\n";
	case 4:
		return "Люкс\n";
	case 5:
		return "Апартаменты\n";
	default:
		return "INVALID ENUM";
	}
}

void save(struct hotels * st)
{
	if (!fopen_s(&fp, filename, "w"))
	{
		fwrite(&current_size, sizeof(int), 1, fp);
		for (int i = 0; i < current_size; i++)
			fwrite((st + i), sizeof(hotels), current_size, fp);

		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void load()
{
	if (!fopen_s(&fp, filename, "r"))
	{
		int buf;
		fread(&buf, sizeof(int), 1, fp);
		for (; current_size < buf; current_size++)
		{
			fread(&turist[current_size], sizeof(hotels), 1, fp);
		}
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}