//
//					ДОПОЛНИТЕЛЬНОЕ ЗАДАНИЕ 2 
//
#include "pch.h"
#include <iostream>
#include <ctime>   
using namespace std;
int getRandKey(int reg = 0)     // генерация случайных ключей
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}

void outarray(int f[] , int size) //Вывод массива
{
	cout << "Array: " << endl;
	for (int i = 0; i < size; i++)
		cout << f[i] << " ";
	cout << endl;
}
//---------------------------------------------------------------------------------ФУНКЦИИ ДЛЯ ДОПА 2
void findMax(int f[], int size)
{
	int maxI = 0, max = f[0];
	for (int i = 0; i < size; i++) {
		if (f[i] > max) {
			max = f[i];
			maxI = i;
		}
	}
	cout << "Максимальный элемент: " << max << " под номером: " << maxI << endl;
}

void findMin(int f[], int size)
{
	int maxI = 0, max = f[0];
	for (int i = 0; i < size; i++) {
		if (f[i] < max) {
			max = f[i];
			maxI = i;
		}
	}
	cout << "Минимальный элемент: " << max << " под номером: " << maxI << endl;
}
//------------------------------------------------------- КОНЕЦ ФУНКЦИЙ ДЛЯ ДОПА 2 
//----------------------------------------------------------------------------------ФУНКЦИИ ДЛЯ ДОПА 3

int* sort_Shella_From_down_To_up(int m[], int size) //Функция сортировки по возрастаню Шелла 
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
int* sort_Shella_From_up_To_down(int m[], int size)//Функция сортировки по убыванию Шелла 
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
		return m;
}
void fill_arr(int arr[], int f[], int index) // заполнение первых/последних 4 элементов в соотвествуюшие  массивы
{
	for (int i = 0, j = index; i < 4; i++, j++)
	{
		f[i] = arr[j];
	}
}

void fill_arr_back(int arr[], int f[], int index) // заполнение первых/последних 4 элементов в исходный массив
{
	for (int i = 0, j = index; i < 4; i++, j++)
	{
		f[j] = arr[i];
	}

}
//------------------------------------------------------- КОНЕЦ ФУНКЦИЙ ДЛЯ ДОПА 3
//----------------------------------------------------------------------------------ФУНКЦИИ ДЛЯ ДОПА 4

int getRandKey_dop(int reg = 0)     // генерация случайных ключей в диапозоне от -5 до 5
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	return (int)( -5 + rand() % 15 );
}

int delete_repeating(int arr[],int size) // Удаление повторяющихся 
{ 
	int size_end = size; //Конечный размер массива
	for (int i = 0; i < size ; i++) // сравниваем первый элементо со всеми остальными 
	{
		for (int j = i+1; j < size; j++) 
		{
			if ((arr[i] == arr[j])&&arr[j]!=20) // если элемент повторяется дадим ему значение 20 и уменьшим размер 
			{
				size_end--;
				arr[j] = 20;
			}
		}

	}
	return size_end;
}


int main()
{
	setlocale(LC_CTYPE, "Russian"); 
	//---------------------------------------------------------Начало допа 2 
	int N;
	cout << "---------Доп 2 ----------" << endl;
	cout << "Enter size of array" << endl;
	cin >> N;
	int * f = new int[N];
	getRandKey(1); 
	for (int i = 0; i < N; i++)// заполнение массива
		f[i] = getRandKey(0);
	outarray(f , N); // Вывод массива
	findMax(f,N); // поиск максимального элемента 
	findMin(f, N);// поиск минимального элемента 
	delete[] f; 
	//-----------------------------------------------------------Конец допа 2
	//----------------------------------------------------------НАЧАЛО ДОПА 3
	cout << "---------Доп 3 ----------" << endl;
	int arr[10],first_4[4],last_4[4]; // исходный массив , массив для первых и последних 4 элементов
	for (int i = 0; i < 10; i++) // заполняем массив 
		arr[i] = getRandKey(0); 
	outarray(arr, 10); // вывод массива
	fill_arr(arr, first_4, 0);	//заполнение массива для первых 4-х элемнтов 
	fill_arr(arr, last_4, 6);//заполнение массива для последних 4-х элемнтов 
	sort_Shella_From_down_To_up(first_4, 4);//сортировка послених 4-х по возврастанию
	sort_Shella_From_up_To_down(last_4, 4); //сортировка первых 4-х по убыванию
	fill_arr_back(first_4, arr, 0); //перезапись первых 4-х цифр
	fill_arr_back(last_4, arr, 6);//перезапись последних 4-х цифр
	outarray(arr, 10);
	//-----------------------------------------------------------Конец допа 3
	//----------------------------------------------------------НАЧАЛО ДОПА 4
	cout << "---------Доп 4 ----------" << endl;
	int Array[15];
	int size = 15;
	getRandKey_dop(1);
	for (int i = 0; i < 15; i++)// заполнение массива
		Array[i] = getRandKey_dop(0);
	outarray(Array, size); //Вывод массива
	int size_end = delete_repeating(Array,15); //Удаление повторяющихся элементов  и вычисление размера массива после удаления повторяющихся элементов
	sort_Shella_From_down_To_up(Array, size); //сортировка Шелла
	outarray(Array, size_end);//вывод отсортированного массива

}
