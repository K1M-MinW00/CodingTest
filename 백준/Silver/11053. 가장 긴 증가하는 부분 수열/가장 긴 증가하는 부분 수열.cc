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

	vector<int> v(n);
	vector<int> dp(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		cnt = max(cnt, dp[i]);
	}

	cout << cnt;

	return 0;
}