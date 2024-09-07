#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	cin >> k >> n;

	vector<long long> v(k);

	long long end = INT_MAX;

	for (int i = 0; i < k; ++i)
	{
		cin >> v[i];
	}


	long long start = 1;

	while (start <= end)
	{
		long long mid = start + (end - start) / 2;

		long long sum = 0;

		for (int i = 0; i < k; ++i)
			sum += (v[i] / mid);

		if (sum < n)
			end = mid - 1;

		else if (sum >= n)
			start = mid + 1;
	}

	cout << end;

	return 0;
}