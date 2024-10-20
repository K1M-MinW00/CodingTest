#include <iostream>
using namespace std;

long long dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	int last_idx = 4;

	while (n--)
	{
		int num;
		cin >> num;

		if (dp[num])
			cout << dp[num] << '\n';
		else
		{
			for (int i = last_idx + 1; i <= num; ++i)
				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

			cout << dp[num] << '\n';
		}

		last_idx = max(last_idx, num);
	}

	return 0;
}