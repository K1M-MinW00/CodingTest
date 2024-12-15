#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int v, e, k;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void solve()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,k });

	dist[k] = 0;

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (auto edge : graph[cur])
		{
			int to = edge.first;
			int weight = edge.second;

			if (dist[to] > distance + weight)
			{
				dist[to] = distance + weight;
				pq.push({ dist[to],to });
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		if (dist[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e >> k;

	graph.resize(v + 1);
	dist.resize(v + 1, INT_MAX);

	int from, to, weight;
	for (int i = 0; i < e; ++i)
	{
		cin >> from >> to >> weight;
		graph[from].push_back({ to,weight });
	}

	solve();

	return 0;
}