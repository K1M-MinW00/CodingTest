#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> v[2];
vector<int> dp[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;


		for (int i = 0; i < 2; ++i)
		{
			v[i].resize(n);
			dp[i].resize(n, 0);
			for (int j = 0; j < n; ++j)
				cin >> v[i][j];
		}

		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[0][1] = dp[1][0] + v[0][1];
		dp[1][1] = dp[0][0] + v[1][1];

		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = v[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = v[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
	return 0;
}