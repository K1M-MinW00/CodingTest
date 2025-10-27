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

int n, m, s;
vector<vector<int>> v;
vector<bool> visited;
bool answer = false;

void dfs(int num)
{
	if (visited[num])
		return;

	cout << num << ' ';
	visited[num] = true;

	for (int next : v[num])
	{
		dfs(next);
	}
}

void bfs(int num)
{
	queue<int> q;
	q.push(num);

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur])
			continue;

		cout << cur << ' ';
		visited[cur] = true;

		for (int next : v[cur])
		{
			if (visited[next])
				continue;

			q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s;
	v.resize(n + 1);
	visited.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end());
	dfs(s);
	cout << '\n';

	fill(visited.begin(), visited.end(), false);

	bfs(s);
	return 0;
}