#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 500000
int n, m;
int visited[2][MAX + 4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	if (n == m)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	visited[0][n] = 1;
	q.push(n);

	int turn = 1;
	bool answer = false;

	while (q.size())
	{
		m += turn;

		if (m > MAX)
			break;

		if (visited[turn % 2][m])
		{
			answer = true;
			break;
		}

		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int cur = q.front();
			q.pop();


			for (int next : {cur + 1, cur - 1, cur * 2})
			{
				if (next <0 || next > MAX || visited[turn % 2][next])
					continue;

				visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
				if (next == m)
				{
					answer = true;
					break;
				}
				q.push(next);
			}

			if (answer)
				break;
		}
		if (answer)
			break;
		turn++;
	}

	if (answer)
		cout << turn;
	else
		cout << -1;

	return 0;
}
