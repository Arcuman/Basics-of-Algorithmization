// lab14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char *mas;
	AAA(int k, char*z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;  
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	AAA *a0 = new  AAA{ 0, (char*)"zero" };
	AAA *a1 = new  AAA { 1, (char*)"one" };
	AAA *a12 = new  AAA{ 1, (char*)"one2" };
	AAA *a13 = new  AAA{ 1, (char*)"one3" };
	AAA *a2 = new  AAA{ 2, (char*)"two" };
	AAA *a3 = new  AAA{ 3, (char*)"three" };
	AAA *a4 = new  AAA{ 4, (char*)"four" };
	AAA *a42 = new  AAA{ 4, (char*)"four2" };
	AAA *a5 = new  AAA{ 5, (char*)"five" };
	AAA *a6 = new  AAA{ 6, (char*)"six" };
	AAA *a62 = new  AAA{ 6, (char*)"six2" };
	AAA *a7 = new  AAA{ 7, (char*)"seven" };
	AAA *a8 = new  AAA{ 8, (char*)"eight" };
	AAA *a71 = new  AAA{ 7, (char*)"seven1" };
	AAA *a72 = new  AAA{ 7, (char*)"seven2" };
	AAA *a73 = new  AAA{ 7, (char*)"seven3" };
	AAA *a81 = new  AAA{ 8, (char*)"eight2" };
	int siz = 16, choice, k;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	Object H = create(siz, key);
	H.insert(a0);
	H.insert(a1);
	H.insert(a12);
	H.insert(a13);
	H.insert(a2);
	H.insert(a3);
	H.insert(a4);
	H.insert(a42);
	H.insert(a5);
	H.insert(a6);
	H.insert(a62);
	H.insert(a7);
	H.insert(a8);
	H.insert(a71);
	H.insert(a81);
	H.insert(a72);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  
			
			break;
		case 2: { AAA *a = new AAA;
			char *str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			cout << H.N << " " <<  H.size <<endl;
			if ((double)H.N > ((double)(H.size) * 0.5F)) // 12 вариант // if ((double)H.N > (double)(H.size) * 0.7) ----- 14 вариант
			{
				cout << "Таблица заполнена на 50%(50% = " << ((double)(H.size) * 0.5)  << " количество элементов в таблице " << H.N <<") Расширяется в 2 раза" << endl;
				Object H1 = create(H.size*2, key); //	Object H1 = create(H.size*3, key); ------ 14 вариант
				for (int i = 0; i < H.size; i++)
				{
					H1.data[i] = H.data[i];
				}
				H1.N = H.N;
				H1.insert(a);
				H = H1;
			}
			else
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		}
	}
	return 0;
}
