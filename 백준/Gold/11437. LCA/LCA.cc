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
#include <unordered_set>
#include <bitset>
#include <tuple>

using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	visited[start] = true;

	int level = 1, cnt = 0, size = 1;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : tree[cur])
		{
			if (visited[next])
				continue;

			visited[next] = true;
			q.push(next);

			parent[next] = cur;
			depth[next] = level;
		}

		cnt++;

		if (cnt == size)
		{
			size = q.size();
			cnt = 0;
			level++;
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}

	while (depth[a] != depth[b])
	{
		a = parent[a];
	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}

	return a;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, a, b;
	cin >> n;

	tree.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs(1);

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}