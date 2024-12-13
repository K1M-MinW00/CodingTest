#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<bool> visited;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n;

	v.resize(n + 1);
	visited.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	cin >> s;

	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		visited[front] = true;

		int next = front + v[front];
		int prev = front - v[front];

		if (next >= 1 && next <= n)
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}

		if (prev >= 1 && prev <= n)
		{
			if (!visited[prev])
			{
				visited[prev] = true;
				q.push(prev);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
		if (visited[i])
			answer++;

	cout << answer;
	return 0;
}