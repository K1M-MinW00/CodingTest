#include<iostream>

using namespace std;

long long two(int n)
{
	long long sum = 0;
	for (long long i = 2; i <= n; i *= 2)
		sum += n / i;
	return sum;
}

long long five(int n)
{
	long long sum = 0;
	for (long long i = 5; i <= n; i *= 5)
	{
		sum += n / i;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	long long a = five(n) - five(m) - five(n - m);
	long long b = two(n) - two(m) - two(n - m);

	cout << min(a, b);
	return 0;
}