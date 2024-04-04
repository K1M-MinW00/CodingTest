#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v)
{
	cout << v << ' ';

	visited[v] = true;

	for (auto x : graph[v])
	{
		if (!visited[x])
			dfs(x);
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << ' ';

		for (auto e : graph[x])
		{
			if (!visited[e])
			{
				q.push(e);
				visited[e] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	graph.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i <= n; ++i)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	cout << '\n';

	fill(visited.begin(), visited.end(), false);
	bfs(v);

	return 0;
}