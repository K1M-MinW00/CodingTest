#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, m, b, answer_t = INT_MAX, answer_h;
int v[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> b;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	

	for (int h = 0; h <= 256; ++h)
	{
		int op1 = 0; // remove
		int op2 = 0; // add

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] > h)
					op1 += v[i][j] - h;
				else if (v[i][j] < h)
					op2 += h - v[i][j];
			}
		}

		if (b + op1 < op2)
			continue;

		int temp = op1 * 2 + op2;
		if (answer_t >= temp)
		{
			answer_t = temp;
			answer_h = h;
		}
	}

	cout << answer_t << ' ' << answer_h;
	return 0;
}
