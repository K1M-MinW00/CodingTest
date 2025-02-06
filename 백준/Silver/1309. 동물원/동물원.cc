#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n;
int dp[100005][3];
const int m = 9901;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1][0] = 1; // O X
	dp[1][1] = 1; // X O
	dp[1][2] = 1; // X X

	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % m;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % m;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % m;
	}

	int answer = (dp[n][0] + dp[n][1] + dp[n][2]) % m;

	cout << answer;

	return 0;
}