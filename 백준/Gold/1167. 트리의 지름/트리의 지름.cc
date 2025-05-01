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

using namespace std;

int n;
vector<vector<pair<int, int>>> v;
vector<bool> visited;

int answer = 0, vertex = 0;

void dfs(int cur, int d)
{

	if (visited[cur])
		return;

	visited[cur] = true;

	if (answer < d)
	{
		answer = d;
		vertex = cur;
	}

	for (auto e : v[cur])
	{
		int next = e.first;
		int len = e.second;

		dfs(next, len + d);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 2);
	visited.resize(n + 2);

	int start, end, length;

	for (int i = 1; i <= n; ++i)
	{
		cin >> start;

		while (1)
		{
			cin >> end;

			if (end == -1)
				break;

			cin >> length;

			v[start].push_back({ start,length });
			v[end].push_back({ start,length });
		}
	}

	dfs(1, 0);

	fill(visited.begin(), visited.end(), false);

	answer = 0;
	dfs(vertex, 0);

	cout << answer;
	return 0;
}