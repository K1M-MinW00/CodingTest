#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n >> s;

	vector<long long> v(n + 5);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int l = 0, r = 0;

	int temp = v[0];
	int min_idx = 1000001;

	while (l <= r && r < n)
	{
		if (temp < s)
		{
			temp += v[++r];
		}

		else
		{
			min_idx = min(min_idx, r - l + 1);

			temp -= v[l++];
		}

	}

	if (temp == s)
	{
		min_idx = min(min_idx, r - l + 1);
	}

	if (min_idx != 1000001)
		cout << min_idx;

	else
		cout << 0;

	return 0;
}