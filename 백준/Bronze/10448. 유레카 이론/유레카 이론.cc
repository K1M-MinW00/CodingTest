#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	for (int i = 1; i <= 1000; ++i)
		v[i] = v[i - 1] + i;

	while (t--)
	{
		cin >> n;

		bool find = false;
		for (int i = 1; i < 1001; ++i)
		{
			if (v[i] >= n || find)
				break;
			for (int j = 1; j < 1001; ++j)
			{
				if (v[i] + v[j] >= n || find)
					break;
				for (int k = 1; k < 1001; ++k)
				{
					if (v[i] + v[j] + v[k] > n || find)
						break;
					int sum = v[i] + v[j] + v[k];
					if (sum == n)
					{
						// cout << v[i] << " + " << v[j] << " + " << v[k] << " = " << n << '\n';
						find = true;
						break;
					}
				}
			}
		}

		if (find)
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}
	return 0;
}