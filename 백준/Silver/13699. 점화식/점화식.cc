#include <iostream>
using namespace std;

long long dp[36];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}

	cout << dp[n];

	return 0;
}