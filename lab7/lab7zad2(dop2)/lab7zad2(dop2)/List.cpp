#include "pch.h"

bool Object::Insert(void* data)           // ������� � ������
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
void Object::SortPositive(int(*f)(void*))//���������� ������������� ��������� �� ������������
{
	Element* rc = Head; //��������� �� 1 ���� ������ � ������
	Element* p = rc->Next;
	Element *temp = new Element(NULL,NULL,NULL) ;
	while (rc != NULL)
	{
		int check = f(rc->Data);//����� �������� �������� 
		if (check > 0)//���� �� ������������� ��������� ��� � ���������� 
		{
			p = rc->Next;
			while (rc != NULL && p != NULL)//���� ��� ������������� ������� � ������
			{
				int check2 = f(p->Data); //����� �������� �������� 
				if (check2 > 0) //��������� �� ���������������
				{
					if (check>check2)//�������� ����� �� ��������� ������ ���� ������ ������ ���������� ������ , ����� ������ �������
					{
						temp->Data = (*rc).Data; //����� �� �������� ��������� ������ �� ���� � ���� ������� ������� �� �� ��������� ����������
						rc->Data = (*p).Data; // ������ ������� 
						p->Data = (*temp).Data;
						check = f(rc->Data);
						continue;
					}
					else
					{
						p = p->Next;
					}
				}
				else
				{
					p = p->Next;
				}
			}
			rc = rc->Next;
		}
		else
		{
			rc = rc->Next;
		}
	}
	delete temp;
}
void Object::SortEven(int(*f)(void*))//���������� ������������� ��������� �� ������������
{
	Element* rc = Head->Next; //��������� �� 1 ���� ������ � ������
	Element* p = (rc->Next)->Next;
	Element *temp = new Element(NULL, NULL, NULL);
	int check = 1;
	while (rc != NULL && p != NULL)
	{
		p = (rc->Next)->Next;
		int check = f(rc->Data);//����� �������� �������� 
		if(check % 2 == 0)
		{
		while (rc != NULL && p != NULL)
		{
			int check2 = f(p->Data); //����� �������� ��������
			if (check > check2)//�������� ����� �� ��������� ������ ���� ������ ������ ���������� ������ , ����� ������ �������
			{
				temp->Data = (*rc).Data; //����� �� �������� ��������� ������ �� ���� � ���� ������� ������� �� �� ��������� ����������
				rc->Data = (*p).Data; // ������ ������� 
				p->Data = (*temp).Data;
				break;
			}
			else 
			{
				p = (p->Next)->Next;
			}
		}
		}
		rc = (rc->Next)->Next;
	}
	delete temp;
}
//-----------------------------------------------------------
Element* Object::Search(void* data)    // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*))     // �����
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element *e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // ������� �� ������
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}

//-----------------------------------------------------------
bool Object::Delete(void* data)      // ������� �� ��������
{
	return Delete(Search(data));
};

bool Object::InsertEnd(void* data)
{
	Element* e = GetLast();
	e->Next = new Element(e, data, NULL);
	return true;
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, *rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	};
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}
