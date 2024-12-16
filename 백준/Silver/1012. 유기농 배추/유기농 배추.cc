#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v(50, vector<int>(50, 0));
int m, n;
int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void dfs(int i, int j)
{
	v[i][j] = 0;

	for (int k = 0; k < 4; ++k)
	{
		int cx = i + mx[k];
		int cy = j + my[k];

		if (cx < 0 || cy < 0 || cx >= m || cy >= n)
			continue;
		if (v[cx][cy] == 1)
			dfs(cx, cy);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, k, x, y, answer;
	cin >> T;

	while (T--)
	{
		answer = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (v[i][j] == 1)
				{
					answer++;
					dfs(i, j);
				}
			}
		}
		cout << answer << '\n';

		for (int i = 0; i < m; ++i)
			fill(v[i].begin(), v[i].end(), 0);
	}
	return 0;
}