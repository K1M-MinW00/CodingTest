#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

int n, answer = 0;

struct board {
	int v[24][24];

	void rotate90()
	{
		int temp[24][24];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				temp[i][j] = v[n - j - 1][i];
		}
		memcpy(v, temp, sizeof(v));
	}

	void move()
	{
		int temp[24][24];

		for (int i = 0; i < n; ++i)
		{
			int c = -1, d = 0;

			for (int j = 0; j < n; ++j)
			{
				if (v[i][j] == 0)
					continue;

				if (d && v[i][j] == temp[i][c])temp[i][c] *= 2, d = 0;
				else
					temp[i][++c] = v[i][j], d = 1;
			}
			for (c++; c < n; c++)
				temp[i][c] = 0;
		}
		memcpy(v, temp, sizeof(v));
	}

	void getMax()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				answer = max(answer, v[i][j]);
		}
	}
};

void solve(board b, int here)
{
	if (here == 5)
	{
		b.getMax();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		board d = b;
		d.move();
		solve(d, here + 1);
		b.rotate90();
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	board c;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> c.v[i][j];

	solve(c, 0);

	cout << answer;
	return 0;
}