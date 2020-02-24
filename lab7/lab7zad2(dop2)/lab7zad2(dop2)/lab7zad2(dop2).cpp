// lab7zad2(dop2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;
struct Person
{
	int number;
	Person *next;
};      
int conventer(void* b)
{
	Person *a = (Person*)b;
	return a->number;
}
void print(void* b)       //Функция используется при выводе 
{
	Person *a = (Person*)b;
	cout << a->number << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { 1 };
	Person a2 = { 4 };
	Person a3 = { 3 };
	Person a4 = { 5 };
	Person a5 = { 2 };
	Object L1 = Create();
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.Insert(&a4);
	L1.Insert(&a5);
	Object L2 = Create();
	L2.Insert(&a1);
	L2.Insert(&a2);
	L2.Insert(&a3);
	L2.Insert(&a4);
	L2.Insert(&a5);
	cout << "Our list: " << endl;
	L1.PrintList(print);
	L1.SortPositive(conventer);
	cout << "Our list after SortPositive: " << endl;
	L1.PrintList(print);
	L2.SortEven(conventer);
	cout << "Our list after SortEven: " << endl;
	L2.PrintList(print);
	system("pause");
}
