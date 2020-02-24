#include "pch.h"
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;
void push(int x, Stack *myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}


void show(Stack *myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void readFromFile(Stack *myStk)          //���������� �� �����
{
	int min = 1024, i= 1 , counter = 0; 
	struct Stack *t;
	char *str = new char[1024];
	ifstream F1("F1.txt"); //���������� �� �����
	cout << "�������� �� �����" << endl;
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
	cout << endl << "��������� ����� �������� ������ ��� �������: " << counter << " ����� ������ = " << min << endl;
}