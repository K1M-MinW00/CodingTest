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
	fill(d.begin(), d.end(), INT_MAX);

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

	int d_1_x = solve(1, x);
	int d_x_y = solve(x, y);
	int d_y_n = solve(y, n);

	int d_1_y = solve(1, y);
	int d_y_x = solve(y, x);
	int d_x_n = solve(x, n);

	int p1 = d_1_x + d_x_y + d_y_n;
	int p2 = d_1_y + d_y_x + d_x_n;

	if (d_1_x == INT_MAX || d_x_y == INT_MAX || d_y_n == INT_MAX)
		p1 = INT_MAX;
	if (d_1_y == INT_MAX || d_y_x == INT_MAX || d_x_n == INT_MAX)
		p2 = INT_MAX;

	if (p1 == INT_MAX && p2 == INT_MAX)
		cout << -1 << '\n';
	else
		cout << min(p1, p2) << '\n';

	return 0;
}