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
int v[301][301];
int dp[301][301];
bool visited[301][301];

int mx[] = { 1,0 };
int my[] = { 0,1 };

void solve()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });

	visited[1][1] = true;
	dp[1][1] = v[1][1];

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = dp[cx][cy];
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx< 1 || ny < 1 || nx>n || ny > m)
				continue;

			if (visited[nx][ny] == false)
			{
				dp[nx][ny] = cur + v[nx][ny];
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (dp[nx][ny] < cur + v[nx][ny])
			{
				dp[nx][ny] = cur + v[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> v[i][j];

	solve();

	cout << dp[n][m];
	return 0;
}