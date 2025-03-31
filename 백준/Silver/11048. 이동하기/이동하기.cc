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

using namespace std;

int n, m;
int mx[2] = { 1,0 };
int my[2] = { 0,1 };

int v[1001][1001];
int answer[1001][1001];
bool visited[1001][1001];
void solve()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });

	visited[1][1] = true;
	answer[1][1] = v[1][1];

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx > n || ny > m)
				continue;


			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				answer[nx][ny] = answer[cx][cy] + v[nx][ny];
				q.push({ nx,ny });
			}
			else if (answer[nx][ny] < answer[cx][cy] + v[nx][ny])
			{
				answer[nx][ny] = answer[cx][cy] + v[nx][ny];
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

	cout << answer[n][m];
	return 0;
}