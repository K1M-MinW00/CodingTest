#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int v[301][301] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int temp;
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= m; ++j)
		{
			cin >> temp;
			v[i][j] = v[i][j - 1] + temp;
		}
	}

	int q, r1, c1, r2, c2;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> r1 >> c1 >> r2 >> c2;

		int sum = 0;
		for (int j = r1; j <= r2; ++j)
		{
			sum += (v[j][c2] - v[j][c1 - 1]);
		}
		cout << sum << '\n';
	}
	return 0;
}