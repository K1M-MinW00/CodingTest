#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

long long t, n;

bool isPrime(long long x)
{
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;

		if (n <= 1)
		{
			cout << 2 << '\n';
			continue;
		}

		while (1)
		{
			if (isPrime(n))
				break;
			n++;
		}
		cout << n << '\n';
	}
	return 0;
}