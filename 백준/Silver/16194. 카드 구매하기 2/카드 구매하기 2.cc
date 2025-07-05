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
#define N 1005

int n;
int p[N];
int dp[N];

void solve()
{
	dp[1] = p[1];

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = p[i];

		for (int j = 1; j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[n] << '\n';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	solve();

	return 0;
}