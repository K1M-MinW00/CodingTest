#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int n, m, answer = 0;

int map[101];
bool visited[101];

void bfs()
{
	visited[1] = true;
	queue<pair<int, int>> q;
	q.push({ 1,0 });

	while (q.size())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == 100)
		{
			answer = cnt;
			break;
		}

		for (int next : {cur + 1, cur + 2, cur + 3, cur + 4, cur + 5, cur + 6})
		{
			if (next > 100)
				continue;

			if (visited[next])
				continue;

			if (map[next] != 0)
			{
				next = map[next];
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
			else
			{
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int u, v;
	for (int i = 0; i < n + m; ++i)
	{
		cin >> u >> v;
		map[u] = v;
	}

	bfs();

	cout << answer;
	return 0;
}