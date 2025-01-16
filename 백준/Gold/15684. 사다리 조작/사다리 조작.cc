#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, m, h;
int visited[301][301];
int answer = INT_MAX;

bool check()
{
	for (int i = 1; i <= n; ++i)
	{
		int start = i;
		for (int j = 1; j <= h; ++j)
		{
			if (visited[j][start])
				start++;
			else if (visited[j][start - 1])
				start--;
		}
		if (start != i)
			return false;
	}
	return true;
}

void solve(int cur, int cnt)
{
	if (cnt > 3 || cnt >= answer)
		return;

	if (check())
	{
		answer = min(answer, cnt);
		return;
	}

	for (int i = cur; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
				continue;
			visited[i][j] = 1;
			solve(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		visited[a][b] = 1;
	}

	solve(1, 0);

	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;

	return 0;
}
