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

long long dp[65][10];
long long answer[65];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	answer[1] = 10;

	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= 64; ++i)
	{
		long long sum = 0;

		for (int j = 0; j < 10; ++j)
		{
			dp[i][j] = dp[i - 1][j] + sum;
			sum += dp[i - 1][j];
		}

		answer[i] = 0;
		for (int k = 0; k < 10; ++k)
			answer[i] += dp[i][k];
	}

	while (t--)
	{
		int n;
		cin >> n;

		cout << answer[n] << '\n';
	}

	return 0;
}