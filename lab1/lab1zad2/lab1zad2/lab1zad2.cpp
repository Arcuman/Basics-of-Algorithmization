#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;


float calc(int n, int x)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 2 * x;
	else
		return ((((2 * n) / (n - 1))*calc(n - 1, x)) + ((n - 1) / 2 * n)*calc(n - 2, x));
}

int main()
{
	int n;
	int x;
	cout << "n: ";
	cin >> n;
	cout << "x: ";
	cin >> x;
	cout << calc(n, x) << endl;
	system("pause");
}
