#include "pch.h"
#include "Hash_ Twin_Chain.h"
#include "Lists.h"
#include <iostream>
struct AAA
{
	int key;
	char *mas;
	AAA( char*z)
	{
		mas = z;
	}
};
namespace hashTC
{
	Object create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	}
	int Object::hashFunction(void* data) //хэш функция
	{
		return (FunKey(data) % size);
	};
	bool Object::insert(void* data) // функция добавления пары в таблицу
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].deleteByData(data);
		}
		return 1;
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			std::cout << '\n';
		}
	};
}
