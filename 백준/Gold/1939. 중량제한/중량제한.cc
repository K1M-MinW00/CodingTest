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
#define MAX 10001
int n, m, s, e;

vector<vector<pair<int, int>>> v;
vector<int> D;
void solve()
{
	priority_queue <pair<int, int>> pq;
	D[s] = INT_MAX;
	pq.push({ D[s],s });

	while (pq.size())
	{
		int curw = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (D[cur] > curw)
			continue;

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int nextw = min(curw, v[cur][i].second);

			if (D[next] < nextw)
			{
				D[next] = nextw;
				pq.push({ D[next],next });
			}
		}
	}

	cout << D[e] << '\n';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;

	int a, b, c;

	v.resize(n + 1);
	D.resize(n + 1, 0);

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> s >> e;

	solve();

	return 0;
}