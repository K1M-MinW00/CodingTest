#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 1000

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

int n, m, answer = -1;

int v[MAX][MAX];
int visited[MAX][MAX][2];

void solve()
{
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;

	queue<pair<pair<int, int>, bool>> q;
	q.push({ { 0,0 }, 0 });

	while (q.size())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		bool broken = q.front().second;

		int cur = visited[cx][cy][broken];
		q.pop();

		if (cx == n - 1 && cy == m - 1)
		{
			answer = cur;
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (visited[nx][ny][broken])
				continue;

			if (v[nx][ny] == 0)
			{
				visited[nx][ny][broken] = cur + 1;
				q.push({ {nx,ny},broken });
			}
			else if (v[nx][ny] == 1 && broken == false)
			{
				visited[nx][ny][true] = cur + 1;
				q.push({ {nx,ny}, true });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string line;
	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		cin >> line;

		for (int j = 0; j < m; ++j)
			v[i][j] = line[j] - '0';
	}

	solve();

	cout << answer;

	return 0;
}
