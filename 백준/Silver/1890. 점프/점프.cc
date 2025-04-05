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

int mx[] = { 1,0 };
int my[] = { 0,1 };

int n;
int v[101][101];
long long dp[101][101];

long long solve(int x, int y)
{
	if (x >= n || y >= n)
		return 0;

	if (x == n - 1 && y == n - 1)
		return 1;

	if (v[x][y] == 0)
		return 0;

	if (dp[x][y] != 0)
		return dp[x][y];

	return dp[x][y] = solve(x + v[x][y], y) + solve(x, y + v[x][y]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	// fill(dp, dp + n * n, -1);

	cout << solve(0, 0);
	return 0;
}