// lab17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;
void outarray(int f[])
{
	for (int i = 0; i < 10; i++)
		cout << f[i] << " ";
	cout << endl;
}

void radix_int(int* begin, int size, unsigned bit = 0x80000000)
{
	if (!bit)
		return;

	if (size < 2)
		return;

	int last = 0;
	for (int i = 0; i < size; i++)
	{
		if ((begin[i] & bit) == 0)
			swap(begin[last++], begin[i]);
	}

	radix_int(begin, last, bit >> 1);
	radix_int(begin + last, size - last, bit >> 1);
}
void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n  &&  A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
	outarray(A);
}

void countSort(int in[], int size, int out[])//сортировка подсчетом in - исходный массив out - массив вывода 
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
		outarray(m);
		return m;
}

int getRandKey(int reg = 0)     // генерация случайных ключей
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 1000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}



//------------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n = 10;
	int k[n], f[n] , k1[n];
	getRandKey(1);
	for (int i = 0; i < n; i++)
		f[i] = getRandKey(0);
	cout << "Исходный массив: " << endl;
		outarray(f) ;
	
		cout << "Массив после сортировки Шелла:  " << endl;
		memcpy(k, f, n * sizeof(int));
		sort_Shella(k, n);
		cout << "Массив после сортировки подсчетом: " << endl;
		memcpy(k, f, n * sizeof(int));
		countSort(k, n , k1);
		cout << "Массив после пирамидальной сортировки: " << endl;
		memcpy(k, f, n * sizeof(int));
		piramSort(k, n);
		cout << "Массив после поразрядной сортировки: " << endl;
		memcpy(k, f, n * sizeof(int));
		radix_int(k,n);
		outarray(k);
	system("pause");
	return 0;
}
