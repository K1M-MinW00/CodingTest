#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 51

int n, m;
int v[MAX][MAX];
int visited[MAX][MAX];

int mx[] = { -1,-1,-1,0,0,1,1,1 };
int my[] = { -1,0,1,-1,1,-1,0,1 };

vector<pair<int, int>> s;

int bfs(int x, int y)
{
	int answer = 0;

	visited[x][y] = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cnt = visited[cx][cy];
		q.pop();

		for (int j = 0; j < 8; ++j)
		{
			int nx = cx + mx[j];
			int ny = cy + my[j];

			if (v[nx][ny] == 1)
				return cnt;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (visited[nx][ny])
				continue;

			visited[nx][ny] = cnt + 1;
			q.push({ nx,ny });
		}
	}
	return 0;
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
		{
			cin >> v[i][j];

			if (v[i][j] != 1)
				s.push_back({ i,j });
		}
	}

	int answer = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		memset(visited, 0, sizeof(visited));

		int x = s[i].first;
		int y = s[i].second;

		int d = bfs(x, y);

		answer = max(answer, d);
	}

	cout << answer;
	return 0;
}