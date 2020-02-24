//вариант 1
#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
int **m1;
int **m2;
int **C;
int size1;
int size2;
int rows1;
int rows2;
int cols1;
int cols2;
FILE *f;
errno_t err;
void enter(int *Arr, int row, int col)// Заполнение массива и вывод
{
	Arr[0] = col;
	for (int i = 1; i <= row * col; i++)
	{
		if (i % 2 == 0)
			Arr[i] = 1;
		else Arr[i] = 2;
	}
}

void input(char *path) // Ввод в файл
{
	int row, col;
	cout << "Введите количество строк и колонок" << endl;
	cin >> row >> col;
	int * Arr = (int*)malloc((row*col + 1) * sizeof(int)); // Объявление массива
	enter(Arr, row, col);
	if (!fopen_s(&f, path, "wb"))
	{
		for (int p = 0; p <= row * col; p++)
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

void output1(char *path) // Вывод из файла
{
	if (!fopen_s(&f, path, "rb"))
	{
		fseek(f, 0L, SEEK_END); //ставим указатель в конец
		size1 = ftell(f); //Вычисляем размер файла M1
		fseek(f, 0L, SEEK_SET); //ставим указатель в начало
		fread(&cols1, sizeof(int), 1, f); //читаю первый элемент массива(кол-во столбцов)
		rows1 = ((size1 / sizeof(int)) - 1) / cols1; //вычисляю количество строк
		m1 = (int**)malloc(size1 - sizeof(int)); // Объявление массива
		for (int i = 0; i < rows1; i++)
		{
			m1[i] = (int*)malloc(sizeof(int)*cols1);
		}
		cout << "Массив " << path << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				fread(&m1[i][j], sizeof(int), 1, f); //читаю массив из файла
				cout << m1[i][j] << " "; //Вывод массива в консоль
			}
			cout << endl;
		}
		cout << endl;
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void multiplication() {
	C = (int**)malloc(cols2*rows1 * sizeof(int)); // Объявление двухмерного массива
	for (int i = 0; i < rows1; i++)
	{
		C[i] = (int*)malloc(sizeof(int)*cols2);
	}
	cout << "Matrix C: " << endl;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			C[i][j] = 0; //инициализация массива
		}
	}
	for (int i = 0; i < rows1; i++) // Перемножаем матрицы
	{
		for (int k = 0; k < cols1; k++)
		{
			for (int j = 0; j < rows2; j++)
			{
				C[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			cout << C[i][j] << " "; //Вывод массива в консоль
		}
		cout << endl;
	}if (!fopen_s(&f, "C.bin", "wb"))
	{
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols2; j++)
				fwrite(&C[i][j], sizeof(int), 1, f); //запись в файл С
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	free(C);
}


void output2(char *path) // Вывод из файла M2
{
	if (!fopen_s(&f, path, "rb"))
	{
		fseek(f, 0L, SEEK_END); //ставим указатель в конец
		size2 = ftell(f); //Вычисляем размер файла M2
		fseek(f, 0L, SEEK_SET); //ставим указатель в начало
		fread(&cols2, sizeof(int), 1, f); //читаю первый элемент массива(кол-во столбцов)
		rows2 = ((size2 / sizeof(int)) - 1) / cols2; //вычисляю количество строк
		m2 = (int**)malloc(size2 - sizeof(int)); // Объявление двухмерного массива
		for (int i = 0; i < rows2; i++)
		{
			m2[i] = (int*)malloc(sizeof(int)*cols2);
		}
		cout << "Массив " << path << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				fread(&m2[i][j], sizeof(int), 1, f); //читаю массив из файла
				cout << m2[i][j] << " "; //Вывод массива в консоль
			}
			cout << endl;
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
	setlocale(LC_CTYPE, "Russian");
	char path1[] = "M1.bin";
	char path2[] = "M2.bin";
	input(path1);
	input(path2);
	output1(path1);
	output2(path2);
	if (cols1 == rows2)
	{
		multiplication();
	}
}