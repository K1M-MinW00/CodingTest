#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, answer = INT_MAX;
int v[11][11], visited[11][11];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int setting(int x, int y)
{
	int sum = v[x][y];
	visited[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		visited[nx][ny] = 1;
		sum += v[nx][ny];
	}

	return sum;
}

void erase(int x, int y)
{
	visited[x][y] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		visited[nx][ny] = 0;
	}
}

bool check(int x, int y)
{
	if (visited[x][y])
		return false;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			return false;
		if (visited[nx][ny])
			return false;
	}
	return true;
}

void solve(int cnt, int sum)
{
	if (cnt == 3)
	{
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (check(i, j))
			{
				int temp = setting(i, j);
				solve(cnt + 1, sum + temp);
				erase(i, j);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	solve(0, 0);

	cout << answer;
	return 0;
}
