#include "pch.h"
#include <iostream>
#include "myStack.h"
using namespace std;
void push(int x, Stack *myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}

int pop(Stack *myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack *e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
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
void clear(Stack *myStk)    //Clear стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (myStk->head != NULL)
	{
		e = myStk->head;
		myStk->head = myStk->head->next;
		delete e;
	}
}
void writeToFile(Stack *myStk)//Запись в файл
{
	struct Stack *t = myStk->head;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;

	while (t)
	{
		fwrite(t, sizeof(struct Stack), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
void readFromFile(Stack *myStk)          //Считывание из файла
{
	struct Stack *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Stack();
		if (!t)
		{
			cerr << "Ошибка выделения памяти памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Stack), 1, fp))
			break;
		push(t->data, myStk);
	}
	fclose(fp);
}
void fillnewstack(Stack *Stack1 , Stack *Stack2, Stack *Stack3)
{
	struct Stack *t1 = Stack1->head;
	struct Stack *t2 = Stack2->head;
	struct Stack *t3 = Stack3->head;
	int temp = 0;
	while(t1!=NULL) //ПРоверяем на совпадение э 
	{
		while (t2 != NULL)
		{
			if (t1->data != t2->data)
			{
				temp++;
				t2 = t2->next;
			}
			else
			{
				temp = 0;
				break;
			}
		}
		if (temp)
		{
			push(t1->data, Stack3);
		}
		t1 = t1->next;
		t2 = Stack2->head;
	}

}