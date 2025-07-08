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

int n, m, p;
vector<vector<pair<int, int>>> v;


int solve(int s, int e)
{
	vector<int> D(n + 1, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	D[1] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == e)
		{
			break;
		}

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int next_cnt = v[cur][i].second;

			if (D[next] > cnt + next_cnt)
			{
				D[next] = cnt + next_cnt;
				pq.push({ D[next],next });
			}
		}
	}


	return D[e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> p;

	v.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int answer_1 = solve(1, p) + solve(p, n);
	int answer_2 = solve(1, n);

	if (answer_1 <= answer_2)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";

	return 0;
}