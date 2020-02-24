#include "pch.h"
#include "myQueue.h"
#include<iostream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Number *Queue1 = new Number; //выделение памяти для очереди
	Number *Queue2 = new Number; //выделение памяти для очереди
	Number *Queue3= new Number; //выделение памяти для очереди
	Queue1->head = nullptr;       //инициализация первого элемента	
	Queue2->head = nullptr;
	Queue3->head = nullptr;
	int choice,size;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элементов в очередь" << endl;
		cout << "2 - Вывод элементов" << endl;
		cout << "3 - Удаление всех элементов очереди" << endl;
		cout << "4 - Определение размера" << endl;
		cout << "5 - Формирование и вывод двух очередей по четности" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите размер вводимых элементов:" << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout <<"Введите цифру " << endl;
				cin >> choice;
				create(choice, Queue1);
			}
			break;
		case 2:
			view(Queue1);
			break;
		case 3:
			Del(Queue1);
			break;
		case 4:
			Count(Queue1);
			break;
		case 5:
			Form(Queue1, Queue2, Queue3);
			break;
		case 6: return 0;
			break;
		default:
			break;
		}
	}
}
