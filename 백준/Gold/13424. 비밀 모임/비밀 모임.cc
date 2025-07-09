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
#define N 105
int n, m, k;

vector<vector<pair<int, int>>> v;
vector<int> answer;

void solve(int s)
{
	vector<int> DP(n + 1, INT_MAX);

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
			int weight = v[cur][i].second;

			if (DP[next] > cnt + weight)
			{
				DP[next] = cnt + weight;
				pq.push({ DP[next],next });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		answer[i] += DP[i];
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		v.clear();
		v.resize(n + 1);
		answer.clear();
		answer.resize(n + 1, 0);

		int a, b, c, f;

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		cin >> k;

		for (int i = 0; i < k; ++i)
		{
			cin >> f;
			solve(f);
		}

		int minV = INT_MAX, idx = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (minV > answer[i])
			{
				minV = answer[i];
				idx = i;
			}
		}

		cout << idx << '\n';
	}

	return 0;
}