#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 201

int n;
int r1, r2, c1, c2;
int v[MAX][MAX];
int visited[MAX][MAX];

int mx[] = { -2,-2,0,0,2,2 };
int my[] = { -1,1,-2,2,-1,1 };

void bfs()
{
	visited[r1][c1] = 1;
	queue<pair<int, int>> q;
	q.push({ r1,c1 });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cnt = visited[cx][cy];
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx == r2 && ny == c2)
			{
				cout << cnt;
				return;
			}

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (visited[nx][ny] != 0)
				continue;

			visited[nx][ny] = cnt + 1;
			q.push({ nx,ny });
		}
	}

	cout << -1;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs();

	return 0;
}