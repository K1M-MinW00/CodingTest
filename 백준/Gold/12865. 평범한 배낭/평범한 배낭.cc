#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[105], v[105];
int dp[105][100005];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

	return 0;
}