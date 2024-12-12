#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> visited;

int cnt = 0;

void dfs(int s)
{
	visited[s] = ++cnt;

	for (auto a : g[s])
	{
		if (visited[a] == false)
			dfs(a);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, r, u, v;
	cin >> n >> m >> r;

	visited.resize(n + 1, false);
	g.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end());

	dfs(r);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << '\n';
	return 0;
}