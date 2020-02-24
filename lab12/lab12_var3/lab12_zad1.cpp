// lab12_zad1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Tree.h"
#include <fstream>
using namespace std;
int countK;
struct NodeTree
{
	int  key;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key < ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT;
	return rc;
}
bool IsKeyEqualK(void * x, int y)
{
	if (((NodeTree*)x)->key == (int)y)
	{
		countK++;
		return true;
	}
	else
		return false;
}
//-------------------------------
void printNode(void* x)               // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << ends;
}
//-------------------------------
bool buildTree(const char *FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE *inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // заполнение дерева 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree *a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}
FILE * outFile;
//-------------------------------
void saveToFile(void *x)              // Запись одного элемента в файл
{
	NodeTree *a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}
//-------------------------------
void saveTree(btree::Object &tree, const char *FileName)    //Сохранение дерева в файл 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown1(saveToFile);
	fclose(outFile);
}
//-------------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object demoTree = btree::create(cmpfnc);
	int k, choice;
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 }, a9 = { 9 }, a8 = { 8 }, a7 = { 7 }, a10 = { 10 }, a11 = { 11 }, a12 = { 12 }, a13 = { 13 };;
	bool rc = demoTree.insert(&a6);   //           4  
	rc = demoTree.insert(&a4);        //   1           
	rc = demoTree.insert(&a9);        //                   6
	rc = demoTree.insert(&a3);        //      2       
	rc = demoTree.insert(&a2);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	rc = demoTree.insert(&a8);        //      
	rc = demoTree.insert(&a7);        //  
	rc = demoTree.insert(&a10);        // 
	rc = demoTree.insert(&a11);        //  
	rc = demoTree.insert(&a12);        //  
	rc = demoTree.insert(&a13);        //  
	cout << demoTree.Root->Height() << endl;
	//NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 };
	//bool rc = demoTree.insert(&a4);   //           4  
	//rc = demoTree.insert(&a1);        //   1           
	//rc = demoTree.insert(&a6);        //                   6
	//rc = demoTree.insert(&a2);        //      2       
	//rc = demoTree.insert(&a3);        //         3
	//rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree *a = new NodeTree;
		cout << "1 - вывод дерева на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - сохранить в файл" << endl;
		cout << "5 - загрузить из файла" << endl;
		cout << "6 - очистить дерево" << endl;
		cout << "7 - проверка сбалансированности дерева " << endl;
		cout << "8 - количество вершин с k " << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  	if (demoTree.Root)
			demoTree.Root->scanByLevel(printNode);
					else
			cout << "Дерево пустое" << endl;
			break;
		case 2: 	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, "G.txt");
			break;
		case 5:  	buildTree("G.txt", demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		case 7:
			if (demoTree.Root->AVLtree() != 0)
				cout << "Дерево сбалансировано" << endl;
			else
				cout << "Дерево не сбалансировано" << endl;
			break;
		case 8:
			int k,temp;
			cout << "\nВведите цифру k: "; cin >> k;

			cout << "Количество вершин: " << demoTree.Root->CountTopK(IsKeyEqualK, k) << " со значение k: ";
			cout<< countK << endl;
			break;
		}
	}
	return 0;
}
