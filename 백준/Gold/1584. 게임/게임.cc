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
#include <bitset>

using namespace std;
int n, m, x, y;

int v[505][505];
bool visited[505][505];
int d[505][505];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void solve()
{
	fill(&d[0][0], &d[501][501], INT_MAX);

	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{0,0} });

	while (pq.size())
	{
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		int cur = pq.top().first;

		pq.pop();

		if (cur > d[cy][cx])
			continue;

		d[cy][cx] = cur;

		if (cx == 500 && cy == 500)
			return;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx > 500 || ny > 500)
				continue;

			if (v[ny][nx] == 2)
				continue;

			if (d[ny][nx] > d[cy][cx] + v[ny][nx])
			{
				d[ny][nx] = d[cy][cx] + v[ny][nx];
				pq.push({ d[ny][nx],{nx,ny} });
			}
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	// v : 0 - 안전 , 1 - 위험 , 2 - 죽음
	int x1, x2, y1, y2;
	int sx, sy, ex, ey;
	while (n--)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		sx = min(x1, x2);
		ex = max(x1, x2);
		sy = min(y1, y2);
		ey = max(y1, y2);

		for (int i = sx; i <= ex; i++)
		{
			for (int j = sy; j <= ey; j++)
			{
				v[i][j] = 1;
			}
		}
	}

	cin >> m;

	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		sx = min(x1, x2);
		ex = max(x1, x2);
		sy = min(y1, y2);
		ey = max(y1, y2);

		for (int i = sx; i <= ex; i++)
		{
			for (int j = sy; j <= ey; j++)
			{
				v[i][j] = 2;
			}
		}
	}

	solve();

	if (d[500][500] == INT_MAX)
		cout << -1;
	else
		cout << d[500][500];

	return 0;
}