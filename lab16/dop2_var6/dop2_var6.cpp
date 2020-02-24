// dop2_var6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
const int MAX = 20;

void sort_Shella(int m[], int size)
{
	int buf;
	bool sort;
	for (int g = size / 2; g > 0; g /= 2)
		do
		{
			sort = false;
			for (int i = 0, j = g; j < size; i++, j++)
				if (m[i] < m[j])
				{
					sort = true;
					buf = m[i];
					m[i] = m[j];
					m[j] = buf;
				}
		} while (sort);
}

void selectSort(int A[], int size) //Сортировка выбором
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++) //Ищем минимальный элемент в диапозоне от i до size 
			if (A[j] > A[k])
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c; //ставь его на место i элемента
	}
}

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 9, k = 0, s = 0;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 20;
		cout << A[i] << " ";
		if (!(i % 2))
			k++;
	}
	cout << endl;
	int *B = new int[k];
	for (int i = 0; i < n; i += 2)
	{
		B[s] = A[i];
		s++;
	}
	for (int i = 0; i < s; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	int c;
	cout << "1-Шелла" << endl;
	cout << "2-выбором" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		sort_Shella(B, s);
		break;
	case 2:
		selectSort(B, s);
		break;
	default:
		break;
	}
	for (int i = 0; i < s; i++)
	{
		cout << B[i] << " ";
	}

}