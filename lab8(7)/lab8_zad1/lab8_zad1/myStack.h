#pragma once
struct Stack
{
	int data;             //информационный элемент
	Stack *head;		 //вершина стека 
	Stack *next;		 //указатель на следующий элемент
};

void show(Stack *myStk);         //прототип
void clear(Stack *myStk);         //прототип
int pop(Stack *myStk);           //прототип
void push(int x, Stack *myStk);  //прототип
void writeToFile(Stack *myStk); //прототип
void readFromFile(Stack *myStk); //прототип
void fillnewstack(Stack *Stack1, Stack *Stack2, Stack *Stack3); //прототип