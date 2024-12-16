#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
vector<int> answer;
int n, m, ret = 0;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void dfs(int i, int j)
{
	if (visited[i][j])
		return;

	++ret;
	visited[i][j] = true;

	for (int t = 0; t < 4; ++t)
	{
		int cx = i + mx[t];
		int cy = j + my[t];

		if (cx < 0 || cy < 0 || cx >= n || cy >= m)
			continue;
		if (v[cx][cy] == 0)
		{
			dfs(cx, cy);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;

	cin >> m >> n >> k;

	v.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i)
	{
		v[i].resize(m);
		visited[i].resize(m);
	}


	int sx, sy, ex, ey;
	for (int t = 0; t < k; ++t)
	{
		cin >> sx >> sy >> ex >> ey;

		for (int i = sx; i < ex; ++i)
		{
			for (int j = sy; j < ey; ++j)
				v[i][j]++;
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0 && !visited[i][j])
			{
				ret = 0;
				dfs(i, j);

				answer.push_back(ret);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << ' ';
	return 0;
}