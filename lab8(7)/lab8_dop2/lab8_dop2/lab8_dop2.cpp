// lab8_zad1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack *Stack3 = new Stack; //выделение памяти для стека
	Stack *temp = NULL;
	Stack3->head = NULL;       //инициализация первого элемента	
	readFromFile(Stack3);
	
}
