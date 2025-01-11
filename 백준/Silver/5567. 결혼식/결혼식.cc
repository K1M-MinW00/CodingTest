#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
int n, m;

vector<vector<int>> v;
vector<int> visited;

void solve(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			if (visited[next] > visited[cur] + 1)
			{
				visited[next] = visited[cur] + 1;
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

	cin >> n >> m;

	v.resize(n + 1);
	visited.resize(n + 1, 987654321);

	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve(1);

	int answer = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (visited[i] <= 3)
		{
			answer++;
		}
	}

	cout << answer;
	return 0;
}
