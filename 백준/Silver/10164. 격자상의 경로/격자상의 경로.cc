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
int n, m, k;
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

			if (nr > tr || nc > tc || nr >= n || nc >= m)
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

	cin >> n >> m >> k;

	sr = 0, sc = 0;
	er = n - 1, ec = m - 1;

	v[0][0] = 1;

	if (k == 0)
	{
		dfs(sr, sc, er, ec);

		cout << v[er][ec];
		return 0;
	}

	k--;
	kr = k / m, kc = k % m;

	//cout << kr << ' ' << kc << '\n';
	dfs(sr, sc, kr, kc);

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//		cout << v[i][j] << ' ';
	//	cout << '\n';
	//}
	//cout << '\n';

	dfs(kr, kc, er, ec);


	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//		cout << v[i][j] << ' ';
	//	cout << '\n';
	//}
	//cout << '\n';
	cout << v[kr][kc] * v[er][ec];

	return 0;
}