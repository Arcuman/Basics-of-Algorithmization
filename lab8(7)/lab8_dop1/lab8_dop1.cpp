// lab8_dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct Stack
{
	char data;             //информационный элемент
	Stack *head;		 //вершина стека 
	Stack *next;		 //указатель на следующий элемент
};
void push(char x, Stack *myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack; //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e; //сдвиг вершины на позицию вперед
	e->next;
}
void show(Stack *myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
char pop(Stack *myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack *e = myStk->head;   //е - переменная для хранения адреса элемента
		char a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
int main()
{

	setlocale(LC_ALL, "Rus");
	Stack *Stack1 = new Stack; //выделение памяти для стека
	Stack1->head = nullptr;
	string a,b;
	cout << "Введите строку из четного кол-ва букв" << endl;
	do
	{
		getline(cin, a);
		if (a.length() % 2 == 0 )
		{
			break;
		}
	} while (1);
	cout << a  << "  "<< a.length()  << endl;
	for (int i = 0; i < a.length() / 2; i++) //заполняем первую половину в стек
	{
		push(a[i],Stack1);
	}
	show(Stack1);
	while (Stack1->head != NULL) //Записываем в строку b
	{
		b += pop(Stack1);
	}
	for (int i = a.length()/2; i < a.length(); i++)//заполняем вторую половину в стек
	{
		push(a[i], Stack1);
	}
	show(Stack1);
	while( Stack1->head != NULL)//Записываем в строку b
	{
		b += pop(Stack1);
	}
	cout << endl << b;
}

