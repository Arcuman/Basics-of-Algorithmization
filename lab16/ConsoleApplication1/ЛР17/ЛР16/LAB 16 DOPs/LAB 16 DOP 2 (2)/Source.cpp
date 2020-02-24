#include <iostream>
#include <ctime>

using namespace std;

int fsum(int n, ...)
{
	int S = 0, *p = &n, pol = 0, nepol = 0, ch = 0;
	pol = n / 2;
	nepol = n - (pol * 2);
	for (int i = 1; i <= pol; i++) {
		ch = 0;
		ch = ch + (*(++p));
		ch = ch * (*(++p));
		S = S + ch;
	}
	if (nepol == 1) S = S + (*(++p));
	return S;
}

void main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Rus");
	cout << "Сумма по формуле: " << fsum(4, 2, 2, 3, 4) << "\n\n";
	cout << "Сумма по формуле: " << fsum(7, 1, 2, 6, 1, 2, 3, 9) << "\n\n";
	cout << "Сумма по формуле: " << fsum(5, 2, 2, 2, 2, 2) << "\n\n";
	system("pause");
}