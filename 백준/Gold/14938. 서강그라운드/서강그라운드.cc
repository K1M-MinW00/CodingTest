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
#define MAX 101
int n, m, r;
vector<int> items;
vector<pair<int, int>> v[MAX];

int solve(int s)
{
	int ret = 0;

	vector<int> d(n + 1, INT_MAX);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	d[s] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int dist = d[cur] + v[cur][i].second;

			if (d[next] > dist)
			{
				d[next] = dist;
				pq.push({ d[next],next });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (d[i] <= m)
			ret += items[i];
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;

	items.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> items[i];
	}

	int a, b, t;

	for (int i = 0; i < r; ++i)
	{
		cin >> a >> b >> t;
		v[a].push_back({ b,t });
		v[b].push_back({ a,t });
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, solve(i));
	}

	cout << answer;

	return 0;
}