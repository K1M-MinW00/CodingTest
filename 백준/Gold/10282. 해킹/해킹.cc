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
int n, d, c;

vector<vector<pair<int, int>>> v;
vector<int> D;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void solve()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,c });
	D[c] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (D[cur] > cnt)
			continue;

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;

			if (D[next] > cnt + v[cur][i].second)
			{
				D[next] = cnt + v[cur][i].second;
				pq.push({ D[next],next });
			}
		}
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
		cin >> n >> d >> c;

		int a, b, s;

		v.clear();
		D.clear();

		v.resize(n + 1);
		D.resize(n + 1, INT_MAX);

		for (int i = 0; i < d; ++i)
		{
			cin >> a >> b >> s;

			v[b].push_back({ a,s });
		}

		solve();

		int answer = 0, cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (D[i] != INT_MAX)
			{
				cnt++;
				answer = max(answer, D[i]);
			}
		}

		cout << cnt << ' ' << answer << '\n';
	}

	return 0;
}