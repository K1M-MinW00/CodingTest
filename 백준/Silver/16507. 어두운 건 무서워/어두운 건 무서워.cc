#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int v[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int r, c, q;

	cin >> r >> c >> q;

	for (int i = 1; i <= r; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= c; ++j)
		{
			cin >> v[i][j];
			v[i][j] += v[i][j - 1];
		}
	}

	int r1, r2, c1, c2;

	for (int i = 0; i < q; ++i)
	{
		cin >> r1 >> c1 >> r2 >> c2;

		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		int sum = 0;
		for (int x = r1; x <= r2; ++x)
		{
			sum += v[x][c2] - v[x][c1 - 1];
		}
		cout << sum / cnt << '\n';
	}
	return 0;
}