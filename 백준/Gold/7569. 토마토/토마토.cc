#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, int> point;

const int MAX = 101;
int n, m, h;
int v[MAX][MAX][MAX];

int mx[6] = { 1,-1,0,0,0,0 };
int my[6] = { 0,0,1,-1,0,0 };
int mz[6] = { 0,0,0,0,1,-1 };

queue<pair<point, int>> q;
int answer = 0;

void bfs()
{
	while (!q.empty())
	{
		point p = q.front().first;
		int cnt = q.front().second;
		answer = max(cnt, answer);

		q.pop();

		int x = p.first.first;
		int y = p.first.second;
		int z = p.second;

		for (int i = 0; i < 6; ++i)
		{
			int nx = x + mx[i];
			int ny = y + my[i];
			int nz = z + mz[i];

			if (nx < 1 || nx > h || ny < 1 || ny > n || nz < 1 || nz > m)
				continue;
			if (v[nx][ny][nz] != 0)
				continue;

			v[nx][ny][nz] = 1;
			point np = { {nx,ny},nz };
			q.push({ np,cnt + 1 });

		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				cin >> v[i][j][k];

				if (v[i][j][k] == 1)
				{
					point p = { {i,j},k };
					q.push({ p,0 });
				}
			}
		}
	}

	bfs();

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				if (v[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;

	return 0;
}