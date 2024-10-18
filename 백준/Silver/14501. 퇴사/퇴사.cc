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

	vector<pair<int, int>> v(n + 2);

	vector<int> dp(n + 2);

	for (int i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;

	for (int i = n; i >= 1; --i)
	{
		int deadLine = i + v[i].first;

		if (deadLine <= n + 1)
			dp[i] = max(dp[i + 1], dp[deadLine] + v[i].second);
		else
			dp[i] = dp[i + 1];
	}

	cout << dp[1];

	return 0;
}