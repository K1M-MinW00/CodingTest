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
#define MAX 9999999999
#define N 100001

int n, m;

vector<pair<long long, long long>> v[N];
vector<long long> D(N, MAX);
vector<int> A(N);


void solve()
{
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	D[0] = 0;
	pq.push({ 0,0 });

	while (pq.size())
	{
		long long cnt = pq.top().first;
		long long cur = pq.top().second;
		pq.pop();

		if (D[cur] < cnt)
			continue;

		for (int i = 0; i < v[cur].size(); ++i)
		{
			long long next = v[cur][i].first;
			long long next_cnt = v[cur][i].second;

			if (A[next] == 0)
			{
				if (D[next] > cnt + next_cnt)
				{
					D[next] = cnt + next_cnt;
					pq.push({ D[next],next });
				}
			}
			else
			{
				if (next == n - 1 && D[next] > cnt + next_cnt)
				{
					D[next] = cnt + next_cnt;
					pq.push({ D[next],next });
				}
			}
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	solve();

	if (D[n - 1] == MAX)
		cout << -1 << '\n';
	else
		cout << D[n - 1] << '\n';

	return 0;
}