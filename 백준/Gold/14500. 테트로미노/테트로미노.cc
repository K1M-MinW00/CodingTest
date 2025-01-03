#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n, m, answer;
int v[505][505];

int solve(int x, int y)
{
	int ret = 0;

	if (x + 3 <= n) ret = max(ret, v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x + 3][y]); // ㅁㅁㅁㅁ
	if (y + 3 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y + 2] + v[x][y + 3]); // ㅁㅁㅁㅁ 세로

	if (x + 1 <= n && y + 1 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x + 1][y] + v[x + 1][y + 1]); // 정사각형

	if (x - 1 >= 1 && x + 1 <= n && y + 1 <= m) ret = max(ret, v[x][y] + v[x + 1][y] + v[x - 1][y] + v[x][y + 1]); // ㅗ 모양
	if (x - 1 >= 1 && x + 1 <= n && y - 1 >= 1) ret = max(ret, v[x][y] + v[x + 1][y] + v[x - 1][y] + v[x][y - 1]);
	if (x + 1 <= n && y - 1 >= 1 && y + 1 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y - 1] + v[x + 1][y]);
	if (x - 1 >= 1 && y - 1 >= 1 && y + 1 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y - 1] + v[x - 1][y]);

	if (x - 1 >= 1 && x + 1 <= n && y - 1 >= 1) ret = max(ret, v[x][y] + v[x - 1][y] + v[x][y - 1] + v[x + 1][y - 1]); // z 모양
	if (x - 1 >= 1 && x + 1 <= n && y - 1 >= 1) ret = max(ret, v[x][y] + v[x - 1][y] + v[x][y + 1] + v[x + 1][y + 1]);
	if (x + 1 <= n && y + 1 <= m && y - 1 >= 1) ret = max(ret, v[x][y] + v[x + 1][y] + v[x][y + 1] + v[x + 1][y - 1]);
	if (x + 1 <= n && y + 1 <= m && y - 1 >= 1) ret = max(ret, v[x][y] + v[x + 1][y] + v[x][y - 1] + v[x + 1][y + 1]);


	if (x + 2 <= n && y + 1 <= m) ret = max(ret, v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x + 2][y + 1]);
	if (x + 2 <= n && y + 1 <= m) ret = max(ret, v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x][y + 1]);
	if (x + 2 <= n && y - 1 >= 1) ret = max(ret, v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x + 2][y - 1]);
	if (x + 2 <= n && y - 1 >= 1) ret = max(ret, v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x][y - 1]);
	if (x + 1 <= n && y + 2 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y + 2] + v[x + 1][y + 2]);
	if (x + 1 <= n && y + 2 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y + 2] + v[x + 1][y]);
	if (x - 1 >= 1 && y + 2 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y + 2] + v[x - 1][y + 2]);
	if (x - 1 >= 1 && y + 2 <= m) ret = max(ret, v[x][y] + v[x][y + 1] + v[x][y + 2] + v[x - 1][y]);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> v[i][j];
	}

	answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			answer = max(answer, solve(i, j));
		}
	}

	cout << answer;

	return 0;
}