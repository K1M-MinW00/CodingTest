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
priority_queue<int> d[1001];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	d[1].push(0);

	while (pq.size())
	{
		int cur_d = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int weight = v[cur][i].second;

			if (d[next].size() < k)
			{
				d[next].push(cur_d + weight);
				pq.push({ cur_d + weight,next });
			}
			else if (d[next].top() > cur_d + weight)
			{
				d[next].pop();
				d[next].push(cur_d + weight);
				pq.push({ cur_d + weight, next });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (d[i].size() == k)
		{
			cout << d[i].top() << '\n';
		}
		else
			cout << -1 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	v.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
	}

	dijkstra();

	return 0;
}