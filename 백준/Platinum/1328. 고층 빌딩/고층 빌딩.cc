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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int n, l, r;
long long m = 1000000007;
long long dp[101][101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	dp[1][1][1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= l; ++j)
		{
			for (int k = 1; k <= r; ++k)
			{
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % m;
			}
		}
	}

	cout << dp[n][l][r];
	return 0;
}