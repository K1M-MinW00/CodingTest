#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;


long long  dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	dp[1][1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j];
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= 1000000007;
		}
	}

	cout << dp[n][m];


	return 0;
}