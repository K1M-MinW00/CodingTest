#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	int temp;

	for (int i = l; i <= 100; ++i)
	{
		temp = (n - i * (i - 1) / 2);
		if (temp / i >= 0 && temp % i == 0)
		{
			int x = temp / i;
			for (int j = x; j < x + i; ++j)
				cout << j << ' ';
			return 0;
		}
	}

	cout << -1;
	return 0;
}