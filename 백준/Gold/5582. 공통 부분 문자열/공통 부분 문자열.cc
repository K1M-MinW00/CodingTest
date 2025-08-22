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


int dp[4005][4005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	int n = a.length(), m = b.length();

	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = 1;

				if (i >= 1 && j >= 1)
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
				answer = max(answer, dp[i][j]);
			}
		}
	}

	cout << answer;
	return 0;
}