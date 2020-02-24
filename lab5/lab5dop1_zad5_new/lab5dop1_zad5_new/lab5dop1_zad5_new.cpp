#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
#include <string.h>
using namespace std;

int K1, K2; // Диапазон 
char *str = new char[1024]; // буферная строка
int k;
string stroka;
int cs;
void is_word_there() // функция проверяющая наличие слова в строке и подсчитывающая кол-во согласных в последней строке
{

	ifstream F2("F2.txt");
	char gl[] = "AEIOUaeiou";
	stroka = str;
	cs = 0;
	while (!F2.eof())
	{
		F2.getline(str, 1024, '\n'); //запись строки из файла
		for (int i = 0; i < strlen(str); i++) // Подсчет кол-ва согласных в строке
			for (int j = 0; j < strlen(gl); j++)
				if (str[i] == gl[j])
					cs++;
	}
	F2.close();
	cout << cs << endl;
}
void input_from_file()
{
	ifstream F1("F1.txt"); //Информация из файла
	ofstream F2("F2.txt"); // Информация в файл
	cout << "Enter K" << endl;
	cin >> K1;
	K2 = K1 + 5;
	int i = 1; //номер строки
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n'); //запись строки из файла
		if (i >= K1 && i <= K2)
		{
				F2 << str << endl; //Запись строки в F2
		}
		i++;
	}
	F1.close();
	F2.close();
	is_word_there();
	delete str;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	input_from_file();
	return 0;
}
