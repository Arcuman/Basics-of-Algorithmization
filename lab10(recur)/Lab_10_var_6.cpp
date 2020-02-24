#include <iostream>

using namespace std;

unsigned int A(unsigned int m, unsigned int n)
{
		if (m == 0 && n >= 0)	return ++n;
		else if (m > 0 && n > 0) return A(m, n) + A(--m, A(m, --n));
		else if (m > 0 && n == 0) return A(m, 0) + A(--m, 1);
		else return 0;
}


int main()
{
	unsigned int m, n;
  cout << "¬ведите m и n" << endl;
	cin >> m >> n;
	cout << A(m, n) << endl;

	system("pause");
	return 0;
}

