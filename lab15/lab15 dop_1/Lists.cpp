#include "pch.h"
#include "Lists.h"
#include <iostream>
struct AAA        //элемент таблицы
{
	int key;
	char mas;
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
		while ((rc != NULL) && ((((AAA*)rc->data)->mas) != ((AAA*)data)->mas))
			rc = rc->next;
		return rc;
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
			std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
			e = e->getNext();
		};
	}
}

