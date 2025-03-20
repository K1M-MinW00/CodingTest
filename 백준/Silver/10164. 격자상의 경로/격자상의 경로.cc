#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int mx[] = { 1,0 };
int my[] = { 0,1 };

int v[16][16];
bool visited[16][16];
int sr, sc, er, ec, kr, kc;

void dfs(int r, int c, int tr, int tc)
{
	queue<pair<int, int>> q;
	q.push({ r, c });

	while (q.size())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			int nr = r + mx[i];
			int nc = c + my[i];

			if (nr > tr || nc > tc)
				continue;

			if (nr == tr && nc == tc)
			{
				v[nr][nc] += 1;
				continue;
			}

			q.push({ nr,nc });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	sr = 1, sc = 1;
	er = n, ec = m;

	v[1][1] = 1;

	if (k == 0)
	{
		dfs(sr, sc, er, ec);

		cout << v[er][ec];
		return 0;
	}

	kr = k / m + 1, kc = k % m;

	dfs(sr, sc, kr, kc);
	dfs(kr, kc, er, ec);

	cout << v[kr][kc] * v[er][ec];

	return 0;
}