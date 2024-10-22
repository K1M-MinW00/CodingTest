#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> dp(k + 1);

	for (int i = 1; i <= n; ++i)
		cin >> coins[i];


	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];

	return 0;
}