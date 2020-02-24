#include "pch.h"
#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
	std::cout << x;
}
bool AAA::compare()
{
	return (x > 0) ? true : false;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x; //чтобы не писать отельно size++
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax(int i)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[i];
			storage[i] = storage[size - 1];
			size--;
			heapify(i);
		} return rc;
	}

	void Heap::check_positive()
	{
		int positive = 0;
		for (int u = 0, y = 0; u < size; u++)
		{
			if (((AAA*)storage[u])->compare())
			{
				positive++;
			}
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}

		}
		std::cout << "Number of positive elements: " << positive << std::endl;
	}

	void Heap::check_negative()
	{
		int negative = 0;
		for (int u = 0, y = 0; u < size; u++)
		{
			if (!(((AAA*)storage[u])->compare()))
			{
				negative++;
			}
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}

		}
		std::cout << "Number of negative elements: " << negative << std::endl;
	}
		
	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	void Heap::merge(Heap* b)
	{
		for (int i = 0; i < b->size ; i++)
		{
			size++;
			storage[size - 1] = b->storage[i];
			heapify(i);
		}
	}
	int Heap::Height()
	{
		int y = 0;
		for (int u = size; u > 0; y++)
			u = parent(u);
		return y - 1;
	}
	void* Heap::extractMin(int height)
	{
		void* min = storage[0];
		int mini = 0;
		// Закоменченное ниже можно использовать для ускорнеия работы(удаления элемента)
		//if (size == (pow(2, height + 1) - 1)) //удаление элементов при возможном расположении минимальных элементов только на одном ПОСЛЕДНИМ уровни дерева
		//{ 
		//	for(int i = (pow(2, height - 1) + 1) ; i < size ;i++)
		//		if (isGreat(min, storage[i]))
		//		{
		//			min = storage[i];
		//			mini = i;
		//		}
		//	std::cout << min << std::endl;
		//	storage[mini] = storage[size - 1];
		//	size--;
		//	heapify(parent(mini));
		//}
		//else
		//{
			for (int i = (pow(2, height - 1) + 1); i < size; i++) // проверка потомков и родителей
				if (isGreat(min, storage[i]))
				{
					min = storage[i];
					mini = i;
				}
			for (int i = (pow(2, height - 2) + 1); i < (pow(2, height - 1) + 1); i++)
				if (isGreat(min, storage[i]))
				{
					min = storage[i];
					mini = i;
				}
			std::cout << min << std::endl;
			storage[mini] = storage[size - 1];
			size--;
			heapify(parent(mini));
		/*}*/
			return min;
	}
}
