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
#define N 101

int n, m;

int info[N][N];

void solve(int s)
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b, c;

	fill(info[0], info[N], 987654321);

	for (int i = 1; i <= n; ++i)
	{
		info[i][i] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		info[a][b] = min(info[a][b], c);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				info[j][k] = min(info[j][k], info[j][i] + info[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (info[i][j] == 987654321)
				cout << 0 << ' ';
			else
				cout << info[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}