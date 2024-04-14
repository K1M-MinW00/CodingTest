#include <iostream>
#include <vector>

using namespace std;

int v[1001][1001] = { 0, };
int main()
{
	int n, k;
	cin >> n >> k;

	v[0][0] = 1;
	v[1][0] = v[1][1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}

	if (k > (n / 2))
		k = n - k;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= min(n / 2, k); ++j)
		{
			v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % 10007;
			v[i][n - j] = v[i][j] % 10007;
		}
	}

	cout << v[n][k];
	return 0;
}