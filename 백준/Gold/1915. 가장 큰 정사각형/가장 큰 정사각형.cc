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
#define N 1005

int n, m;
int v[N][N];

void solve()
{
	int l = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j] != 0)
			{
				v[i][j] = min(v[i - 1][j - 1], min(v[i][j - 1], v[i - 1][j])) + 1;

				if (l < v[i][j])
					l = v[i][j];
			}
		}
	}

	cout << l * l << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	string str;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			v[i][j + 1] = str[j] - '0';
		}
	}

	solve();

	return 0;
}