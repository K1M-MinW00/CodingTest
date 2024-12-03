#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	long long a = 1, b = 1;
	map<long long, int> m;

	for (int i = 2; i < 100001; ++i)
	{
		a += b;
		swap(a, b);
		if (b >= 100000000000000000LL) b -= 100000000000000000LL;
		m[a] = i;
	}

	while (t--)
	{
		string s;
		cin >> s;

		long long value = 0;
		for (auto i : s)
		{
			value = value * 10 + (i - '0');
			value %= 100000000000000000LL;
		}
		cout << m[value] << '\n';
	}

	return 0;
}