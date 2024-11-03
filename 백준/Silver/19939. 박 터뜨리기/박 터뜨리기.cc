#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(k);

	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		for (int j = i; j < k; ++j)
		{
			v[j]++;
			sum++;
		}
	}

	if (n < sum)
		cout << -1;

	else
	{
		n -= sum;
		int idx = k;
		while (n--)
		{
			idx--;
			v[idx]++;
			if (idx == 0)
				idx = k;
		}

		cout << v[k - 1] - v[0];
	}

	return 0;
}