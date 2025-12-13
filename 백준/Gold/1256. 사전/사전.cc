#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

long long v[202][202];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i <= 200; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || j == i)
				v[i][j] = 1;

			else
			{
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];

				if (v[i][j] > 1000000000)
					v[i][j] = 1000000001;
			}
		}
	}

	if (v[n + m][m] < k)
		cout << -1;
	else
	{
		while (n || m)
		{
			if (v[n - 1 + m][m] >= k)
			{
				cout << "a";
				n--;
			}
			else
			{
				cout << "z";
				k -= v[n - 1 + m][m];
				m--;
			}
		}
	}

	return 0;
}