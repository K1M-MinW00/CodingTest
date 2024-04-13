#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1, vector<int>(10, 0)); // int v[n+1][10] 0,1,2,3,4,5,6,7,8,9

	for (int i = 1; i <= 9; ++i)
		v[1][i] = 1;

	if (n == 1)
	{
		cout << 9;
		return 0;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j > 0 && j < 9)
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j + 1];
			else if (j == 0)
				v[i][j] = v[i - 1][1];
			else if (j == 9)
				v[i][j] = v[i - 1][8];
			v[i][j] %= 1000000000;
		}
	}

	int total = 0;

	for (int i = 0; i < 10; ++i)
	{
		total = (total+v[n][i]) % 1000000000;
	}

	cout << total;

	return 0;
}