#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int f, s, g, u, d, answer = 0;

void bfs()
{
	vector<int> v(f + 1, -1);
	v[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur + u, cur - d})
		{
			if (next == g)
			{
				cout << v[cur] + 1;
				return;
			}

			if (next < 1 || next > f)
				continue;

			if (v[next] != -1)
				continue;

			v[next] = v[cur] + 1;
			q.push(next);
		}
	}

	cout << "use the stairs";
	return;
}

int main()
{
	cin >> f >> s >> g >> u >> d;

	if (s == g)
	{
		cout << 0;
		return 0;
	}

	bfs();
	return 0;
}