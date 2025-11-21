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
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

#define MAX 1000

int n, m, k;

int v[MAX][MAX];
bool visited[MAX][MAX][10];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

typedef struct
{
	int x, y, cnt, wall;
	bool day;
}s;

int bfs()
{
	int ret = -1;

	queue<s> q;
	q.push({ 0,0,1,0,true });
	visited[0][0][0] = true;

	while (q.size())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cnt = q.front().cnt;
		int wall = q.front().wall;
		bool day = q.front().day;

		q.pop();

		if (cx == n - 1 && cy == m - 1)
		{
			ret = cnt;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (v[nx][ny] == 0) // 벽 X
			{
				if (visited[nx][ny][wall] == true)
					continue;

				visited[nx][ny][wall] = true;

				q.push({ nx,ny,cnt + 1,wall,!day });
			}
			else if (v[nx][ny] == 1) // 벽 O
			{
				if (wall < k)
				{
					if (visited[nx][ny][wall + 1] == true)
						continue;

					if (day == true)
					{
						visited[nx][ny][wall + 1] = true;
						q.push({ nx,ny,cnt + 1,wall + 1,false });
					}
					else
						q.push({ cx,cy,cnt + 1,wall,true });
				}
			}
		}
	}

	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}

	cout << bfs();

	return 0;
}