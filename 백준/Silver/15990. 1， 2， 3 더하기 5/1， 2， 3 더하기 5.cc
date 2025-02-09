#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int t, n;
const int MAX = 100001;
const int M = 1000000009;

int dp[MAX][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i < MAX; ++i)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % M; // 2 + 1 , 3 + 1
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % M; // 1 + 2 , 3 + 2
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % M; // 1 + 3 , 2 + 3
	}

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;

		cout << ((long long)dp[n][1] + (long long)dp[n][2] + (long long)dp[n][3]) % M << '\n';
	}

	return 0;
}