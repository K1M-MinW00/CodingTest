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

int n, m;

typedef tuple<int, int, int> edge;

vector<edge> edges;
vector<long> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	d.resize(n + 1,LONG_MAX);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edges.push_back({ a,b,w });
	}

	d[1] = 0;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int s = get<0>(edges[j]);
			int e = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			if (d[s] != LONG_MAX && d[e] > d[s] + w)
				d[e] = d[s] + w;
		}
	}

	bool minusCycle = false;

	for (int i = 0; i < m; ++i)
	{
		int s = get<0>(edges[i]);
		int e = get<1>(edges[i]);
		int w = get<2>(edges[i]);

		if (d[s] != LONG_MAX && d[e] > d[s] + w)
			minusCycle = true;
	}

	if (minusCycle == false)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (d[i] == LONG_MAX)
				cout << -1 << '\n';
			else
				cout << d[i] << '\n';
		}
	}
	else
		cout << -1 << '\n';
	
	return 0;
}