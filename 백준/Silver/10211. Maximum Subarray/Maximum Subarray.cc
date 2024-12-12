#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> dp(n + 1, 0);
		int temp;
		for (int i = 1; i <= n; ++i)
		{
			cin >> temp;
			dp[i] = temp + dp[i - 1];

			dp[i] = max(temp, dp[i]);
		}

		int answer = dp[1];
		for (int i = 1; i <= n; ++i)
		{
			//cout << dp[i] << ' ';
			if (answer < dp[i])
				answer = dp[i];
		}
		cout << answer << '\n';
	}
	return 0;
}