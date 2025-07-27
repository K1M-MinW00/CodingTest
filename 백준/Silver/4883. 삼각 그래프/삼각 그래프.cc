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
#define N 100003

int n;

int v[N][3];
int dp[N][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		fill(v[0], v[N], 0);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i][0] >> v[i][1] >> v[i][2];
		}

		dp[0][0] = INT_MAX, dp[0][1] = v[0][1], dp[0][2] = v[0][1] + v[0][2];

		for (int i = 1; i < n; ++i)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][0];
			dp[i][1] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2],dp[i][0] }) + v[i][1];
			dp[i][2] = min({ dp[i - 1][1],dp[i - 1][2],dp[i][1] }) + v[i][2];
		}


		cout << t++ << ". " << dp[n - 1][1] << '\n';
	}


	return 0;
}