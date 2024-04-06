#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;

int bfs(int i)
{
	int cnt = 0;
	vector<bool> visited(n+1,false);
	queue<int> q;
	q.push(i);
	visited[i] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int x : v[cur])
		{
			if (!visited[x])
			{
				visited[x] = true;
				q.push(x);
				++cnt;
			}
		}
	}
	
	return cnt;
}

int main()
{
	cin >> n >> m;

	v.resize(n+1);

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[b].push_back(a);
	}

	vector<int> answer(n+1);
	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		answer[i] = bfs(i);
		if (max < answer[i])
			max = answer[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		if (max == answer[i])
			cout << i << ' ';
	}

	return 0;
}