#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>
#include <tuple>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> v;
vector<int> d;

void dijkstra()
{
	vector<bool> visited(n + 1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,k });

	d[k] = 0;

	while (pq.size())
	{
		int cur_d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int weight = v[cur][i].second;

			if (d[next] > d[cur] + weight)
			{
				d[next] = d[cur] + weight;
				pq.push({ d[next],next });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
			cout << d[i] << '\n';
		else
			cout << "INF" << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	v.resize(n + 1);
	d.resize(n + 1, INT_MAX);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;

		v[a].push_back({ b,w });
	}

	dijkstra();

	return 0;
}