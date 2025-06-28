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
#define N 201
#define MAX INT_MAX

int n, m;

vector<pair<int, int>> v[N];
int D[N];
int answer[N];

void solve(int s)
{
	fill(D, D + N, MAX);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	D[s] = 0;
	pq.push({ 0,s });

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int next_cnt = v[cur][i].second;


			if (D[next] > cnt + next_cnt)
			{
				answer[next] = cur;
				D[next] = cnt + next_cnt;
				pq.push({ D[next],next });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i == s)
			cout << "- ";
		else if (answer[i] == s)
			cout << i << ' ';
		else
		{
			int cur = i;
			while (1)
			{
				if (answer[cur] == s)
				{
					cout << cur << " ";
					break;
				}
				else
					cur = answer[cur];
			}
		}
		cout << ' ';
	}
	cout << '\n';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; ++i)
	{
		solve(i);
	}
	return 0;
}