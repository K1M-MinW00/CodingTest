#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int v, e;
	cin >> v >> e;

	vector<vector<int>> edge(v + 1);
	vector<bool> visited(v + 1, false);
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	int answer = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		visited[cur] = true;

		for (auto s : edge[cur])
		{
			if (!visited[s])
			{
				answer++;
				visited[s] = true;
				q.push(s);
			}
		}
	}

	cout << answer;
}