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
vector<vector<int>> v;
vector<bool> visited;
bool answer = false;

void dfs(int num, int idx)
{
	if (idx == 5)
	{
		answer = true;
		return;
	}

	visited[num] = true;

	for (int next : v[num])
	{
		if (visited[next])
			continue;

		dfs(next, idx + 1);
		visited[next] = false;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	visited.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		dfs(i, 1);
		visited[i] = false;

		if (answer)
			break;
	}

	cout << answer;

	return 0;
}