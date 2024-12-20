#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> v;
vector<bool> visited;

int dfs(int start)
{
	int ret = 1;
	for (int e : v[start])
	{
		if (visited[e])
			continue;
		visited[e] = true;
		ret += dfs(e);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	visited.resize(n + 1);
	int s, e;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		v[e].push_back(s);
	}

	vector<int> cnt(n + 1, 0);
	int maxValue = 0;

	for (int i = 1; i <= n; ++i)
	{
		fill(visited.begin(), visited.end(), false);

		visited[i] = true;
		cnt[i] = dfs(i);
		maxValue = max(cnt[i], maxValue);
	}

	for (int i = 1; i <= n; ++i)
		if (maxValue == cnt[i])
			cout << i << ' ';

	return 0;
}