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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n;

		vector<int> v(21);
		vector<int> dp(10001);

		dp[0] = 1;

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cin >> m;

		for (int i = 0; i < n; ++i)
		{
			for (int j = v[i]; j <= m; ++j)
			{
				dp[j] += dp[j - v[i]];
			}
		}

		cout << dp[m] << '\n';
	}

	return 0;
}