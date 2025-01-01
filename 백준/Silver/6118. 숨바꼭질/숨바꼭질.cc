#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> visited;
vector<vector<int>> v;

void bfs(int s)
{
	visited[s] = 1;

	queue<int> q;
	q.push(s);

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (auto e : v[cur])
		{
			if (visited[e] == 0)
			{
				visited[e] = visited[cur] + 1;
				q.push(e);
			}
			else if (visited[e] > visited[cur] + 1)
				visited[e] = visited[cur] + 1;
		}
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int s, e;
	v.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end());

	bfs(1);

	vector<int> answer;
	int value = -987654321;

	for (int i = 2; i <= n; ++i)
	{
		if (visited[i] > value)
		{
			value = visited[i];
			answer = {};
			answer.push_back(i);
		}
		else if (visited[i] == value)
			answer.push_back(i);
	}

	cout << answer[0] << ' ' << visited[answer[0]] - 1 << ' ' << answer.size();
	return 0;
}