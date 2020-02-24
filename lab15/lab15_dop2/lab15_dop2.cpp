// lab15_dop2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "Hash_ Twin_Chain.h"
using namespace std;

struct AAA
{
	char *mas;
	AAA( char*z) //конструктор с параметрами
	{
		mas = z;
	}
	AAA()//конструктор без параметров
	{
		mas = (char*)"";
	}
};

int hf(void* d) // функция получения ключа
{

	AAA* f = (AAA*)d;
	int sum = 0;
	for (int k = 0; k < strlen(f->mas); k++)
		sum = sum + int(f->mas[k]);
	return  sum;
}

void AAA_print(listx::Element* e) // функция вывода ключа и значений 
{
	std::cout << ((AAA*)e->data)->mas << " / ";
}

void word_from_string(char str[], hashTC::Object H) //Выделение слов для записи в таблицу
{
	char *word = new char[20]; //массив для 
	int k = 0;
	for (int i = 0; i < strlen(str) + 1; i++) //запись в УЧАСТОК ПЯМЯТИ WORD слов по очереди
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			char *temp = new char[20]; //выделение памяти для каждого слова
			word[k] = '\0'; //обозначение конца строки
			for (int j = 0; j < strlen(word) + 1; j++) //запись нового слова в его УЧАСТОК ПЯМЯТИ
			{
				temp[j] = word[j];
			}
			AAA *a = new AAA();
			a->mas = temp;
			H.insert(a);
			k = 0;
			continue;
		}
		word[k] = str[i];
		k++;
	}
}

int CountWordSize() //подсчет количества слов
{
	ifstream F1("F1.txt");
	char symbol;
	int ColWord = 0;
	while (!F1.eof())
	{
		symbol = F1.get();
		if ((symbol == '\n') || (symbol == ' ') || (symbol == '\t'))
			ColWord++;
	}
	cout << "Количество слов в файле: "<<ColWord + 1 << endl;
	
	F1.close();
	return ColWord + 1;
}

void input_from_file(hashTC::Object H)
{
	ifstream F1("F1.txt");
	char *str = new char[1024]; // буферная строка для строки
	char *word = new char[30]; // буферная строка для слов
	F1.getline(word, 30, ' ');
	CountWordSize();
	F1.seekg(0, ios::beg);// Указатель в начало файла
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		word_from_string(str,H);
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
	AAA *c = new AAA;
	char k[20];
	cout << "введите слово " << endl;
	cin >> k;
	c->mas = k;
	if (H.search(c) == NULL) //поиск элемента 
		cout << "слово не найдено" << endl;
	else
	{
		cout << "Первое слово " << endl;
		AAA_print(H.search(c));
		cout << endl;
	}
	char  letter[2];
	AAA *b = new AAA;
	cout << "введите букву" << endl;
	cin >> letter;
	b->mas = letter;
	H.deleteByData(b); // функция удаления 
	cout << "Слова начинающиеся на " << letter  << " удалены" << endl;
	H.Scan();
}
