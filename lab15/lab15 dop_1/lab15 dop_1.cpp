// lab15 dop_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Hash_ Twin_Chain.h"
#include <string>

using namespace std;
void fill_hash(string  str, hashTC::Object H); //Заполнение таблицы
unsigned char rand8[256];
int getHashSize(string str ); // Подсчет количества различных букв (размера таблицы)
struct AAA
{
	int letter_count;
	char letter;
	AAA(int Letter_count, char Letter) //конструктор с параметрами
	{
		letter_count = Letter_count;
		letter = Letter;
	}
	AAA()//конструктор без параметров
	{
		letter_count = 0;
		letter = (char)"";
	}
};

int hf1(void* d) // функция получения ключа (hash функция)
{
	AAA* f = (AAA*)d;
	return f->letter;
}
void AAA_print(listx::Element* e) // функция вывода ключа и значений 
{
	std::cout << ((AAA*)e->data)->letter_count << '-' << ((AAA*)e->data)->letter << " / ";
}
int main()
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 256; i++) // Переменная для хеш функции
		rand8[i] = rand() % 255;

	string str; //строка для ввода
	cout << "Enter the string" << endl;
	getline(cin, str); 
	cout << str; //Вывод строки
	int size = getHashSize(str);
	printf("Количество неповторяющихся символов в строке => %d\n", size);
	hashTC::Object H = hashTC::create(size, hf1); //Создание таблицы 
	fill_hash(str, H); //Заполнение таблицы
	H.Scan();
	char k;
	AAA *c = new AAA;
	cout << "введите букву" << endl;
	cin >> k;
	c->letter = k;
	if (H.search(c) == NULL) //поиск элемента 
		cout << "Буква не найдена" << endl;
	else
	{
		cout << "Буква в таблице" << endl;
		AAA_print(H.search(c));
		cout << endl;
	}
	return 0;
}

void fill_hash( string str , hashTC::Object H)
{
	
	int count = 0;
	char n;
	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n' || str[i] == '\0')
			break;
		if (str[i] == ' ')
			continue;
		n = str[i];
		count++;
		str[i] = ' ';
		for (j = i + 1;j<str.length();j++)
		{
			if (n == str[j])
			{
				str[j] = ' ';
				count++;
			}
		}AAA *a = new AAA();
		cout << n << " " << count;
		a->letter = n ;
		a->letter_count = count;
		H.insert(a);
		count = 0;
	}
	cout << endl;
	
}

int getHashSize(string str) // Подсчет количества различных букв (размера таблицы)
{
	int count = 0;
	int j;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n' || str[i] == '\0') /* если встречается символ переноса или конец строки - выходим из цикла */
			break;
		for (j = i - 1; j >= 0; j--)
		{
			if ((str[i] == str[j]) || str[i] == ' ')
				break;
		}
		if (j == -1) /* если j стал ниже нуля, значит символ не встречался раньше, увеличиваем счетчик */
			count++;
	}

	return count;
}

