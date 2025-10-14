#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
#define N 2001

int n, m, k;
int v[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	string line;

	for (int i = 1; i <= n; ++i)
	{
		cin >> line;

		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];

			if ((i + j) % 2 == 0 && line[j - 1] == 'B')
				v[i][j] += 1;
			else if ((i + j) % 2 == 1 && line[j - 1] == 'W')
				v[i][j] += 1;
		}
	}

	int answer = N * N;

	for (int i = 1; i + k - 1 <= n; ++i)
	{
		for (int j = 1; j + k - 1 <= m; ++j)
		{
			int x = i + k - 1;
			int y = j + k - 1;

			int v1 = v[x][y] - v[i - 1][y] - v[x][j - 1] + v[i - 1][j - 1];
			int v2 = k * k - v1;

			answer = min({ v1, v2, answer });
		}
	}

	cout << answer;

	return 0;
}