#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int w, h, cnt = 0;

int v[51][51];
bool visited[51][51];

int mx[8] = { 1,-1,0,0,1,1 ,-1,-1 };
int my[8] = { 0,0,1,-1,1,-1,1,-1 };

void bfs(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r,c });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx<1 || nx>h || ny < 1 || ny > w)
				continue;
			if (v[nx][ny] == 0)
				continue;
			if (visited[nx][ny] == true)
				continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

void solve()
{
	cnt = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (v[i][j] == 1 && !visited[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 1; i <= h; ++i)
		{
			for (int j = 1; j <= w; ++j)
			{
				cin >> v[i][j];
			}
		}

		solve();


		memset(v, 0, sizeof(v));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}