#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


char v[304][304];
int visited[304][304];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x1, y1, x2, y2;

	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;

	string line;

	for (int i = 1; i <= n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			v[i][j + 1] = line[j];
	}

	queue<pair<int, int>> q;
	q.push({ x1,y1 });
	visited[x1][y1] = 1;

	int cnt = 0;

	while (v[x2][y2] != '0')
	{
		cnt++;
		queue<pair<int, int>> temp;

		while (q.size())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx < 1 || ny < 1 || nx > n || ny > m)
					continue;
				if (visited[nx][ny])
					continue;
				visited[nx][ny] = cnt;

				if (v[nx][ny] != '0')
				{
					v[nx][ny] = '0';
					temp.push({ nx,ny });
				}
				else
					q.push({ nx,ny });
			}
		}
		q = temp;
	}

	cout << visited[x2][y2];

	return 0;
}
