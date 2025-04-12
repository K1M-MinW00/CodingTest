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

int v[301][301];
int n, m, r, box;

int mx[] = { 0,1,0,-1 };
int my[] = { 1,0,-1,0 };

void solve()
{
	for (int i = 0; i < box; ++i)
	{
		int start = v[i][i];
		int x = i, y = i;

		int k = 0;

		while (k < 4)
		{
			int nx = x + mx[k];
			int ny = y + my[k];

			if (nx == i && ny == i)
				break;

			if (nx >= i && nx < n - i && ny >= i && ny < m - i)
			{
				v[x][y] = v[nx][ny];
				x = nx;
				y = ny;
			}
			else
				k++;
		}
		v[i + 1][i] = start;
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];


	box = min(n, m) / 2;

	for (int i = 0; i < r; ++i)
		solve();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << v[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}