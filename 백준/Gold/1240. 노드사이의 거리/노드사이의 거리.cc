#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
vector<int> dist(1001);

int bfs(int u, int v)
{
	queue<int> q;

	q.push(u);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur])
		{
			if (dist[next.first] > 0) continue;
			dist[next.first] = dist[cur] + next.second;
			q.push(next.first);
		}
	}

	return dist[v];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, e;
		cin >> u >> v >> e;

		adj[u].push_back({ v,e });
		adj[v].push_back({ u,e });
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		fill(dist.begin(), dist.end(), 0);

		cout << bfs(u, v) << '\n';
	}

	return 0;
}