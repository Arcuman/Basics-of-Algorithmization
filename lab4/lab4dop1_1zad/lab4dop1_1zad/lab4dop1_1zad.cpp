// lab4dop1_1zad.cpp : 14 вариант

#include "pch.h"							
#include <iostream>
#include <stdio.h>
#include <iomanip>
#define size 5
using namespace std;
FILE * fp; // указатель на фаловый поток
void write(char * filename, int *mass);
void output(char * filename);
void stolb(); // ф-ция создания файла с k-ым столбцом
int main()
{
	char filename[] = "data.bin";
	int num = 1;
	int mass[size][size];
	for (int i = 0; i < size; i++) // Заполняем массив
		for (int j = 0; j < size; j++)
			mass[i][j] = num++;

	write(filename, mass[0]); // записывает исходный массив в файл data.bin
	output(filename); // считывает и выводит исходный массив из файла data.bin
	stolb(); // принимает номер столбца, считывает столбец из data.bin и записывает его в stolb.bin
	system("pause");
}

void write(char * filename, int *mass)
{
	if (!fopen_s(&fp, filename, "ab"))
	{
		for (int i = 0; i < size; i++)
			fwrite((mass + i), sizeof(int) * size, size, fp); // Запись матрицы в файл
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void output(char * filename)
{
	if (!fopen_s(&fp, filename, "rb"))
	{
		int arr[size][size];
		fread(arr, sizeof(int) * size, size, fp); // Вывод матрицы из файла
		for (int i = 0; i < size; i++)  // Вывод матрицы на экран
		{
			for (int j = 0; j < size; j++)
				cout << setw(4) << *(*(arr + j) + i);
			cout << endl;
		}
		cout << endl;
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
void stolb() // ищем , записываем и выводим столбец 
{
	int k;
	cout << "Enter k: ";
	cin >> k;
	int arr[size];
	k--;
	if (!fopen_s(&fp, "data.bin", "rb"))
	{
		fseek(fp, 20 * k, SEEK_SET);
		fread(arr, sizeof(int), size, fp);
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
	if (!fopen_s(&fp, "stolb.bin", "wb"))
	{
		fwrite(arr, sizeof(int), size, fp);
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}

	if (!fopen_s(&fp, "stolb.bin", "rb"))
	{
		fseek(fp, 20 * k, SEEK_SET);
		fread(arr, sizeof(int), size, fp);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
		fclose(fp);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
