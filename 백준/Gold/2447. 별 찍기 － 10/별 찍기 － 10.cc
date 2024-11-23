#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 6562

char v[INT_MAX][INT_MAX];

void solve(int x, int y, int n)
{
	int r = x + n / 3;
	int c = y + n / 3;

	for (int i = r; i < r + n / 3; ++i)
	{
		for (int j = c; j < c + n / 3; ++j)
			v[i][j] = ' ';
	}

	if (n == 3)
		return;

	n /= 3;
	solve(x, y, n);
	solve(x, y + n, n);
	solve(x + n, y, n);
	solve(x, y + 2 * n, n);
	solve(x + 2 * n, y, n);
	solve(x + 2 * n, y + n, n);
	solve(x + n, y + 2 * n, n);
	solve(x + 2 * n, y + 2 * n, n);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			v[i][j] = '*';
	}

	solve(0, 0, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}

	return 0;
}