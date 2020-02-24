#include <iostream>
#include <ctime>

using namespace std;

int fmaxi(int n, ...)
{
	int p = 0;
	int *ptr = &n;
	for (int i = 1; i <= n; i++) {
		ptr++;
		if (p < *ptr) p = *ptr;
	}
	return p;
}

double fmaxd(double n, ...)
{
	double p = 0;
	double *ptr = &n;
	for (int i = 1; i <= n; i++) {
		ptr++;
		if (p < *ptr) p = *ptr;
	}
	return p;
}

void main()
{
	setlocale(LC_CTYPE, "Rus");
	cout << "Максимальное число: " << fmaxi(8, -3, 57, -28, 58, 3, 101, -39, 22) << "\n";
	cout << "Максимальное число: " << fmaxi(3, 59, 105, 79) << "\n";
	cout << "Максимальное число: " << fmaxi(5, 32, 234, 283, 24, 85) << "\n\n";

	cout << "Максимальное число: " << fmaxd(8, 3.4, 4.3, 6.23, 3.45 , 34.235, 34.228, 23.34, 2.45) << "\n";
	cout << "Максимальное число: " << fmaxd(3, 59.34, 105.32, 79) << "\n";
	cout << "Максимальное число: " << fmaxd(5, 32.234, 234.45, 283.24, 24.34, 85) << "\n\n";
	system("pause");
}