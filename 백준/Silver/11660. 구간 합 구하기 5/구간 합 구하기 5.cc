#include <iostream>
#include <vector>
using namespace std;

int a[1024][1024] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][0];

		for (int j = 1; j < n; ++j)
		{
			int t;
			cin >> t;
			a[i][j] = a[i][j - 1] + t;
		}
	}

	int x1, y1, x2, y2;

	for (int i = 0; i < m; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;

		if (x1 == x2 && y1 == y2)
		{
			sum = a[x1 - 1][y2 - 1] - a[x1 - 1][y2 - 2];
			cout << sum << '\n';
			continue;
		}

		for (int j = x1; j <= x2; ++j)
		{
			if (y1 == 1)
			{
				sum += a[j - 1][y2 - 1];
			}
			else
			{
				sum += a[j - 1][y2 - 1] - a[j - 1][y1 - 2];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}