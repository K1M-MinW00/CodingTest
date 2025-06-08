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
#include <bitset>

using namespace std;
int n, m, t;
int v[3005][3005];
bool visited[3005][3005];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void solve(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	visited[x][y] = true;

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m * 3)
				continue;

			if (v[nx][ny] == 0 || visited[nx][ny])
				continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m * 3; ++j)
		{
			cin >> v[i][j];
		}
	}

	cin >> t;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m * 3; j += 3)
		{
			int avg = (v[i][j] + v[i][j + 1] + v[i][j + 2]) / 3;

			if (avg >= t)
			{
				v[i][j] = v[i][j + 1] = v[i][j + 2] = 255;
			}
			else
			{
				v[i][j] = v[i][j + 1] = v[i][j + 2] = 0;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m * 3; ++j)
		{
			if (v[i][j] == 0 || visited[i][j])
				continue;

			answer++;
			solve(i, j);
		}
	}

	cout << answer;
	return 0;
}