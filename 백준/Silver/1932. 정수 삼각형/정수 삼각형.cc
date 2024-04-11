#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	int num;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int j = 1; j <= n; ++j)
		dp[n][j] = v[n][j];

	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + v[i][j];
		}
	}

	cout << dp[1][1];

	return 0;
}