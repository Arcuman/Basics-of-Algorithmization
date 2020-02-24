#pragma once
struct Stack
{
	int data;             //�������������� �������
	Stack *head;		 //������� ����� 
	Stack *next;		 //��������� �� ��������� �������
};

void show(Stack *myStk);         //��������
void clear(Stack *myStk);         //��������
int pop(Stack *myStk);           //��������
void push(int x, Stack *myStk);  //��������
void writeToFile(Stack *myStk); //��������
void readFromFile(Stack *myStk); //��������
void fillnewstack(Stack *Stack1, Stack *Stack2, Stack *Stack3); //��������