#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 101
int n, m, t;

int v[MAX][MAX];
int visited[MAX][MAX][2];

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

struct p { int x, y, c; bool find; };
int answer = 0;

void solve()
{
	visited[1][1][0] = 0;

	queue<p> q;
	q.push({ 1,1,0,false });

	while (q.size())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int c = q.front().c;
		bool find = q.front().find;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];
			int nc = c + 1;

			if (nx < 1 || ny < 1 || nx > n || ny > m)
				continue;

			if (nx == n && ny == m)
			{
				answer = nc;
				return;
			}

			bool nfind = (find || v[nx][ny] == 2);
			if (find || v[nx][ny] != 1)
			{
				if (visited[nx][ny][nfind] == -1)
				{
					q.push({ nx,ny,nc,nfind });
					visited[nx][ny][nfind] = nc;
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}

	memset(visited, -1, sizeof(visited));

	solve();


	if (answer == 0 || answer > t)
		cout << "Fail";
	else
		cout << answer;

	return 0;
}