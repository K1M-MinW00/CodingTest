#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n + 2);
	vector<int> dp(n + 2);

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= n + 1; ++i)
	{
		dp[i] = max(dp[i - 1], dp[i]);

		int next_day = i + v[i].first;

		if (next_day <= n + 1)
		{
			dp[next_day] = max(dp[next_day], dp[i] + v[i].second);
		}
	}

	cout << dp[n + 1];

	return 0;
}