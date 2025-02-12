#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int r, c, k;
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

char v[5][5];
int visited[5][5];

int solve(int x, int y)
{
	if (x == 0 && y == c - 1)
	{
		if (visited[x][y] == k)
			return 1;
		else
			return 0;
	}

	int temp = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny] || v[nx][ny] == 'T')
			continue;
		visited[nx][ny] = visited[x][y] + 1;
		temp += solve(nx, ny);
		visited[nx][ny] = 0;
	}

	return temp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> k;

	string line;
	for (int i = 0; i < r; ++i)
	{
		cin >> line;
		for (int j = 0; j < c; ++j)
			v[i][j] = line[j];
	}

	visited[r - 1][0] = 1;
	int answer = solve(r - 1, 0);

	cout << answer;
	return 0;
}