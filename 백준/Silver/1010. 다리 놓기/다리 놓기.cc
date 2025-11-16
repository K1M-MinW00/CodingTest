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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	int dp[31][31];

	for (int i = 0; i < 31; ++i)
	{
		dp[i][1] = 1;
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	for (int i = 2; i < 31; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		cout << dp[m][n] << '\n';
	}
	return 0;
}