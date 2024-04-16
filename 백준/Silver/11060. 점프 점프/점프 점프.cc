#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	queue<pair<int, int>> q; // idx - cnt

	q.push({ 1,0 });
	visited[1] = true;

	while (q.size())
	{
		int idx = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (idx == n)
		{
			cout << cnt;
			return 0;
		}

		for (int i = 1; i <= v[idx]; ++i)
		{
			int next = idx + i;

			if (next <= n && visited[next] == false)
			{
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}

	cout << -1;

	return 0;
}