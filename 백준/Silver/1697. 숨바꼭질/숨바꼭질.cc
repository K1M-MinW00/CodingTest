#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer = 99999;

void bfs(int n, int k)
{
	vector<int> v(100001);
	v[n] = 0;

	if (n >= k)
	{
		answer = n - k;
		return;
	}

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : { cur + 1, cur - 1, cur * 2 })
		{
			if (next == k)
			{
				answer = v[cur] + 1;
				return;
			}

			if (next < 0 || next > 100000)
				continue;
			if (v[next] != 0)
				continue;

			v[next] = v[cur] + 1;
			q.push(next);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << answer;
}