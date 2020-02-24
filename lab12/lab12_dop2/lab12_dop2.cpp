#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
struct Tri
{
	int value;
	Tri* left;
	Tri* right;
};

int* create();
Tri* makeTree(Tri *Root, int key);
Tri* list(int i);
Tri* insertElem(Tri *t, int key);
void view(Tri *t, int level);
int N;
int main()
{
	setlocale(LC_ALL, "rus");
	int* delta = create();
	Tri* Root = new Tri;
	Root = makeTree(Root,delta[0]);
	for (int i=1;i<N;i++)
	{
		insertElem(Root,delta[i]);
	}
	view(Root,0);
	system("pause");
	return 0;
}
int* create()
{
	cout << "Введите количество элементов: "; cin >> N;
	int* mass = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите новый элемент массива: "; cin >> mass[i];
	}
	std::sort(mass, mass + N);
	for (int i = 1; i < N; i += 2)
	{
		int t = mass[i - 1];
		mass[i - 1] = mass[i];
		mass[i] = t;
	}
	for (int i = 0; i < N; i++)
	{
		cout << "Эдементы массива: ";cout << mass[i]<<endl;
	}
	return mass;
}
Tri* list(int i)     //Создание нового элемента
{
	Tri *t = new Tri[sizeof(Tri)];
	t->value = i;
	t->left = t->right = NULL;
	return t;
}
Tri* makeTree(Tri *Root,int key)    //Создание дерева
{
	Root = list(key);	// установка указателя на корень
	return Root;
}
Tri* insertElem(Tri *t, int key)  //Добавление нового элемента
{
	Tri *Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->value)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->value) t = t->left;
			else t = t->right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key);           //создается новый узел 
		if (key < Prev->value)  // и присоединяется либо 
			Prev->left = t;    //переход на левую ветвь,
		else
			Prev->right = t;   // либо на правую 
	}
	return t;
}

void view(Tri *t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->value;
		cout << tm << endl;
		view(t->left, level + 1);	//вывод левого поддерева
	}
}
