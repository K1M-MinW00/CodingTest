#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long dp[36];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n + 1);
	vector<int> dp(k + 1, 10001);

	for (int i = 1; i <= n; ++i)
		cin >> coins[i];

	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == 10001)
		cout << -1;
	else
		cout << dp[k];

	return 0;
}