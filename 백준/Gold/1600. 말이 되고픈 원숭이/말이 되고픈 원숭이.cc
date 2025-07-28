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
#define N 205
#define K 31

int k, w, h;
int v[N][N];
bool visited[N][N][K];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };

void solve()
{
	priority_queue<pair<pair<int, int>, pair<int, int>>, vector< pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
	pq.push({ {0,0},{0,0} });
	visited[0][0][0] = true;

	while (pq.size())
	{
		int cur = pq.top().first.first;
		int horse = pq.top().first.second;

		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();


		if (cx == h - 1 && cy == w - 1)
		{
			cout << cur << '\n';
			return;
		}

		if (horse < k)
		{
			for (int i = 0; i < 8; ++i)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					continue;
				}

				if (v[nx][ny] == 0 && visited[nx][ny][horse + 1] == false)
				{
					visited[nx][ny][horse + 1] = true;
					pq.push({ {cur + 1,horse + 1},{nx,ny} });
				}

			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
			{
				continue;
			}

			if (v[nx][ny] == 0 && visited[nx][ny][horse] == false)
			{
				visited[nx][ny][horse] = true;
				pq.push({ {cur + 1,horse},{nx,ny} });
			}
		}
	}

	cout << -1 << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> v[i][j];
		}
	}

	solve();

	return 0;
}