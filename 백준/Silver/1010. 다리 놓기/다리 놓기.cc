#include <iostream>
#include <vector>

using namespace std;

int dp[31][31] = { 0, };

int func(int n, int m)
{
	if (dp[n][m] != 0)
		return dp[n][m];
	
	if (n == 1)
		return dp[n][m] = m;
	else
	{
		for (int i = n - 1; i < m; ++i)
			dp[n][m] += func(n - 1, i);

		return dp[n][m];
	}
}
int main()
{
	int t;
	cin >> t;

	for (int i = 1; i < 30; ++i)
	{
		for (int j = i; j < 30; ++j)
				func(i, j);
	}

	for (int i = 1; i <= t; ++i)
	{
		int n, m;
		cin >> n >> m;

		cout << dp[n][m] << '\n';
	}

	return 0;
}