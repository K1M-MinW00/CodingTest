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

using namespace std;

int n, m;
int v[41];
int dp[41];
int answer = 1;

void solve()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	int start = 0;

	for (int i = 0; i < m; ++i)
	{
		int vip = v[i];
		answer *= dp[vip - start - 1];
		start = vip;
	}

	answer *= dp[n - start];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int num;
	for (int i = 0; i < m; ++i)
		cin >> v[i];


	solve();

	cout << answer;
	return 0;
}