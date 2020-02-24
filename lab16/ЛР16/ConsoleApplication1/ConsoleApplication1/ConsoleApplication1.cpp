// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define N 10
int insertB(int A[], int B[], int size)
{
	int k = 0,j;
	for (int i = 1 ; i < size; i+=2)
	{
		j = i+1;
		if (A[j] % 2 == 0);
		{
			B[k] = A[i];
			k++;
		}
	}
	return k;

}

//Сортировка пузырьком-------------------------
void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
//-------------------------------------------------

void swapEl(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//Сортировка подсчетом----------------------

void countSort(int in[], int out[], int size)
{
	int i, j, count;
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))
				count++;
		out[count] = in[i];
	}
}


//------------------------------------------------------

//ф-ция "шейкер"-сортировки

void myShakerSort(int *arr, int size)
{
	int leftMark = 1;//левая граница
	int rightMark = size - 1; //правая граница
	while (leftMark <= rightMark) //пока не втретятся
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i])
				swapEl(arr, i);
		leftMark++;
		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i])
				swapEl(arr, i);
		rightMark--;
	}
}
//---------------------------------------------------------------

//ПИРАМИДАЛЬНАЯ СОРТИРОВКА
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
}

//ВЫБОРОМ
void selectSort(int B[], int n)
{
	int k, i, j, min;
	for (i = 0; i < n; i++)
	{
		k = i;
		min = B[i];
		for (j = i + 1; j < n; j++)
			if (B[j] < min)
			{
				k = j;
				min = B[j];
			}
		B[k] = B[i];
		B[i] = min;
	}
}

void Shell(int A[], int n) //сортировка Шелла
{
	int d = n, j, i, count;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && A[j] > A[j + d])
			{
				count = A[j];
				A[j] = A[j + d];
				A[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}

// ПОРАЗРЯДНАЯ --------------------------------------

void Sort(int* begin, int size, unsigned bit = 0x80000000)
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

	Sort(begin, last, bit >> 1);
	Sort(begin + last, size - last, bit >> 1);
	
}

void insOrd(int m[], int sm, int em, int e)
{ // m[]  массив чисел; sm  индекс 1-ого элемента левой части; cm  индекс
  //последн. элемента левой части; em  индекс последн. элемента правой ча-сти
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}

int*  merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}

int* sortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}


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
			cout << i + 1 << " элемент = ";
			cin >> A[i];
		}
		int sizeB = insertB(A,B,size);
		int* P = new int[sizeB];
		for (i = 0; i < sizeB; i++)
			P[i] = rand() % 1000;

		//bubbleSort(B, sizeB);  //ПУЗЫРЬКОМ 
		//Shell(B, sizeB);			//ШЕЛЛА
		
		//--------------ОСНОВНОЕ---------------------------
		
		//myShakerSort(B, sizeB);	//ШЕЙКЕРНАЯ ++
		//countSort(B, P, sizeB);	//ПОДСЧЕТОМ ++
		//piramSort(B, sizeB);	//ПИРАМИДАЛЬНАЯ ++
		//selectSort(B, sizeB);		//ВЫБОРОМ   ++

		//--------------ДРУГИЕ------------------------------
		
		//Sort(B, sizeB, 0x80000000);
		sortMerge(B,1,sizeB);
		
		cout << "Результирующий массив: ";
		for (i = 0; i < sizeB; i++)
			cout << B[i] << " ";
		cout << endl;
	

}
