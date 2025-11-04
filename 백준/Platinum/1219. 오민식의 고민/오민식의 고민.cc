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

typedef tuple<int, int, int> edge;

int n, m, s, e;
vector<long> d, money;
vector<edge> edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s >> e >> m;

	d.resize(n, LONG_MIN);
	money.resize(n);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({ a,b,w });
	}

	for (int i = 0; i < n; ++i)
		cin >> money[i];

	d[s] = money[s];

	for (int i = 0; i <= n + 50; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a = get<0>(edges[j]);
			int b = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			if (d[a] == LONG_MIN)
				continue;

			else if (d[a] == LONG_MAX)
				d[b] = LONG_MAX;

			else if (d[b] < d[a] + money[b] - w)
			{
				d[b] = d[a] + money[b] - w;

				if (i >= n - 1)
					d[b] = LONG_MAX;
			}
		}
	}

	if (d[e] == LONG_MIN)
		cout << "gg" << '\n';
	else if (d[e] == LONG_MAX)
		cout << "Gee" << '\n';
	else
		cout << d[e] << '\n';

	return 0;
}