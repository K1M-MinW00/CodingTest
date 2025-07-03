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
#define N 505

int n, m;
int v[N][N];
int dp[N][N];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
		return 1;

	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (v[x][y] <= v[nx][ny])
				continue;

			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

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
			dp[i][j] = -1;
		}
	}

	int answer = dfs(0, 0);

	cout << answer;
	return 0;
}