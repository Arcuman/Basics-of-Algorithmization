#pragma once
#define MYQUEUE1_EQE  0x0000  // ������� � ������ ������� ������� 
struct Number
{
	int info;
	Number *head;
	Number *last;
	Number *next;
};
void create(int x, Number *Queue1);
void view(Number *Queue1);
void Del(Number *Queue1);
void Count(Number *Queue1);
void Form(Number *begin, Number *Queue1, Number *Queue2);
//struct Queue               // ���� ���������� �������� 
//{
//	int Head;           // ������ �������
//	int Tail;           // ����� �������
//	int Size;           // ������ ������� (����. �����.+1)
//	void** Data;        // ��������� ������ ������� 
//	Queue(int size)     // ���������� ������ �������  
//	{
//		Head = Tail = 0;
//		Data = new void*[Size = size + 1];
//	}
//	bool isFull() const;       // ������� ��������a ?
//	bool isEmpty() const;       // ������� ����a ? 
//};
//
//Queue createQueue(int n);            // n � ����. ���������� 
//Queue createQueue(const Queue& pq);  // ������� ������� �� ������� 
//bool  enQueue(Queue& q, void* x);    // �������� x 
//void* delQueue(Queue& q);            // ������� ������� 
//void* peekQueue(const Queue& q);     // �������� ������ �������
//int clearQueue(Queue& q);            // �������� �������
//void releaseQueue(Queue& q);         // ���������� ������� 
