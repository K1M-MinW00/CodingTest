#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
vector<vector<int>> v;
queue<pair<pair<int, int>, int>> q;

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
int answer = 0;

void bfs()
{

	while (q.size())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		answer = max(answer, cnt);
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx < 1 || nx >n || ny < 1 || ny >m || v[nx][ny] != 0)
				continue;

			v[nx][ny] = 1;
			q.push({ { nx,ny }, cnt + 1 });
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	v.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		v[i].resize(m + 1);

		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 1)
				q.push({ {i,j},0 });
		}
	}

	bfs();


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << answer;
	return 0;
}