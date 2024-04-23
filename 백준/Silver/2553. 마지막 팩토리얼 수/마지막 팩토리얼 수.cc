#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	int n;
	cin >> n;

	long long tmp = 1;

	for (int i = 2; i <= n; ++i)
	{
		tmp *= i;

		while (tmp % 10 == 0)
			tmp /= 10;

		tmp %= 10000000;
	}

	cout << tmp % 10;
}