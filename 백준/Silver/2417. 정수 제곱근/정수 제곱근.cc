#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long bin(long long n)
{
	long long left = 0, right = sqrt(n), mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		long long qsquare = mid * mid;
		if (qsquare >= n)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	cout << bin(n);

	return 0;
}