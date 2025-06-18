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
#define MAX 50001

int n, m, c;
vector<vector<pair<int, int>>> v;
vector<bool> visited;
vector<int> d;

void solve()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	visited[1] = true;
	d[1] = 0;

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

	solve();

	cout << d[n] << '\n';

	return 0;
}