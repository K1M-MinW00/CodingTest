#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n;

bool isPrime(int num)
{
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

void dfs(int num, int len)
{
	if (len == n)
	{
		cout << num << '\n';
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (isPrime(num * 10 + i))
			dfs(num * 10 + i, len + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}