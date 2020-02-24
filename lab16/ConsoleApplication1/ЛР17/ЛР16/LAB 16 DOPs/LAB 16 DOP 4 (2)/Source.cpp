#include <iostream>
#include <ctime>

using namespace std;

int kvadr(int n, ...)
{
	int r = 0, *p = &n;
	for (int i = 0; i < n; i++)	{
		++p;
		int ch = 0;
		ch = pow(*p, 0.5);
		if (pow(ch, 2) == *p) r++;
	}
	return r;
}

void main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Rus");
	cout << "Количество точных квадратов: " << kvadr(6, 1, 4, 3, 16, 8, 9) << "\n\n";
	cout << "Количество точных квадратов: " << kvadr(7, 121, 6, 7, 15, 169, 3, 9) << "\n\n";
	cout << "Количество точных квадратов: " << kvadr(5, 2, 11, 32, 36, 81) << "\n\n";
	system("pause");
}