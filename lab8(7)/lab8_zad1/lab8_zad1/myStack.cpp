#include "pch.h"
#include <iostream>
#include "myStack.h"
using namespace std;
void push(int x, Stack *myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}

int pop(Stack *myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack *e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
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
void clear(Stack *myStk)    //Clear �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (myStk->head != NULL)
	{
		e = myStk->head;
		myStk->head = myStk->head->next;
		delete e;
	}
}
void writeToFile(Stack *myStk)//������ � ����
{
	struct Stack *t = myStk->head;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;

	while (t)
	{
		fwrite(t, sizeof(struct Stack), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
void readFromFile(Stack *myStk)          //���������� �� �����
{
	struct Stack *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new Stack();
		if (!t)
		{
			cerr << "������ ��������� ������ ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Stack), 1, fp))
			break;
		push(t->data, myStk);
	}
	fclose(fp);
}
void fillnewstack(Stack *Stack1 , Stack *Stack2, Stack *Stack3)
{
	struct Stack *t1 = Stack1->head;
	struct Stack *t2 = Stack2->head;
	struct Stack *t3 = Stack3->head;
	int temp = 0;
	while(t1!=NULL) //��������� �� ���������� � 
	{
		while (t2 != NULL)
		{
			if (t1->data != t2->data)
			{
				temp++;
				t2 = t2->next;
			}
			else
			{
				temp = 0;
				break;
			}
		}
		if (temp)
		{
			push(t1->data, Stack3);
		}
		t1 = t1->next;
		t2 = Stack2->head;
	}

}