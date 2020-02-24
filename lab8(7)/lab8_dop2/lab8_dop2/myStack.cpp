#include "pch.h"
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;
void push(int x, Stack *myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}


void show(Stack *myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
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

void readFromFile(Stack *myStk)          //Считывание из файла
{
	int min = 1024, i= 1 , counter = 0; 
	struct Stack *t;
	char *str = new char[1024];
	ifstream F1("F1.txt"); //Информация из файла
	cout << "Загрузка из файла" << endl;
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		push(strlen(str), myStk);
		if (min >= strlen(str))
		{
			min = strlen(str);
			counter = i;
		}
		i++;
	}
	show(myStk);
	cout << endl << "Последняя самая короткая строка под номером: " << counter << " Длина строки = " << min << endl;
}