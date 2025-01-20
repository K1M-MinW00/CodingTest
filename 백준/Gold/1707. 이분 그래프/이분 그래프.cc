#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

#define MAX 20001
int n, m, k, answer;

vector<int> v[MAX];
int visited[MAX];

void dfs(int cur, int color)
{
	visited[cur] = color;

	for (int next : v[cur])
	{
		if (visited[next])
			continue;
		int next_color = (color == 1) ? 2 : 1;
		dfs(next, next_color);
	}
}

bool check()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j : v[i])
		{
			if (visited[j] == visited[i])
				return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;

	while (k--)
	{
		cin >> n >> m;

		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; ++i)
			v[i].clear();

		int s, e;

		for (int i = 0; i < m; ++i)
		{
			cin >> s >> e;
			v[s].push_back(e);
			v[e].push_back(s);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i])
				dfs(i, 1);
		}

		bool answer = check();


		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}


	return 0;
}