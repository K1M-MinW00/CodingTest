#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> v(n + 1);

		int num = n;
		for (int i = 2; i <= num; ++i)
		{
			while (num % i == 0)
			{
				num /= i;
				v[i]++;
			}
		}

		for (int i = 2; i <= n; ++i)
			if (v[i] != 0)
				cout << i << ' ' << v[i] << '\n';
	}
	return 0;
}