#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m;
int arr[1001][1001];
int dist[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dist[i][j] = -1;
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				dist[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	int dirX[4] = { 1,0,-1,0 };
	int dirY[4] = { 0,1,0,-1 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nX = cur.first + dirX[i];
			int nY = cur.second + dirY[i];

			if (nX < 0 || nX >= n || nY < 0 || nY >= m)
				continue;

			if (dist[nX][nY] != -1)
				continue;

			if (arr[nX][nY] == 0)
				continue;


			dist[nX][nY] = dist[cur.first][cur.second] + 1;
			q.push({ nX, nY });
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == 0)
				cout << 0 << ' ';
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}