#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> v;
vector<int> d;

void bfs(int s)
{
	vector<bool> visited(n + 1);
	fill(d.begin(), d.end(), 0);
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;
			int dist = v[cur][i].second;

			if (visited[next])
				continue;

			visited[next] = true;
			q.push(next);
			d[next] = d[cur] + dist;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.resize(n + 1);
	d.resize(n + 1);

	int num, a, b;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num;

		while (1)
		{
			cin >> a;

			if (a == -1)
				break;

			cin >> b;

			v[num].push_back({ a, b });
		}
	}

	bfs(1);

	int idx = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (d[idx] < d[i])
			idx = i;
	}

	bfs(idx);

	sort(d.begin(), d.end());
	cout << d[n];

	return 0;
}