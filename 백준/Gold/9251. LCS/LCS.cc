#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;

	cin >> a >> b;

	int n = a.length(), m = b.length();

	int dp[1001][1001];
	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(answer, dp[i][j]);
			}
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << answer;
	return 0;
}
