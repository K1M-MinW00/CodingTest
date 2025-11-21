#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int n;
int color = 0;

int v[101][101];
bool visited[101][101];

int mx[] = { 1,-1,0,0, };
int my[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	v[x][y] = ++color;

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (v[nx][ny] == 0 || visited[nx][ny] == true)
				continue;

			v[nx][ny] = color;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int bfs2(int num)
{
	int ret = 0;
	queue<pair<int, int>> q;

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == num)
			{
				visited[i][j] = true;
				q.push({ i,j });
			}
		}
	}

	while (q.size())
	{
		int qs = q.size();

		for (int i = 0; i < qs; ++i)
		{
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = cx + mx[j];
				int ny = cy + my[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (v[nx][ny] != 0 && v[nx][ny] != num)
					return ret;

				else if (v[nx][ny] == 0 && visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}

			}
		}
		ret++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	color = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == 0)
				continue;

			if (visited[i][j])
				continue;

			visited[i][j] = true;
			bfs(i, j);
		}
	}

	memset(visited, false, sizeof(visited));

	int answer = INT_MAX;

	for (int i = 1; i <= color; ++i)
	{
		int ret = bfs2(i);
		answer = min(ret, answer);
	}

	cout << answer;

	return 0;
}