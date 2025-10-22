#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int n, answer = 0;
int v[18][18];

int mx[] = { 0,1,1 }; // 오른쪽, 아래, 대각선 아래
int my[] = { 1,0,1 }; // 오른쪽, 아래, 대각선 아래

void dfs(int x, int y, int dir)
{
	if (x == n && y == n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (dir == 0 && i == 1)
			continue;

		if (dir == 1 && i == 0)
			continue;

		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;

		if (v[nx][ny] == 1)
			continue;

		if (i == 2 && (v[x + 1][y] == 1 || v[x][y + 1] == 1))
			continue;

		dfs(nx, ny, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}

	dfs(1, 2, 0);
	cout << answer;

	return 0;
}