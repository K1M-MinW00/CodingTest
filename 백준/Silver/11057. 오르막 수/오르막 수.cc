#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

int dp[1001][10] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
			{
				dp[i][0] = 1;
				continue;
			}

			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	int answer = 0;

	for (int i = 0; i < 10; ++i)
		answer += dp[n][i];

	cout << (answer % 10007);
	return 0;
}