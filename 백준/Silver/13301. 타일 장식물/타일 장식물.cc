#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <regex>
using namespace std;

long long dp[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] * 4 + dp[n - 1] * 2;

	return 0;
}