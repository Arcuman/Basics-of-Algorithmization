// lab7zad1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "List.h"
using namespace std;
struct Person
{
	char name[20];
	int age;
	Person *next;
};

void print(void* b)       //Функция используется при выводе 
{
	Person *a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "Петров", 20 };
	Person a2 = { "Сидоров", 25 };
	Person a3 = { "Гончаров", 47 };
	Person a31 = { "Гончаров", 48 };
	Person a4 = { "Орлов", 24 };
	Person a5 = { "Бунич",  55 };
	Person a6 = { "Borisov",  18 };
	Person* aa;
	bool rc;
	Object L1 = Create();   // создать список L1
	rc = L1.Insert(&a1);     // = true
	rc = L1.Insert(&a2);     // = true 
	rc = L1.Insert(&a3);     // = true 
	rc = L1.Insert(&a4);     // = true  
	rc = L1.Insert(&a5);
	L1.PrintList(print);
	rc = L1.InsertEnd(&a6);
	L1.PrintList(print);
	cout << "----------------------------" << endl;
	Element* e = L1.GetLast();
	e = L1.Search(&a3);
	aa = (Person*)e->Data;
	L1.CountList();
	L1.DeleteList();
	L1.PrintList(print);
	cout << "Удаление успешно " << endl;
	cout << "Найден элемент= " << aa->name << endl;
	e = L1.Search(&a5);

	return 0;
}

