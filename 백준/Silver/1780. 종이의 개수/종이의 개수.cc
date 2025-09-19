#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;
#define N 2200

int n;
int v[N][N];

int m1 = 0, zero = 0, p1 = 0;

void solve(int r, int c, int size)
{
	bool same = true;
	int num = v[r][c];

	for (int i = r; i < r + size; i++)
	{
		if (!same)
			break;

		for (int j = c; j < c + size; j++)
		{
			if (v[r][c] != v[i][j])
			{
				same = false;
				break;
			}
		}
	}

	if (same || size == 1)
	{
		if (num == -1)
			m1++;
		else if (num == 0)
			zero++;
		else if (num == 1)
			p1++;

		return;
	}

	else
	{
		int t = size / 3;
		solve(r, c, t);
		solve(r, c + t, t);
		solve(r, c + 2 * t, t);
		solve(r + t, c, t);
		solve(r + t, c + t, t);
		solve(r + t, c + 2 * t, t);
		solve(r + 2 * t, c, t);
		solve(r + 2 * t, c + t, t);
		solve(r + 2 * t, c + 2 * t, t);
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	solve(0, 0, n);

	cout << m1 << '\n' << zero << '\n' << p1;


	return 0;
}