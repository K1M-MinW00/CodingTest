#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (v[j] < v[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] > max)
			max = dp[i];
		
	}
	cout << max;
	return 0;
}