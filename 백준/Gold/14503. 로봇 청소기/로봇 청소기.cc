#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

bool v[51][51];
bool visited[51][51];
int n, m, r, c, d;
int answer = 0;

int mx[] = { -1,0,1,0 };
int my[] = { 0,1,0,-1 };

void solve()
{
	for (int i = 0; i < 4; ++i)
	{
		int dir = (d + 3 - i) % 4;
		int nx = mx[dir] + r;
		int ny = my[dir] + c;

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny])
			continue;

		if (v[nx][ny] == 0 && visited[nx][ny] == 0) // 빈칸이 있는 경우
		{
			visited[nx][ny] = 1;
			answer++;

			r = nx;
			c = ny;
			d = dir;

			solve();
			return;
		}
	}

	int back_dir = (d + 2) % 4;
	int back_r = r + mx[back_dir];
	int back_c = c + my[back_dir];

	if (back_r >= 0 && back_r <= n && back_c >= 0 && back_c <= m)
	{
		if (v[back_r][back_c] == 0)
		{
			r = back_r;
			c = back_c;
			solve();
			return;
		}

		else
		{
			cout << answer;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];

	visited[r][c] = 1;
	answer++;

	solve();

	return 0;
}