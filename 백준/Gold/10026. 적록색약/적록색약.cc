#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
vector<vector<char>> v1; // normal
vector<vector<char>> v2; // abnormal
vector<vector<bool>> visited;
int n, cnt;

void dfs(vector<vector<char>>& v, int i, int j)
{
	for (int k = 0; k < 4; ++k)
	{
		int nx = i + mx[k];
		int ny = j + my[k];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (v[i][j] == v[nx][ny] && !visited[nx][ny])
		{
			visited[nx][ny] = true;
			dfs(v, nx, ny);
		}
	}
}

int main()
{
	cin >> n;

	v1.resize(n);
	v2.resize(n);
	visited.resize(n);

	char c;
	for (int i = 0; i < n; ++i)
	{
		v1[i].resize(n);
		v2[i].resize(n);
		visited[i].resize(n);

		for (int j = 0; j < n; ++j)
		{
			cin >> c;

			if (c == 'G')
			{
				v1[i][j] = 'G';
				v2[i][j] = 'R';
			}
			else
				v1[i][j] = v2[i][j] = c;
		}
	}

	cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				cnt++;
				visited[i][j] = true;
				dfs(v1, i, j);
			}

		}
	}

	int v1_cnt = cnt;
	cnt = 0;

	for (int i = 0; i < n; ++i)
		fill(visited[i].begin(), visited[i].end(), false);


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j])
			{
				cnt++;
				visited[i][j] = true;
				dfs(v2, i, j);
			}
		}
	}

	int v2_cnt = cnt;

	cout << v1_cnt << ' ' << v2_cnt;

	return 0;
}