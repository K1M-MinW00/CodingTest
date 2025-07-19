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
#include <tuple>
using namespace std;
#define N 2005

int n, m;
int v[N];
bool p[N][N] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 1; i < n; ++i)
	{
		p[i][i] = true;

		if (v[i] == v[i + 1])
			p[i][i + 1] = true;
	}

	p[n][n] = true;

	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = i + 2; j <= n; ++j)
		{
			if (v[i] == v[j] && p[i + 1][j - 1] == true)
			{
				p[i][j] = true;
			}
		}
	}

	cin >> m;

	int s, e;
	while (m--)
	{
		cin >> s >> e;

		cout << p[s][e] << '\n';
	}


	return 0;
}