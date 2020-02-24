#include <iostream>

using namespace std;

int numsq(int a, int b)
{ 
	if (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
		return numsq(a, b) + 1;
	}
	else return 1;
}


int main()
{
	int a, b;

	cin >> a >> b;
	cout << numsq(a, b) << endl;

	system("pause");
	return 0;
}