// Вариант 9
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
#include <string.h>
using namespace std;

int N1, N2; // Диапазон 
char *str = new char[1024]; // буферная строка
int k;
void number_of_words() // функция подсчитывающая количество слов
{
	ifstream F2("F2.txt");
	F2.getline(str, 1024, '\n'); //запись строки из файла
	int count = 0;
	cout << str << endl;
	for (int i = 0; i <= strlen(str); i++) {
		if ((str[i] == ' ' || str[i] == '\n')) {
			count++;
		}
	}
	if (k==1)
	count++;
	cout <<"Количество слов в первой строке: "<<count << endl;
}
void input_from_file()
{
	ifstream F1("F1.txt"); //Информация из файла
	ofstream F2("F2.txt"); // Информация в файл
	cout << "Enter N1" << endl;
	cin >> N1;
	cout << "Enter N2" << endl;
	cin >> N2;
	int i = 1; //номер строки
	while (!F1.eof())
	{
		F1.getline(str, 1024, '\n'); //запись строки из файла
		if (i >= N1 && i <=N2)
		{
			if (str[0] == 'A' || str[0] == 'a')//проверка условия что строка начинается с буквы А
			{
				F2 << str << endl; //Запись строки в F2
				k = 1;
			}
		}
		i++;
	}
	F1.close();
	F2.close();
	number_of_words();
	delete str;
}
//F1.getline(str, 1024, '\n'); //запись строки из файла
//if (i == 1) // если это первая строка
//{
//	
//}
int main()
{
	setlocale(LC_ALL, "Russian");
	input_from_file();
	return 0;
}

