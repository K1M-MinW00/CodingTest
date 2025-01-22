#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 100001

int n, m, r;
vector<int> v[MAX];
vector<int> visited(MAX);

void bfs(int s)
{
	int cnt = 1;
	visited[s] = cnt;
	queue<int> q;
	q.push(s);

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			if (visited[next])
				continue;

			visited[next] = ++cnt;
			q.push(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;

	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end());

	bfs(r);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << '\n';

	return 0;
}