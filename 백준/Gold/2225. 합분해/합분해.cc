#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n, k;
const long long m = 1000000000;
long long dp[201][201];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= k; ++i)
		dp[1][i] = i;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
		}
	}

	cout << dp[n][k];
	return 0;
}