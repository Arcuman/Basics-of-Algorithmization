// lab1dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int i, c, b;

int func(int a, int count, int * arr) {
	if (!b)
	{
		while (i < count) {
			i++;
			b++;
		}
	}
	if (i <= a) {
		arr[c] = i;
		i++;
		c++;
		func(a, count, arr);
	}
	else {
		return c;
	}
}

int main(int argc, char *argv[])
{
	int a;
	cin >> a;
	int *arr = new int[a];
	int counter = 1;
	while (counter < a) 
	{ 
		counter = counter * 10;
	}
	if (counter == a);
	else
		counter = counter / 10;
	cout << "after / " << counter << endl;
	int count = func(a, counter, arr);

	for (int i = 0;i < count;i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;
	system("pause");
	return 0;

}