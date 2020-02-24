//Вариант 11 зад 1
#include "pch.h"
#include <iostream>
using namespace std;
FILE *f;
int allnumb[100];
int choice;
int mysize;
void input(int size)
{
	cout << "\nВведите числа:";
	for (int i = 0; i < size; i++) //Ввод данных массива
	{
		cin >> allnumb[i];
	}
	allnumb[size] = 0;

	if (!fopen_s(&f, "A.bin", "wb")) //Запись в файл А.bin
	{
		for (int m = 0; m < size + 1; m++)
		{
			fwrite(&allnumb[m], sizeof(int), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	int buf = 0;
	mysize = 0;
	if (!fopen_s(&f, "A.bin", "rb")) //Открытие файла для чтения 
	{

		fread(&buf, sizeof(int), 1, f); // Считывание информации 
		do {
			allnumb[mysize] = buf;
			mysize++;
		} while (fread(&buf, 4, 1, f) != 0);
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}

	for (int m = 0; m < mysize + 1; m++) //Реализация чередования знаков в массиве
	{
		if (m % 2 == 0) {
			if (allnumb[m] > 0)
				allnumb[m] = -1 * allnumb[m];
		}
		else
		{
			if (allnumb[m] < 0)
				allnumb[m] = -1 * allnumb[m];
		}
	}

	if (!fopen_s(&f, "B.bin", "wb"))// Запист в файл и вывод в консоль
	{
		for (int m = 0; m < mysize - 1; m++)
		{
			fwrite(&allnumb[m], sizeof(int), 1, f);
			cout << endl << allnumb[m] << endl;
		}
		fclose(f);
	}

	else {
		cout << "Ошибка открытия файла";
		return;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	bool ex = false;

	do {
		cout << "\n1.Перезаписать файл А\n";
		cout << "2.Создать файл B\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nВведите количество чисел которые вы хотите ввести\n" << endl;
			cin >> mysize;
			input(mysize);
			break;
		case 2:
			output();
			break;
		case 0:
			ex = true;
			break;
		}
	} while (!ex);


}
