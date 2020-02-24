// lab4zad1_new.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"							
#include <iostream>
#include <stdio.h>
#include <iomanip>
#define size 5
using namespace std;
FILE * fp; // указатель на фаловый поток
void write(char * filename, int *mass);
void output(char * filename);
void change(char * filename);
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
	change(filename);
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
void change(char * filename)
{
	if (!fopen_s(&fp, filename, "rb"))
	{
		int arr[size][size];
		fread(arr, sizeof(int) * size, size, fp); // Вывод матрицы из файла
		fclose(fp);
		int t;
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				t = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = t;
			}
		}
		if (!fopen_s(&fp, "trans.bin", "wb"))
		{
			fwrite(arr, sizeof(int), size, fp);
			fclose(fp);
		}
		else
		{
			cout << "Ошибка открытия файла";
			return;
		}
		if (!fopen_s(&fp, "trans.bin", "rb"))
		{
			fread(arr, sizeof(int) * size, size, fp);
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
		cout << endl;
		
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}