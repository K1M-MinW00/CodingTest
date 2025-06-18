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

using namespace std;
int n, m, x, y;
vector<vector<pair<int, int>>> v;
vector<bool> visited;
vector<int> d;

int solve(int s, int e)
{
	fill(visited.begin(), visited.end(), false);
	fill(d.begin(), d.end(), 2147483647);

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	visited[s] = true;
	d[s] = 0;

	while (pq.size())
	{
		int cur = pq.top().second;
		pq.pop();

		visited[cur] = true;

		for (auto e : v[cur])
		{
			int next = e.first;
			int food = e.second;

			if (!visited[next] && d[next] > d[cur] + food)
			{
				d[next] = d[cur] + food;
				pq.push({ d[next],next });
			}
		}
	}

	return d[e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1);
	visited.resize(n + 1, false);
	d.resize(n + 1, INT_MAX);

	int a, b, c;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> x >> y;

	cout << solve(x, y);


	return 0;
}