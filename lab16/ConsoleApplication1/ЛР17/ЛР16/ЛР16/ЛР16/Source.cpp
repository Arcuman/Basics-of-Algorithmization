#include <iostream>
using namespace std;

void firstTsk() {
	double a, b, x, e = 0.001, k = 1;
	cout << "a and b: ";
	cin >> a >> b;
	x = (a + b) / 2;
	while (abs(a - b) > (2 * e))
	{
		cout << ((2 * x + x * x*x - 7)) << endl;
		if (((2 * x + x * x*x - 7)*(2 * a + a * a*a - 7)) <= 0)

			b = x;
		else
			a = x;
		cout << "a= " << a << "\tb= " << b << endl;
		x = (a + b) / 2;
		k++;
	}
	cout << "x= " << x << endl;
}

void secondTsk() {
	double a, b, x, e = 0.001, k = 1;
	cout << "a and b: ";
	cin >> a >> b;
	x = (a + b) / 2;
	while (abs(a - b) > (2 * e))
	{
		cout << ((exp(x) + 2 * x)) << endl;
		if (((exp(x) + 2 * x)*(exp(a) + 2 * a)) <= 0)

			b = x;
		else
			a = x;
		cout << "a= " << a << "\tb= " << b << endl;
		x = (a + b) / 2;
		k++;
	}
	cout << "x= " << x << endl;
}

void main()
{
	int ch;
	cout << "1 - 2x + x^3 -7" << endl;
	cout << "2 - e^x + 2x " << endl;
	cin >> ch;
	switch (ch) {
	case 1:
		firstTsk();
		break;
	case 2: 
		secondTsk();
		break;
	}
	system("pause");
}
