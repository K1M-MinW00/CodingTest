#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(1001);
	vector<int> dp(1001, 1000000);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	dp[1] = 0;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= v[i]; ++j)
			if (i + j <= 1000)
				dp[i + j] = min(dp[i + j], dp[i] + 1);
	}

	if (dp[n] == 1000000)
		cout << -1;

	else
		cout << dp[n];

	return 0;
}