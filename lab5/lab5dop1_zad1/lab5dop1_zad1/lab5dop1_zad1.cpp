// Вариант 12
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
#include <string.h>
using namespace std;
ifstream F1("F1.txt"); //Информация из файла
ofstream F2("F2.txt"); // Информация в файл 
char *word = new char[30]; // буферная строка для первого слова
char *temp = new char[30];// буферная строка для первого слова
char *str = new char[1024]; // буферная строка для первого слова
string stroka;
int cs = 0;

bool is_word_there() // функция проверяющая наличие слова в строке и подсчитывающая кол-во согласных в последней строке
{
	char sog[] = "bcdfghjklmnpqyrstvwxzBCDFGHJKLMNPQRSTVWXYZ";
	stroka = str;
	int pos = stroka.find(word); // проверка на наличия слова, find-возвращает -1 если нет слова и позицию слова если оно есть
	if(pos == -1)
	return false;
	else
	{
		cs = 0; 
		for (int i = 0; i < strlen(str); i++) // Подсчет кол-ва согласных в строке
			for (int j = 0; j < strlen(sog); j++)
				if (str[i] == sog[j])
					cs++;
		return true;
	}
}
void input_from_file()
{
	F1.getline(word, 30, ' '); //запись первого слова из файла
	F1.seekg(0, ios::beg);// Указатель в начало файла
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		if(is_word_there())
		F2 << str << endl; //Запись строки в F2
	}
	delete str;
	cout << "программа завершилась успешно" << endl;
	cout << cs;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	input_from_file();
	return 0;
}

