//Вариант 1
#include "pch.h"
#include <iostream> 
#include <fstream> 
using namespace std;
void count()
{
	ifstream F1("F1.txt", ios::in );
	ifstream F2("F2.txt", ios::in );
	F1.seekg(0, ios::end);
	F2.seekg(0, ios::end);
	int sizeofF1 = F1.tellg();
	int sizeofF2 = F2.tellg();
	cout << sizeofF1 << " " << sizeofF2 << endl;
	cout << "Количество байт F1 + F2 "<< sizeofF1 + sizeofF2 << endl;
}
void main() {
	setlocale(LC_ALL, "Russian");
	const int len = 30, strings = 8;
	const char ch = '\n';
	char mass[len];

	ifstream fs("F1.txt", ios::in);
	ofstream fw("F2.txt");
	
	if (!fs) 
		exit; //Если ошибка открытия файла, то завершаем программу
	for (int r = 0; r < strings; r++)
	{
		fs.getline(mass, len - 1, ch); //Считываем строки в массив
		cout << "String " << r + 1 << " = " << mass << endl; //Выводи строку из массива
		if (r % 2 == 1)
		fw << mass << endl;
	}
	cout << "Запись прошла успешно" << endl;
	fs.close(); //Закрываем файл
	count();


}