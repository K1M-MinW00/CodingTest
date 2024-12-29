#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int dp[65][65][65];
int a[3];
int visited[65][65][65];
int m[6][3] = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3} };

struct t
{
	int a, b, c;
};


int bfs(int x, int y, int z)
{
	visited[x][y][z] = 1;
	queue<t> q;
	q.push({ x,y,z });

	while (q.size())
	{
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;
		q.pop();

		if (visited[0][0][0])
			break;

		for (int i = 0; i < 6; ++i)
		{
			int na = max(0, ca - m[i][0]);
			int nb = max(0, cb - m[i][1]);
			int nc = max(0, cc - m[i][2]);

			if (visited[na][nb][nc])
				continue;

			visited[na][nb][nc] = visited[ca][cb][cc] + 1;
			q.push({ na,nb,nc });
		}
	}

	return visited[0][0][0] - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int answer = bfs(a[0], a[1], a[2]);
	cout << answer;
	return 0;
}