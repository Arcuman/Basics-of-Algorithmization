// lab12_dop3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//СВОЙСТВА КРАСНО-ЧЕРНЫХ ДЕРЕВЬЕВ
//1) Каждый узел окрашен либо в красный, либо в черный цвет(в структуре данных узла появляется дополнительное поле – бит цвета).
//
//2) Корень окрашен в черный цвет.
//
//3) Листья(так называемые NULL - узлы) окрашены в черный цвет.
//
//4) Каждый красный узел должен иметь два черных дочерних узла.Нужно отметить, что у черного узла могут быть черные дочерние узлы.Красные узлы в качестве дочерних могут иметь только черные.
//
//5) Пути от узла к его листьям должны содержать одинаковое количество черных узлов(это черная высота).
#include "pch.h"
#include <iostream>
#include <string>

#define black 0
#define red 1

using namespace std;

struct Tri //структура элемента дерева
{
	int val;
	bool color;
	Tri* left;
	Tri* right;
	Tri* parent;
	
}*head;

int add_k = 0;

void create(int); //Создание дерева
void add(int); //Функция добавления элементов в дерево
void output(); //Вывод дерева

void check_1(Tri*);
void check_2(Tri*);
void check_3(Tri*);
void check_4(Tri*);
void check_5(Tri*);
void rotate_right(Tri*);
void rotate_left(Tri*);

Tri* Ded(Tri*);
Tri* uncle(Tri*);

int main()
{
	create(10);
	add(1);
	add(5);
	add(7);
	add(12);
	add(11);
	output();
	Tri* iu = head;
	system("pause");
	return 0;
}
void create(int data) //Создание дерева (корень черного цвета)
{
	add_k++;
	head = new Tri;
	head->val = data;

	head->left = new Tri; //Левый лист черный
	head->left->val = NULL;
	head->left->left = NULL;
	head->left->right = NULL;
	head->left->color = black;

	head->right = new Tri; //Правый лист черный 
	head->right->val = NULL;
	head->right->left = NULL;
	head->right->right = NULL;
	head->right->color = black;

	head->color = 0; //

	head->parent = NULL;
}
void add(int data) // Добавление элементов 
{
	add_k++;
	Tri* kul = head;
	Tri* buff = NULL;
	while (kul->val != NULL) //Добавление как в бинароном делеве
	{
		buff = kul;
		if (data > buff->val)
		{
			kul = kul->right;
		}
		else
		{
			kul = kul->left;
		}
	}

	kul->val = data;

	kul->left = new Tri;  //Левый черный лист
	kul->left->val = NULL;
	kul->left->left = NULL;
	kul->left->right = NULL;
	kul->left->color = black;

	kul->right = new Tri;//Правый черный лист
	kul->right->val = NULL;
	kul->right->left = NULL;
	kul->right->right = NULL;
	kul->right->color = black;

	kul->color = red; // Цвет вершины

	kul->parent = buff; 

	if (data < buff->val) // Проверка на какую ветку добавить 
	{
		buff->left = kul;
	}
	else
	{
		buff->right = kul;
	}
	check_1(kul);
}
Tri* Ded(Tri* n) //Проверка на существование элементов 2 колена 
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}
Tri* uncle(Tri* n)
{
	Tri* g = Ded(n);
	if (g == NULL)
		return NULL;
	if (n->parent == g->left) //Проверка на 
		return g->right;
	else
		return g->left;
}
void check_1(Tri *n) // Если это первый элемент (head) то цвет черный 
{
	if (n->parent == NULL)
		n->color = black;
	else
		check_2(n);
}
void check_2(Tri* n)  //Проверка родителя на цвет
{
	if (n->parent->color == black) //если черный возвращаемся и оставляем его красным 
		return;
	else
		check_3(n);
}
void check_3(Tri* n) //Проверка на колчество шагов от вершины до листа 
{
	Tri* u = uncle(n), *g;
	if ((u != NULL) && (u->color == red)) {

		n->parent->color = black;
		u->color = black;
		g = Ded(n);
		g->color = red;
		check_1(g);
	}
	else {
		check_4(n);
	}
}
void check_4(Tri* n)
{
	Tri* g = Ded(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n->parent);
		n = n->right;
	}
	check_5(n);
}
void check_5(Tri* n)
{
	Tri* g = Ded(n);

	n->parent->color = black;
	g->color = red;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(g);
	}
	else {
		rotate_left(g);
	}
}
void rotate_left(Tri* n)
{
	Tri* pivot = n->right;
	pivot->parent = n->parent;
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

void rotate_right(Tri* n)
{
	Tri* pivot = n->left;

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}

char get_color(bool x)
{
	return (x == true ? 'r' : 'b');
}

void print_Tree(Tri * p, int level) //вывод дерева
{
	if (p)
	{
		print_Tree(p->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->val << get_color(p->color) << endl;
		print_Tree(p->right, level + 1);
	}
}
void output() // Вывод дерева
{
	Tri * temp = new Tri; 
	temp = head;
	while (temp->parent != NULL) //Ищем head
		temp = temp->parent;
	print_Tree(temp,0);
}