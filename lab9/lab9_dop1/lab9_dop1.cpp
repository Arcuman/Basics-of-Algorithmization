// lab9_dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include<iostream>
using namespace std;
struct Item
{
	int data;
	Item *next;
};
Item *head, *tail;

bool isNull(void)    //Проверка на пустоту
{
	return (head == nullptr);
}
void deletFirst()   //Извлечение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		Item *p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //Получение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Начало = " << head->data << endl;
}
void getFromTail()  //Получение элемента из конца
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Конец = " << tail->data << endl;
}
void insertToQueue(int x)  //Добавление элемента в очередь 
{
	Item *p = new Item;      //новый указатель 
	p->data = x;
	p->next = nullptr;
	Item *v = new Item;      //указатель для нового числа
	Item *p1 = new Item;
	Item *p2 = new Item;
	int i = 0;               //флажок 
	if (isNull())
		head = tail = p;
	else
	{
		p2 = head; p1 = head; // !!!Чтобы реализовать ввод LiFo необходимо чтобы указатель p2 был позади, FiFo наобарот
		while (p1 != nullptr)  //пока очередь не закончится
		{
			/*if (i == 1) //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
			{*/
			if (i == 1)
			{
				if (x > p1->data)  //число больше, чем в очереди
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				if (x == p1->data)
				{
					v->data = x;
					v->next = p1->next;
					p1->next = v;
					return;
				}
				p2 = p2->next;
			}
			if (x > p1->data)
			{
				v->data = x;
				v->next = p1;
				head =  v;
				return;
			}
			if (p1->next == nullptr)
			{
				v->data = x;
				v->next = nullptr;
				tail->next = v;
				tail = v;
				return;
			}
			i = 1;

			p1 = p1->next;      // следующее число
		/*}*/
		/*else // else необходимое для реализации вставки LiFo
		{
			if (x >= p1->data)
			{
				v->data = x;
				v->next = p2;
				head = v;
				return;
			}
		}*/
		/*p1 = p1->next; //ТАКЖЕ НЕОБХОДИМЫ ДЛЯ РЕАЛИЗАЦИИ LiFo
		i = 1;*/
		/*}
		if (p1 == NULL) // Выражение ДЛЯ РЕАЛИЗЦИИ LiFo
		{
			v->data = x;
			v->next = tail;
			p2.next = v;
		}*/
		}
	}
}
void printQueue()             //Вывод очереди
{
	Item *p = new Item;
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!isNull())
		{
			if (p != nullptr)
			{
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()           //Очистка очереди
{
	while (!isNull()) deletFirst();
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, z; head = nullptr;  tail = nullptr;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "6 - получить элемент с конца" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие  ";  cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент:  "; cin >> z;
			insertToQueue(z); printQueue();  break;
		case 2: getFromHead(); break;
		case 3: deletFirst();  break;
		case 4: printQueue();  break;
		case 5: clrQueue();    break;
		case 6: getFromTail(); break;
		}
	}
	return 0;
}
