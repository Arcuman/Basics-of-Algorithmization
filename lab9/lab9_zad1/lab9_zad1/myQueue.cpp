#include "pch.h"
#include "myQueue.h"
#include <iostream>


void create(int x, Number *Queue1)   //Добавление элемента х в очередь
{
	Number *t = new Number;
	t->info = x;
	t->next = nullptr;
	if (Queue1->head == nullptr)
	{
		Queue1->head = Queue1->last = t;
	}
	else
	{
	Queue1->last->next = t;
	Queue1->last = t;
	}
}


void view(Number *Queue1)
{
	Number *t = Queue1->head;
	if (t == nullptr)
	{
		std::cout << "Number is empty\n";
		return;
	}
	else
	{
		std::cout << "Queue: \n";
		while (t != nullptr)
		{
			std::cout << t->info << std::endl;
			t = t->next;
		}
	}
}

void Del(Number *Queue1) //Удаление всей очереди
{
	Number *t;
	t = new Number;
	while (Queue1->head)
	{
		t = Queue1->head;
		Queue1->head = Queue1->head->next;
		delete t;
	}
}

void Count(Number *Queue1) //Посчет элементов 
{
	int count = 0;
	Number *t;
	t = new Number;
	t = Queue1->head;
	while (t)
	{
		count++;
		t = t->next;
	}
	std::cout <<"Количество элементов очереди: " <<count << std::endl;
}


void Form(Number *begin, Number *Queue1, Number *Queue2)
{
	Number * t =	begin->head;
	Number *t1 = Queue1->head;
	Number *t2 = Queue2->head;
	while (t)
	{
		Number *temp = new Number;
		temp->info = t->info;
		temp->next = nullptr;
		if (t->info % 2 == 0)
		{
			if (Queue1->head == nullptr)
			{
				Queue1->head = Queue1->last = temp;
			}
			else
			{
				Queue1->last->next = temp;
				Queue1->last = temp;
			}
		}
		else
		{
			if (Queue2->head == nullptr)
			{
				Queue2->head = Queue2->last = temp;
			}
			else
			{
				Queue2->last->next = temp;
				Queue2->last = temp;
			}
		}
		t = t->next;
	}
	view(Queue1);
	view(Queue2);
}
