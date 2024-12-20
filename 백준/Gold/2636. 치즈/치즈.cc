#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int v[101][101];
bool visited[101][101];
vector<pair<int, int>> temp;

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	visited[x][y] = true;

	if (v[x][y] == 1)
	{
		temp.push_back({ x,y });
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (visited[nx][ny])
			continue;

		bfs(nx, ny);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	}

	int cnt1 = 0, cnt2 = 0;

	while (true)
	{
		fill(&visited[0][0], &visited[n - 1][m - 1], false);
		temp.clear();

		bfs(0, 0);

		cnt2 = temp.size();

		for (auto t : temp)
			v[t.first][t.second] = 0;

		bool flag = false;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] != 0)
					flag = true;
			}
		}
		cnt1++;

		if (!flag)
			break;
	}

	cout << cnt1 << '\n' << cnt2;
	return 0;
}