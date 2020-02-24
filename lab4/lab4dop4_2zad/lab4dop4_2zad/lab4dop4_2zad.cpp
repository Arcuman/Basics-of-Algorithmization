// вариант 1 зад 2
#include "pch.h"
#include <iostream> 
typedef struct Students {
	char fio[16];
	char exam[16];
	int day;
	int month;
	int year;

} STUD;
int number;
FILE *f;
using namespace std;

errno_t err;
void input(int size) {
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "base.bin", "wb")) {
		for (int p = 0; p < size; p++) {
			cout << "Фамилия: ";
			cin >> buf.fio;
			cout << "Экзамен: ";
			cin >> buf.exam;
			cout << "Дата(00.00.0000): ";
			cin >> buf.day;
			cin >> buf.month;
			cin >> buf.year;
			fwrite(&buf, sizeof(buf), 1, f);
		} fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}
void output() {
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb")) {
		cout << "\nФамилия Экзамен Дата\n";
		fread(&buf, sizeof(buf), 1, f);

		while (!feof(f)) {
			cout << buf.fio << "\t " << buf.exam << "\t"<< buf.day << "." << buf.month << "." << buf.year << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
} void find(char lastName[16]) {
	bool flag = false;
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb")) {
		while (!feof(f)) {
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.fio) == 0) //сравнение строк 
			{
				cout << "\nФамилия Экзамен Дата\n";
				cout << buf.fio << "\t " << buf.exam <<"\t " << buf.day<<"."<< buf.month << "." << buf.year << endl;
				flag = true;
				break;
			}

		} fclose(f);
		if (!flag)
			cout << "Ничего не найдено\n";
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice;
	char fio[16];
	do {
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice) {
		case 1: cout << "Введите количество преподавателей: ";
			cin >> number;
			input(number);
			break;
		case 2:
			output();
			break;
		case 3: {
			cout << "Введите фамилию: ";
			cin >> fio;
			find(fio);
			break;
		} case 0:
			exit(0);
			break;
		}
	} while (choice != 0);
}