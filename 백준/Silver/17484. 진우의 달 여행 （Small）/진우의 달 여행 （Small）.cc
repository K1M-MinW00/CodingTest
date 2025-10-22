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
#include <tuple>
using namespace std;
#define MAX 7

int n, m;
int v[MAX][MAX];
int dp[MAX][MAX][3];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];

			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = v[i][j];

			if (j == 0)
				dp[i][j][0] = INT_MAX;
			if (j == m - 1)
				dp[i][j][2] = INT_MAX;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (j > 0) // 제일 왼쪽 제외, 왼쪽 아래로
				dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);

			// 아래로
			dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);

			if (j != m - 1) // 제일 오른쪽 제외,오른쪽 아래로
				dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
		}
	}

	int answer = INT_MAX;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < 3; ++j)
			answer = min(answer, dp[n - 1][i][j]);
	}

	cout << answer;

	return 0;
}