#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int n;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void dfs(int i, int j, int k)
{
	if (visited[i][j])
		return;

	visited[i][j] = true;

	for (int t = 0; t < 4; ++t)
	{
		int cx = i + mx[t];
		int cy = j + my[t];

		if (cx < 1 || cy < 1 || cx > n || cy > n)
			continue;
		if (v[cx][cy] > k)
			dfs(cx, cy, k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer = 0, high = 0;
	cin >> n;

	v.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		v[i].resize(n + 1);
		visited[i].resize(n + 1);

		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			if (high < v[i][j])
				high = v[i][j];
		}
	}

	for (int k = 0; k < high; ++k)
	{
		int cnt = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (v[i][j] > k && visited[i][j] == false)
				{
					cnt++;
					dfs(i, j, k);
				}
			}
		}

		for (int i = 1; i <= n; ++i)
			fill(visited[i].begin(), visited[i].end(), false);

		answer = max(answer, cnt);
	}

	cout << answer;
	return 0;
}