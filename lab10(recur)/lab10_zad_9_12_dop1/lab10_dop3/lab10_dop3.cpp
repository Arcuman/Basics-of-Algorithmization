#include "pch.h"
#include <iostream>
using namespace std;
const int n = 5;
int a[n];

void perm(int k) {
	int i, j, t, p;
	for (i = 0; i < n - k; i++) {
		if (k < n - 2)
			perm(k + 1); // рекурсивный вызов
		else { // печать готовой перестановки
			for (p = 0; p < n; p++) cout << " " << a[p];
			cout << endl;
		}
		// циклический сдвиг
		t = a[k];
		for (j = k + 1; j < n; j++)
			a[j - 1] = a[j];
		a[j - 1] = t;
	}
}

int main(void)
{
	setlocale(LC_CTYPE, "rus");
	int i;
	// заполнение
	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	a[0] = 4; a[1] = 3; a[2] = 5; a[3] = 6; a[4] = 7;

	perm(0);
	return 0;
}