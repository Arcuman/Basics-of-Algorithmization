
#pragma once
struct Stack
{
	int data;             //�������������� �������
	Stack *head;		 //������� ����� 
	Stack *next;		 //��������� �� ��������� �������
};

void show(Stack *myStk);         //��������
void push(int x, Stack *myStk);  //��������
void readFromFile(Stack *myStk); //��������
