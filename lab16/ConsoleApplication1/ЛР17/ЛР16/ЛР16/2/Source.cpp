#include <iostream>
#include <ctime>
using namespace std;
void find_otr(int n, int *myArr);
void zapoln(int n, int *myArr);
void vivod(int n, int *myArr);
void peren(int c, int n, int *myArr);
void main()
{
	setlocale(LC_ALL, "rus");
	const int N = 25;
	int n, myArr[N], j = 0;
	cout << "Введите размер массива (не более 25): ";
	cin >> n; cout << endl;
	if (n > 25) return;
	zapoln(n, myArr);
	cout << "Получившийся массив: ";
	vivod(n, myArr); cout << endl;
	cout << "Массив после преобразования: ";
	find_otr(n, myArr);
	vivod(n, myArr); cout << endl;
	peren(j, n, myArr); 
	cout << "Конечный результат: ";
	vivod(n, myArr); cout << endl;
	system("pause");
}

void peren(int j, int n, int *myArr)
{
	for (int i = 0; i < n-j; i++)
	{
		if (myArr[i] == 0)
		{
			j++;
			myArr[i] = myArr[n-j];
			myArr[n-j] = 0;
		}
	}

}
void vivod(int n, int *myArr)
{
	cout << "T[" << n << "] = {";
	for (int i = 0; i < n; i++)
	{
		cout << myArr[i];
		if (i + 1 < n) cout << " ";
	}
	cout << "}" << endl;
}
void find_otr(int n, int *myArr)
{
for (int i = 0; i < n; i++)
	{
		if (myArr[i] < 0)
			myArr[i] = 0;
	}
}
void zapoln(int n, int *myArr)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		myArr[i] =  -2+ rand() % 8;
	}
}
