#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
#define MAX 31

int l, r, c;
char v[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int mx[] = { 1,0,0,-1,0,0 };
int my[] = { 0,1,0,0,-1,0 };
int mz[] = { 0,0,1,0,0,-1 };

typedef struct t { int x, y, z; };

void solve(int x, int y, int z)
{
	queue<t> q;
	q.push({ x,y,z });

	while (q.size())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		int cur = visited[cx][cy][cz];

		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];
			int nz = cz + mz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c)
				continue;

			if (v[nx][ny][nz] == '#')
				continue;

			if (v[nx][ny][nz] == '.')
			{
				if (visited[nx][ny][nz] == 0)
				{
					visited[nx][ny][nz] = cur + 1;
					q.push({ nx,ny,nz });
				}
				else if (visited[nx][ny][nz] > cur + 1)
				{
					visited[nx][ny][nz] = cur + 1;
					q.push({ nx,ny,nz });
				}
			}
			else
			{
				if (visited[nx][ny][nz] == 0 || visited[nx][ny][nz] > cur + 1)
					visited[nx][ny][nz] = cur + 1;
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	while (1)
	{
		cin >> l >> r >> c;

		if (!l && !r && !c)
			break;

		memset(visited, 0, sizeof(visited));

		int sx, sy, sz, ex, ey, ez;

		string line;
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				cin >> line;
				for (int k = 0; k < c; ++k)
				{
					v[i][j][k] = line[k];

					if (line[k] == 'S')
						sx = i, sy = j, sz = k;
					else if (line[k] == 'E')
						ex = i, ey = j, ez = k;
				}
			}
		}

		solve(sx, sy, sz);


		//cout << "===================\n";
		//for (int i = 0; i < l; ++i)
		//{
		//	for (int j = 0; j < r; ++j)
		//	{
		//		for (int k = 0; k < c; ++k)
		//		{
		//			cout << visited[i][j][k] << ' ';
		//		}
		//		cout << '\n';
		//	}
		//	cout << '\n';
		//}
		//cout << "===================\n";


		if (visited[ex][ey][ez] != 0)
			cout << "Escaped in " << visited[ex][ey][ez] << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}

	return 0;
}