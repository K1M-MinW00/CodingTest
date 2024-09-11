#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> v(n, 0);

	long long max = 0;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	long long start = 0, end = 2000000000;
	long long mid = 0;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		long long sum = 0;

		for (int i = 0; i < n; ++i)
		{
			long long temp = v[i] - mid;

			if (temp >= 0)
				sum += temp;
		}

		if (sum >= m)
			start = mid + 1;

		else
			end = mid - 1;
	}

	cout << end;

	return 0;
}