#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, answer = 99999;
vector<vector<int>> v;
vector<vector<bool>> visited;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void bfs(int i, int j)
{

	queue<tuple<int, int, int>> q;
	q.push({ i, j,1 });

	while (!q.empty())
	{
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = cx + mx[k];
			int ny = cy + my[k];

			if (nx == n - 1 && ny == m - 1)
			{
				if (answer > cnt + 1)
					answer = cnt + 1;
			}


			if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == 0 )
				continue;

			if (v[nx][ny] == 1 && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				q.push({ nx, ny ,cnt + 1 });
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	v.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i)
	{
		string line;
		cin >> line;

		v[i].resize(m);
		visited[i].resize(m);

		for (int j = 0; j < m; ++j)
		{
			v[i][j] = (line[j] - '0');
			visited[i][j] = false;
		}

	}

	bfs(0, 0);

	cout << answer;

	return 0;
}