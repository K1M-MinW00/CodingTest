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
#define N 5
int n;
long long b;

long long v[N][N], temp[N][N], ans[N][N];

void matrix_multi(long long x[N][N], long long y[N][N])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp[i][j] = 0;

			for (int k = 0; k < n; ++k)
			{
				temp[i][j] += (x[i][k] * y[k][j]) % 1000;
			}

			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			x[i][j] = temp[i][j];
		}
	}

	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
		ans[i][i] = 1;
	}


	while (b)
	{
		if (b % 2 == 1)
		{
			matrix_multi(ans, v);
		}

		matrix_multi(v, v);
		b /= 2;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}