#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
using namespace std;


int r, c;

int v[21][21];
bool a[26] = { false, };

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int answer = 0;

void dfs(int x, int y, int cnt)
{
	a[v[x][y]] = true;
	cnt++;
	if (cnt > answer)
		answer = cnt;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + mx[i];
		int ny = y + my[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			char curc = v[nx][ny];

			if (a[curc] == false)
			{
				dfs(nx, ny, cnt);
				a[v[nx][ny]] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	string line;

	for (int i = 0; i < r; ++i)
	{
		cin >> line;
		for (int j = 0; j < c; ++j)
			v[i][j] = line[j] - 'A';
	}

	answer = 0;

	dfs(0, 0, 0);

	cout << answer;

	return 0;
}