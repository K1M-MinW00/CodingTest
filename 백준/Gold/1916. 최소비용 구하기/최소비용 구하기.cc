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

int n, m, s, e;
vector<vector<pair<int, int>>> v;
vector<int> d;

void dijkstra()
{
	vector<bool> visited(n + 1);
	d.resize(n + 1, INT_MAX);
	d[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });

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

	cout << d[e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
	}

	cin >> s >> e;

	dijkstra();

	return 0;
}