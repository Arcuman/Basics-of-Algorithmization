// lab9_dop3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Queue
{
	char data[255];   //массив данных
	int head;         //указатель на начало
};

void creatQueue(Queue *Q)   //Создание очереди Q
{
	Q->head = NULL;
}

bool isFull(Queue *Q)       //Проверка очереди на пустоту
{
	if (!Q->head)
		return true;
	else
		return false;
}
void showQueue(Queue *Q) {
	ofstream fout("B.txt", ios_base::app);
	for (int i = 0; i < Q->head; i++)
	{
		fout << Q->data[i];

	}
	Q->head = 0;
	fout.close();
}
void addToQueue(Queue *Q, char value)     //Добавление элемента
{
	Q->data[Q->head++] = value;
}


ifstream fin("A.txt");
int main()
{
	ofstream fout("B.txt", ios_base::trunc);
	fout.close();
	setlocale(LC_ALL, "Rus");
	Queue Q1, Q2;
	creatQueue(&Q1);
	creatQueue(&Q2);
	while (!fin.eof()) {
		char s[255] = "";
		fin.getline(s, 253);
		for (int i = 0; i < strlen(s); i++)
		{
			if ((s[i] != '0') && (s[i] != '1') && (s[i] != '2') && (s[i] != '3') && (s[i] != '4') && (s[i] != '5') && (s[i] != '6') && (s[i] != '7') && (s[i] != '8') && (s[i] != '9')) { addToQueue(&Q1, s[i]); }
			else addToQueue(&Q2, s[i]);
		}

		showQueue(&Q1);
		showQueue(&Q2);
		ofstream fout("B.txt", ios_base::app);
		fout << endl;
		fout.close();
	}

	system("pause");
	return 0;
	cout << "DONE!" << endl;
}
