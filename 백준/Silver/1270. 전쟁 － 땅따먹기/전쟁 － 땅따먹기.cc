#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;

		map<long long, long long> m;
		for (int j = 0; j < t; ++j)
		{
			long long temp;
			cin >> temp;

			m[temp]++;
		}

		long long max_v = 0, max_idx;
		for (auto e : m)
		{
			if (e.second > max_v)
			{
				max_idx = e.first;
				max_v = e.second;
			}
		}

		if (max_v > t / 2)
			cout << max_idx << '\n';
		else
			cout << "SYJKGW" << '\n';
	}
	return 0;
}