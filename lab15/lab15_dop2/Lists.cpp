#include "pch.h"
#include "Lists.h"
#include <iostream>
struct AAA        //элемент таблицы
{
	char *mas;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)
			head = new Element(NULL, data, head); // первый элемент если head null
		else
			head = (head->prev = (new Element(NULL, data, head)));
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && strcmp((((AAA*)rc->data)->mas), ((AAA*)data)->mas) )
			rc = rc->next;
		return rc;
	}
	Element* Object::search_letter(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && (((((AAA*)rc->data)->mas)[0]) != (((AAA*)data)->mas)[0]))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		listx::Element* e = this->getFirst(), *rc = this->getFirst();
		listx::Element* temp;
		while (e != NULL)
		{
			temp = e->getNext();
			deleteByElement(search_letter(data));
			e = temp;
		};
		return 1;
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), *rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();
		while (e != NULL)
		{
			std::cout << ((AAA*)e->data)->mas << " / ";
			e = e->getNext();
		};
	}
}

