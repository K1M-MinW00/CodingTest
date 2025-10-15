#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int n, m;
vector<int> inDegree;
vector<vector<int>> graph;
queue<int> q;

void topology_sort()
{
	for (int cur = 1; cur <= n; ++cur)
	{
		if (inDegree[cur] == 0)
			q.push(cur);
	}

	for (int i = 0; i < n; ++i)
	{
		if (q.empty())
		{
			cout << "cycle 발생\n";
			return;
		}

		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int k = 0; k < graph[cur].size(); ++k)
		{
			int next = graph[cur][k];
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	inDegree.resize(n + 1);
	graph.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		graph[a].emplace_back(b);
		inDegree[b]++;
	}

	topology_sort();

	return 0;
}