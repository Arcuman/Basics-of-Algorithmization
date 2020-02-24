// lab15_dop3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Hash_ Twin_Chain.h"
using namespace std;

struct AAA
{
	int key;
	AAA(int k) //конструктор с параметрами
	{
		key = k;
		
	}
	AAA()//конструктор без параметров
	{
		key = 0;
	}
};

int hf(void* d) // функция получения ключа
{
	AAA* f = (AAA*)d;
	return  f->key;
}

void AAA_print(listx::Element* e) // функция вывода ключа и значений 
{
	std::cout << ((AAA*)e->data)->key << " / ";
}
void number_from_string(char str[], hashTC::Object H) //Выделение слов для записи в таблицу
{
	char *word = new char[20]; //массив для 
	int k = 0;
	for (int i = 0; i < strlen(str) + 1; i++) //запись в УЧАСТОК ПЯМЯТИ WORD слов по очереди
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			word[k] = '\0';
			string temp = word;
			int key = atoi(temp.c_str()); //преобразование строки в цифры
			AAA *a = new AAA();
			a->key = key;
			H.insert(a);
			k = 0;
			continue;
		}
		word[k] = str[i];
		k++;
	}
}

void input_from_file(hashTC::Object H)
{
	ifstream F1("F1.txt");
	char *str = new char[1024]; // буферная строка для строки
	char *word = new char[30]; // буферная строка для слов
	F1.getline(word, 30, ' ');
	F1.seekg(0, ios::beg);// Указатель в начало файла
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		number_from_string(str, H);
	}
	delete str;
	cout << "программа завершилась успешно" << endl;
	F1.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int current_size;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;

	hashTC::Object H = hashTC::create(current_size, hf); //Создание таблицы 
	input_from_file(H);
	H.Scan();
	int k;
	AAA *c = new AAA;
	cout << "введите число " << endl;
	cin >> k;
	c->key = k;
	if (H.search(c) == NULL) //поиск элемента 
		cout << "число не найдено" << endl;
	else
	{
		cout << "Первое число " << endl;
		AAA_print(H.search(c));
		cout << endl;
	}
}