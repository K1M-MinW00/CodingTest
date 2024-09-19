#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


vector<vector<int>> v;
vector<bool> visited;

void BFS(int i);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;

		v[s].push_back(e);
		v[e].push_back(s);
	}

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			BFS(i);
			answer++;
		}
	}

	cout << answer;

	return 0;
}

void BFS(int i)
{
	if (visited[i])
		return;

	visited[i] = true;

	for (int e : v[i])
	{
		if (!visited[e])
			BFS(e);
	}
}