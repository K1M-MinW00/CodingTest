#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int n, m, answer = 0;

char a[54][54];
int visited[54][54];
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x][y] = 1;

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

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (a[nx][ny] == 'W')
				continue;
			if (visited[nx][ny])
				continue;
			visited[nx][ny] = visited[cx][cy] + 1;
			q.push({ nx,ny });
			answer = max(answer, visited[nx][ny]);
		}
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
		string line;
		cin >> line;
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = line[j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 'L')
				bfs(i, j);
		}
	}

	cout << answer - 1;
	return 0;
}