#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 1000

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
int n, m, k, x;

vector<vector<int>> v;
vector<int> visited;

void solve(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while (q.size())
	{
		int cur = q.front();
		int cnt = visited[cur];
		q.pop();

		for (int next : v[cur])
		{
			if (visited[next] > visited[cur] + 1)
			{
				visited[next] = cnt + 1;
				q.push(next);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> x;

	v.resize(n + 1);
	visited.resize(n + 1, 987654321);

	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
	}

	solve(x);

	bool answer = false;

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == k)
		{
			cout << i << '\n';
			answer = true;
		}
	}

	if (!answer)
		cout << -1;
	return 0;
}
