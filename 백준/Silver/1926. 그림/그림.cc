#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 501

int n, m, cnt = 0;
int v[MAX][MAX];
bool visited[MAX][MAX];
vector<int> answer;

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int bfs(int x, int y)
{
	visited[x][y] = 1;

	queue<pair<int, int>> q;
	q.push({ x,y });

	int cnt = 1;

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
			if (v[nx][ny] == 0 || visited[nx][ny] != 0)
				continue;

			cnt++;
			visited[nx][ny] = 1;
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

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j] && v[i][j])
			{
				cnt++;
				int p = bfs(i, j);
				answer.push_back(p);
			}
		}
	}

	sort(answer.begin(), answer.end(), greater<int>());

	if (answer.size())
		cout << cnt << '\n' << answer[0];
	else
		cout << 0 << '\n' << 0;
	return 0;
}