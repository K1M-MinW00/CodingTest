#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, r;
int cnt = 1;
vector<vector<int>> v;
vector<int> visited;

void dfs(int s)
{
	visited[s] = cnt++;

	for (auto e : v[s])
	{
		if (visited[e])
			continue;
		dfs(e);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;

	v.resize(n + 1);
	visited.resize(n + 1);

	int s, e;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end(), greater<int>());

	dfs(r);

	for (int i = 1; i <= n; ++i)
	{
		cout << visited[i] << '\n';
	}

	return 0;
}