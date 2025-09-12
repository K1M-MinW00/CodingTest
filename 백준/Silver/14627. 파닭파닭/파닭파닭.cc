#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long sum = 0;
	int s, c;
	cin >> s >> c;

	vector<int> v(s);

	for (int i = 0; i < s; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	long long l = 1, r = v.back();
	long long max_l = 0;

	while (l <= r)
	{
		long long m = (l + r) / 2;
		long long cnt = 0;

		for (int i = 0; i < s; ++i)
		{
			cnt += (v[i] / m);
		}

		if (cnt < c)
		{
			r = m - 1;
		}
		else
		{
			max_l = max(max_l, m);
			l = m + 1;
		}
	}

	cout << sum - max_l * c;

	return 0;
}