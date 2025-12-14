#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n;
int t[16];
int p[16];
int dp[17];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> t[i] >> p[i];


	for (int i = n; i > 0; --i)
	{
		if (i + t[i] > n + 1)
			dp[i] = dp[i + 1];

		else
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
	}

	cout << dp[1];

	return 0;
}