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

using namespace std;

#define MAX 51

int n, m;

int v[MAX][MAX];
int visited[MAX][MAX];

int mx[] = { 0,-1,0,1 };
int my[] = { -1,0,1,0 };

int cnt = 0;
int area[MAX * MAX];
int area_max = 0, sum_max = 0;

int solve(int x, int y, int cnt)
{
	if (visited[x][y])
		return 0;

	visited[x][y] = cnt;

	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		if (!(v[x][y] & (1 << i)))
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			ret += solve(nx, ny, cnt);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				cnt++;
				area[cnt] = solve(i, j, cnt);
				area_max = max(area_max, area[cnt]);
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i + 1 < m)
			{
				int a = visited[i + 1][j];
				int b = visited[i][j];

				if (a != b)
					sum_max = max(sum_max, area[a] + area[b]);
			}
			if (j + 1 < n)
			{
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b)
					sum_max = max(sum_max, area[a] + area[b]);
			}
		}
	}

	cout << cnt << '\n' << area_max << '\n' << sum_max;

	return 0;
}