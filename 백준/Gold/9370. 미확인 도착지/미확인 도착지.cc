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
#define N 2005

int n, m, t, s, g, h;
vector<vector<pair<int, int>>> v;
vector<int> dest, answer;
int DP[N];

void solve(int s)
{
	fill(DP, DP + N, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	DP[s] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int w = v[cur][i].second;

			if (DP[next] > cnt + w)
			{
				DP[next] = cnt + w;
				pq.push({ DP[next],next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		v.clear();
		v.resize(n + 1);
		dest.clear();
		answer.clear();

		int a, b, d, x;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> d;
			v[a].push_back({ b,d });
			v[b].push_back({ a,d });
		}

		for (int i = 0; i < t; ++i)
		{
			cin >> x;
			dest.push_back(x);
		}


		int s_DP[N], h_DP[N], g_DP[N];

		solve(s);

		for (int i = 1; i <= n; ++i)
		{
			s_DP[i] = DP[i];
		}

		solve(h);

		for (int i = 1; i <= n; ++i)
		{
			h_DP[i] = DP[i];
		}

		solve(g);

		for (int i = 1; i <= n; ++i)
		{
			g_DP[i] = DP[i];
		}

		for (int i = 0; i < dest.size(); ++i)
		{
			int d = dest[i];

			if (s_DP[d] == s_DP[g] + g_DP[h] + h_DP[d])
				answer.push_back(d);

			if (s_DP[d] == s_DP[h] + h_DP[g] + g_DP[d])
				answer.push_back(d);
		}

		sort(answer.begin(), answer.end());

		for (int i : answer)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}