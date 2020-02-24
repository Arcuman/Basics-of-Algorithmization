//Вариант 8 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <Windows.h>
using namespace std;
using namespace std;
ifstream F1("F1.txt"); //Информация из файла
ofstream F2("F2.txt"); // Информация в файл 
char *temp = new char[100];// буферная строка для первого слова
char *str = new char[1024]; // буферная строка для первого слова
string stroka;
int cs = 0,max = 0;
int number_of_string; // номер проверяемой строки
int wrong_string; // номер проверяемой строки
void is_word_there() // функция проверяющая наличие слова в строке и подсчитывающая кол-во согласных в последней строке
{
	char gl[] = "AEIOUaeiou";
	stroka = str;
	cs = 0;
	for (int i = 0; i < strlen(str); i++) // Подсчет кол-ва согласных в строке
		for (int j = 0; j < strlen(gl); j++)
			if (str[i] == gl[j])
				cs++; 
	if (max < cs)
	{
		wrong_string = number_of_string;
		max = cs;
	}
}
bool is_string()
{
	if (wrong_string == number_of_string)
		return false;
	return true;
}
void input_from_file()
{
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		is_word_there();
		number_of_string++;
	}
	F1.seekg(0, ios::beg);
	number_of_string = 0;
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n');
		if (is_string())
		F2 << str << endl;
		number_of_string++;
	}
	delete str;
	cout << "программа завершилась успешно" << endl;
	cout <<"Максимальное количество гласных: "<< max << " в строке под номером: " << wrong_string + 1;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	input_from_file();
	return 0;
}