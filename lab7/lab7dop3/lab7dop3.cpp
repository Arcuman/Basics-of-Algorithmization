// lab7dop3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;
struct Node {
	int data;
	Node *next;
};
Node *INSERT(Node *heder, Node *current) {
	if (current == heder)
	{
		return current->next;
	}
	else
	{
		Node *p = heder;	//указатель на первый элемент
		Node *prev = current;	//вставляем после этого элемента
		Node *pp;//здесь храним указатель на элемент, перед
			//которым вставляем (т.е. следующий после текущего)
		//пока не переберем все элементы списка до текущего
		while (p != current)
		{
			pp = prev->next;//сохраняем указатель на элемент, после которого нужно вставить
			prev->next = new Node;//создаем новый элемент
			prev = prev->next;//теперь работаем с ним
			prev->data = p->data;//запись данных
			prev->next = pp;//запись указателя на следующий элемент
			p = p->next;//переходим к следующему элементу
		}
		return prev->next;
	}
}
int main()
{
	int n;
	cin >> n;
	Node *head, *last;
	head = new Node;
	//вот здесь мы создали первый элемент списка
	//и должны заполнить поле data
	head->data = 1;
	last = head;
	int k = 2;//так как первый элемент списка уже =1, то следующий =2
	//в цикле создаем и заполняем элементы списка
	while (n - 1> 0) {
		last->next = new Node;
		last = last->next;
		last->data = k;
		last->next = NULL;
		k++;
		n--;
	}
	for (Node *current = head; current != NULL;	current = current->next) {
		cout << current->data << endl;
	}
	for (Node *uk = head; uk != NULL;) {
		uk = INSERT(head, uk);
	}
	for (Node *uk = head; uk != NULL;) {
		cout << uk->data << " ";
		uk = uk->next;
	}
	cout << endl;
	system("pause");
	return 0;
}