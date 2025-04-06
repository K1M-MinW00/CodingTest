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

using namespace std;

int n, m, k, r, c;
int v[101][101];
bool visited[101][101];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int answer = 0;

int solve(int r, int c)
{
	queue<pair<int, int>> q;
	int cnt = 1;
	q.push({ r,c });

	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (v[nx][ny] == 1 && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> r >> c;
		v[r - 1][c - 1] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0)
				continue;

			if (visited[i][j])
				continue;


			visited[i][j] = true;
			int cnt = solve(i, j);

			answer = max(answer, cnt);
		}
	}

	cout << answer;
	return 0;
}