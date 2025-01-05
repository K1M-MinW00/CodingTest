#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int v[101][101];
bool visited[101][101] = { false };
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int bfs(int x, int y)
{
	int cnt = 1;
	char c = v[x][y];

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			if (v[nx][ny] != c)
				continue;

			cnt++;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	string line;

	for (int i = 0; i < m; ++i)
	{
		cin >> line;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = line[j];
		}
	}

	int w = 0, b = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j])
				continue;

			visited[i][j] = true;
			int cnt = bfs(i, j);
			if (v[i][j] == 'W')
				w += cnt * cnt;
			else
				b += cnt * cnt;
		}
	}

	cout << w << ' ' << b;

	return 0;
}
