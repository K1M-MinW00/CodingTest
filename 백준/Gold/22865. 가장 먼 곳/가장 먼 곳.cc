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
#define N 100005

int n, m, a, b, c;
vector<vector<pair<int, int>>> v;
vector<int> answer;

void solve(int s)
{
	int DP[N];
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

	int minV = INT_MAX, idx = 0;


	for (int i = 1; i <= n; ++i)
	{
		if (i == a || i == b || i == c)
			continue;

		if (DP[i] < answer[i])
		{
			answer[i] = DP[i];
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 1);
	answer.resize(n + 1, INT_MAX);

	cin >> a >> b >> c;

	cin >> m;

	int s, e, w;

	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e >> w;
		v[s].push_back({ e,w });
		v[e].push_back({ s,w });
	}

	solve(a);
	solve(b);
	solve(c);

	int maxV = 0, idx = 0;
	for (int i = 1; i < answer.size(); ++i)
	{
		if (i == a || i == b || i == c)
			continue;

		if (maxV < answer[i])
		{
			maxV = answer[i];
			idx = i;
		}
	}

	cout << idx << '\n';
	return 0;
}