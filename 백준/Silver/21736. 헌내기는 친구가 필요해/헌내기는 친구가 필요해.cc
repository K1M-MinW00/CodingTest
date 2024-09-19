#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	char c[601][601] = { -1, };
	bool visited[601][601] = { false };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> c[i][j];
			if (c[i][j] == 'I')
			{
				q.push(make_pair(i, j));
			}
		}
	}

	int dirX[4] = { 1,0,-1,0 };
	int dirY[4] = { 0,1,0,-1 };

	int answer = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newX = x + dirX[i];
			int newY = y + dirY[i];

			if (newX >= 0 && newX < n && newY >= 0 && newY < m)
			{
				if (!visited[newX][newY] && c[newX][newY] != 'X')
				{
					visited[newX][newY] = true;
					q.push(make_pair(newX, newY));

					if (c[newX][newY] == 'P')
						answer++;
				}
			}
		}
	}

	if (answer)
		cout << answer;
	else
		cout << "TT";

	return 0;
}