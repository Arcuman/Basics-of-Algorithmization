// dop1var.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
const int MAX = 20;
void selectSort(int A[], int size) //Сортировка выбором (12 вариант)
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
void BubbleSort1(int A[], int size) //Сортировка пузырьком (12 вариант)
{
	int i, j, count, key;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			key = j + 1;
			count = A[key];
			if (A[j] < A[key])
			{
				A[key] = A[j];
				A[j] = count;
			}
		}
	}
}
void BubbleSort(int A[], int size)
{
	int i, j, count, key;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			key = j + 1;
			count = A[key];
			if (A[j] > A[key])
			{
				A[key] = A[j];
				A[j] = count;
			}
		}
	}
}
void insertSort(int *A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
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
	cout << "1-пузырбком" << endl;
	cout << "2-простой вставкой" << endl;
	cout << "3-выбором(12 вариант)" << endl;
	cout << "4-пузырбком(12 вариант)" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		BubbleSort(B, s);
		break;
	case 2:
		insertSort(B, s);
		break;
	case 3:
		selectSort(B, s);
		break;
	case 4:
		BubbleSort1(B, s);
		break;
	default:
		break;
	}
	for (int i = 0; i < s; i++)
	{
		cout << B[i] << " ";
	}

}