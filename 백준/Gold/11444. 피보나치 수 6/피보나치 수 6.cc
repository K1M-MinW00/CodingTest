#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;
#define D 1000000007LL

map<long long, long long> f;

long long fibo(long long n)
{
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;

	if (f.find(n) != f.end())
		return f[n];

	if (n % 2 == 0)
	{
		long long m = n / 2;
		long long temp1 = fibo(m);
		long long temp2 = fibo(m - 1);
		return f[n] = ((2LL * temp2 + temp1) * temp1) % D;
	}
	else
	{
		long long m = (n + 1) / 2;
		long long temp1 = fibo(m);
		long long temp2 = fibo(m - 1);
		return f[n] = (temp1 * temp1 + temp2 * temp2) % D;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	cout << fibo(n);

	return 0;
}