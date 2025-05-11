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

using namespace std;

#define N 1005

int t, n, m, cnt;
int visited[N];
vector<int> v[N];

void solve(int cur)
{
	visited[cur] = 1;

	for (int next : v[cur])
	{
		if (visited[next])
			continue;

		solve(next);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		fill(visited, visited + N, 0);
		for (int i = 0; i < N; ++i)
			v[i].clear();

		cnt = 0;
		cin >> n >> m;

		int s, e;
		for (int i = 0; i < m; ++i)
		{
			cin >> s >> e;
			v[s].push_back(e);
			v[e].push_back(s);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (visited[i])
				continue;

			solve(i);
			cnt++;
		}

		if (m == n - 1 && cnt == 1)
			cout << "tree\n";
		else
			cout << "graph\n";
	}

	return 0;
}