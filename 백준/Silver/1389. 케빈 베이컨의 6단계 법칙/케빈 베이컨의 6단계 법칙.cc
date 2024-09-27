#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> v;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int i)
{
	vector<int> d(n + 1, -1);
	queue<int> q;

	q.push(i);
	d[i] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int idx = 0; idx < v[cur].size(); ++idx)
		{
			int next = v[cur][idx];
			if (d[next] != -1)
				continue;
			d[next] = d[cur] + 1;
			q.push(next);
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += d[i];

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;

	v.resize(n + 1);
	vector<int> k(n + 1);

	int x, y;

	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);

	}

	int answer = 0;
	int min = INT_MAX;

	for (int i = 1; i <= n; ++i)
	{
		k[i] = bfs(i);

		if (k[i] < min)
		{
			min = k[i];
			answer = i;
		}
	}

	cout << answer;
	return 0;
}