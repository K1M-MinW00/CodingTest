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

long long dp[100001][5][5];

int temp[5][5] = { {0,2,2,2,2}, {2,1,3,4,3}, {2,3,1,3,4}, {2,4,3,1,3}, {2,3,4,3,1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, idx = 1;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 100001; ++k)
				dp[k][i][j] = 100001 * 4;
		}
	}

	dp[0][0][0] = 0;

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < 5; ++i)
		{
			if (n == i)
				continue;

			for (int j = 0; j < 5; ++j)
			{
				dp[idx][i][n] = min(dp[idx - 1][i][j] + temp[j][n], dp[idx][i][n]);
			}
		}

		for (int j = 0; j < 5; ++j)
		{
			if (n == j)
				continue;

			for (int i = 0; i < 5; ++i)
			{
				dp[idx][n][j] = min(dp[idx - 1][i][j] + temp[i][n], dp[idx][n][j]);
			}
		}
		idx++;
	}

	idx--;
	long long answer = INT_MAX;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			answer = min(answer, dp[idx][i][j]);
		}
	}

	cout << answer;

	return 0;
}