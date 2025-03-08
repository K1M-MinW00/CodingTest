#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
using namespace std;

vector<int> v[1001];
bool visited[1001];

void dfs(int k)
{
	for (int i : v[k])
	{
		if (visited[i])
			continue;
		visited[i] = true;
		dfs(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, n, num;
	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; ++i)
			v[i].clear();

		fill(visited, visited + 1001, false);

		for (int i = 1; i <= n; ++i)
		{
			cin >> num;
			v[i].push_back(num);
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i])
				continue;
			cnt++;
			visited[i] = true;
			dfs(i);
		}

		cout << cnt << '\n';
	}

	return 0;
}