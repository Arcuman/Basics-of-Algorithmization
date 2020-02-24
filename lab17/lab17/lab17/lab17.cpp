// lab17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;
void outarray(int f[])
{
	cout << "Array: " << endl;
	for (int i = 0; i < 10; i++)
		cout << f[i] << " ";
	cout << endl;
}

int* sort_bublez(int m[], int lm)
{
	int buf;
	for (int i = 0; i < lm; i++)
		for (int j = 0; j < lm - i - 1; j++)
			if (m[j] > m[j + 1])
			{
				buf = m[j];
				m[j] = m[j + 1];
				m[j + 1] = buf;
			}
	outarray(m);
	return m;
}

void countSort(int in[], int size ,int out[] )//in - исходный массив out - массив вывода 
{
	int i, j, count; 
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j) // 
			if (in[j] < in[i] || (in[j] == in[i] && i < j)) //Подсчет количества элементов меньше чем in[i] или равным при условии что i < j
				count++;
		out[count] = in[i]; //индекс элемента [i]  ==  количеству элементов меньшех чем i
	}
	outarray(out);
}
void selectSort(int A[], int size) //Сортировка выбором
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++) //Ищем минимальный элемент в диапозоне от i до size 
			if (A[j] < A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c; //ставь его на место i элемента
	}
	outarray(A);
}
//------------------------------
int* sort_Shella(int m[], int size)
{
	int buf;
	bool sort;
	for (int g = size / 2; g > 0; g /= 2)
		do
		{
			sort = false;
			for (int i = 0, j = g; j < size; i++, j++)
				if (m[i] > m[j])
				{
					sort = true;
					buf = m[i];
					m[i] = m[j];
					m[j] = buf;
				}
		} while (sort);
		return m;
}

int getRandKey(int reg = 0)     // генерация случайных ключей
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}


//
////------------------------------
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	const int N = 30000; // МЕНЯТЬ количество повторений
//	int k[N], f[N] , k1[N];
//	clock_t  t1, t2;
//	getRandKey(1);
//	for (int i = 0; i < N; i++)
//		f[i] = getRandKey(0);
//	outarray(f);
//	for (int n = 10000; n <= N; n += 10000)
//	{
//		cout << "n = " << n << endl;
//		cout << "SortPuzirek ";
//		memcpy(k, f, n * sizeof(int));
//		t1 = clock();
//		sort_bublez(k, n);
//		t2 = clock();
//		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
//		cout << "SortPodscheta ";
//		memcpy(k, f, n * sizeof(int));
//		t1 = clock();
//		countSort(k, n , k1);
//		t2 = clock();
//		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
//		cout << "SortShell    ";
//		memcpy(k, f, n * sizeof(int));
//		t1 = clock();
//		sort_Shella(k, n);
//		t2 = clock();
//		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
//		cout << "SortViboram   ";
//		
//		memcpy(k, f, n * sizeof(int));
//		t1 = clock();
//		selectSort(k, n);
//		t2 = clock();
//		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
//	}
//	outarray(k);
//	return 0;
//}
