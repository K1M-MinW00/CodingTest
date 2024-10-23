#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}


	dp.resize(n + 2);
	for (int i = 1; i <= n; ++i)
		dp[i].resize(n + 2, 1);

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;


	for (int i = 3; i <= n; ++i)
	{
		for (int j = 2; j <= (i + 1) / 2; ++j)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (j != i - j + 1)
				dp[i][i - j + 1] = dp[i][j];
		}
	}


	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << dp[n][k];

	return 0;
}