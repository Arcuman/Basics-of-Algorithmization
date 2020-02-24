// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define N 10
int insertB(int A[], int B[], int size)
{
	int maxI,max;
	max = A[0];
	for (int i = 0; i < 10; i++) {
		if (A[i] > max) {
			max = A[i];
			maxI = i;
		}
	}
	int k = 0,j;
	for (int i = maxI + 1 ; i < size; i ++)
	{
		if (i % 2 == 1)
		{
			B[k] = A[i];
			k++;
		}
	}
	return k;

}

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
void swapEl(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//ф-ция "шейкер"-сортировки
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};


int main()
{

	setlocale(LC_ALL, "Rus");
	int size, i;
	int A[20];
	int B[20];
	cout << "Количество элементов = ";
	cin >> size;
	for (i = 0; i < size; i++)
	{
		cout << i  << " элемент = ";
		cin >> A[i];
	}
	int sizeB = insertB(A, B, size);
	cout << "Результирующий массив: ";
	for (i = 0; i < sizeB; i++)
		cout << B[i] << " ";
	cout << endl;
	int c;
	cout << "1-пузырбком" << endl;
	cout << "2-шейкерная" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		bubbleSort(B, sizeB);
		break;
	case 2:
		getHoarBorder(B, 0 , sizeB- 1);
		break;
	default:
		break;
	}
		cout << "Результирующий массив: ";
		for (i = 0; i < sizeB; i++)
			cout << B[i] << " ";
		cout << endl;
		system("pause");
}
