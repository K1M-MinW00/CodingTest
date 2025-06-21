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

int n, m, x;
vector<vector<pair<int, int>>> f, r;

vector<int> solve(int s, vector<vector<pair<int, int>>>& v)
{
	vector<int> d(n + 1, INT_MAX);

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	d[s] = 0;

	while (pq.size())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		for (int i = 0; i < v[cur.second].size(); ++i)
		{
			int next = v[cur.second][i].first;
			int dist = cur.first + v[cur.second][i].second;

			if (d[next] > dist)
			{
				d[next] = dist;
				pq.push({ d[next],next });
			}
		}
	}

	return d;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x;

	f.resize(n + 1);
	r.resize(n + 1);
	int a, b, t;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> t;
		f[a].push_back({ b,t });
		r[b].push_back({ a,t });
	}

	vector<int> go = solve(x, f);
	vector<int> back = solve(x, r);

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, go[i] + back[i]);
	}

	cout << answer << '\n';

	return 0;
}