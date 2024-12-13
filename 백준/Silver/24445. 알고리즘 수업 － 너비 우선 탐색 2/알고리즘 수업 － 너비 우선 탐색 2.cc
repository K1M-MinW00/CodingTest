#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, cnt = 1;
vector<vector<int>> v;
vector <int> visited;

void bfs(int from)
{
	visited[from] = cnt++;

	queue<int> q;
	q.push(from);

	while (!q.empty())
	{
		int front = q.front();
		q.pop();


		for (auto end : v[front])
		{
			if (visited[end] == false)
			{
				visited[end] = cnt++;
				q.push(end);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, s, e;
	cin >> n >> m >> r;

	v.resize(n + 1);
	visited.resize(n + 1, 0);

	for (int i = 1; i <= m; ++i)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end(), greater<int>());

	bfs(r);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << '\n';

	return 0;
}