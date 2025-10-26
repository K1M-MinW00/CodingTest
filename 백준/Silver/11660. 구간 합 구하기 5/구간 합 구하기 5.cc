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
#define N 1030

int v[N][N];
int s[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];

			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}