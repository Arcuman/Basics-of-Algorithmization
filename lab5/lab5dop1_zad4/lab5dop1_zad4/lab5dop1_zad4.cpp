// Вариант 4
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
#include <string.h>
using namespace std;

char *str = new char[1024]; // буферная строка
string stroka;
int cs;
bool number_of_words() // функция подсчитывающая количество слов
{
	char gl[] = "1234567890";
	stroka = str;
	cs = 0;
	for (int i = 0; i < strlen(str); i++) // Подсчет кол-ва согласных в строке
		for (int j = 0; j < strlen(gl); j++)
			if (str[i] == gl[j])
				cs++;
	if (cs)
		return false;
	return true;
}
void count()
{
	ifstream F2("F2.txt");
	int i = 0; //номер строки
	while (!F2.eof())
	{
		F2.getline(str, 1024, '\n'); //запись строки из файла
		if (str[0] == 'A' || str[0] == 'a')//проверка условия что строка начинается с буквы А
			i++;
	}
	cout << "Количество строк начинающихся с А " << i << endl;
}
void input_from_file()
{
	ifstream F1("F1.txt"); //Информация из файла
	ofstream F2("F2.txt"); // Информация в файл
	
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n'); //запись строки из файла
		if(number_of_words())
		F2 << str << endl; //Запись строки в F2
	}
	F2.close();
	count();
	delete str;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	input_from_file();
	return 0;
}

