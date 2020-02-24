// lab8_zad1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "myStack.h"
using namespace std;

int main()	
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack *Stack3 = new Stack; //выделение памяти для стека
	Stack *Stack1 = new Stack; //выделение памяти для стека
	Stack *Stack2 = new Stack; //выделение памяти для стека
	Stack *temp = NULL;
	Stack1->head = NULL;       //инициализация первого элемента	
	Stack2->head = NULL;
	Stack3->head = NULL;
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Чистка стека" << endl;
		cout << "5 - Запись в файл стека" << endl;
		cout << "6 - Запись из файла стека" << endl;
		cout << "7 - Запись в новый стек" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: 
			cout << "В какой стек заполняем : \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, temp);
			break;
		case 2:
			cout << "Из какого берем: \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			choice = pop(temp);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: 
			cout << "Какой выводим: \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			cout << "Весь стек: " << endl;
			show(temp);
			break;
		case 4: 
			cout << "Какой чистим: \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			clear(temp);
			break;
		case 5:
			cout << "Какой стек записываем : \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			writeToFile(temp);
			break;
		case 6: 
			cout << "В какой стек заполняем : \n 1) или 2) " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: temp = Stack1;
				break;
			case 2: temp = Stack2;
				break;
			}
			readFromFile(temp);
			break;
		case 7: fillnewstack(Stack1,Stack2,Stack3);
			fillnewstack(Stack2, Stack1, Stack3);
			show(Stack3);
			break;
		case 8: return 0;
			break;
		}
	}
	return 0;
}
