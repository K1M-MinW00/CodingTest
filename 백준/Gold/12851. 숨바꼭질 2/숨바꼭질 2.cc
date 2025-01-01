#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, answer = 0;
vector<int> visited(200005, 0);
vector<int> v(200005, 0);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << '\n' << 1;
		return 0;
	}

	visited[n] = 1;
	v[n] = 1;
	queue<int> q;
	q.push(n);

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (0 <= next && next <= 200001)
			{
				if (visited[next] == 0)
				{
					q.push(next);
					visited[next] = visited[cur] + 1;
					v[next] += v[cur];
				}
				else if (visited[next] == visited[cur] + 1)
					v[next] += v[cur];
			}
		}
	}

	cout << visited[k] - 1 << '\n' << v[k];
	return 0;
}