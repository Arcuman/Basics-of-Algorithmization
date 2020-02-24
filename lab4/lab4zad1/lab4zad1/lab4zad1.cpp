//Вариант 9
#include "pch.h"
#include <iostream>
int n = 5;
int * Arr = (int*)malloc(n * sizeof(int)); // Объявление массива
int * B = (int*)malloc(n * sizeof(int));
int number;
FILE * f;
using namespace std;
errno_t err;
void enter()// Заполнение массива и вывод
{
	for (int i = 0; i < n; i++) 
	{
		if (i % 2 == 0)
			Arr[i] = 1;
		else Arr[i] = 2;
	}
	cout << "Massiv "<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i];
	}
	cout << endl;

}
void change() // Убираем повторяющиеся элементы 
{
	for (int i = 0; i < n - 1; i++) // Убираем повторяющиеся элементы 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (Arr[i] == Arr[j]) //  Нашли повтор 
			{
				for (int k = j; k < n; k++)
					Arr[k] = Arr[k + 1]; // Сдвигаем все следующие элементы на 1 справа-налево 
			}
			n = n - 1; // "Укорачиваем" массив 
			j = j - 1;
		}
	}
	n++;
	cout << "Array after changing " << endl;
	for (int i = 0; i < n; i++) // Заполняем новый массив без повторяющихся элементов
	{
		B[i] = Arr[i];
		cout << B[i];
	}
	cout << endl;
}

void inputA(int size) // Ввод в файл А
{
	if (!fopen_s(&f, "A.bin", "wb"))
	{
		for (int p = 0; p < size; p++)
		{
			fwrite(&Arr[p], sizeof(int), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	free(Arr);
}
void inputB(int size)
{
	if (!fopen_s(&f, "B.bin", "wb"))
	{
		for (int p = 0; p < size; p++)
		{
			fwrite(&B[p], sizeof(int), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	free(B);
}
void outputA() // Вывод из файла
{
	int j = 0;
	if (!fopen_s(&f, "A.bin", "rb"))
	{
		fread(&Arr[0], sizeof(int), 1, f);
		cout << "Array from A.bin" << endl;
		while (!feof(f))
		{
			cout  << Arr[j] ;
			j++;
			fread(&Arr[j], sizeof(int), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}
void outputB() // Вывод из файла
{
	int j = 0;
	if (!fopen_s(&f, "B.bin", "rb"))
	{
		fread(&B[0], sizeof(int), 1, f);
		cout << "Array from B.bin" << endl;
		while (!feof(f))
		{
			cout << B[j];
			j++;
			fread(&B[j], sizeof(int), 1, f);
		}
		cout << endl;
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
	enter();
	inputA(n);
	outputA();
	change();
	inputB(n);
	outputB();
}
