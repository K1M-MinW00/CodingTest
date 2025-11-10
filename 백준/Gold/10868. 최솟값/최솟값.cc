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
#include <unordered_set>
#include <bitset>
#include <tuple>

using namespace std;

vector<long long> v;

long long getMin(long long s, long long e)
{
	long long ret = LLONG_MAX;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			ret = min(ret, v[s]);
			s++;
		}
		if (e % 2 == 0)
		{
			ret = min(ret, v[e]);
			e--;
		}

		s /= 2;
		e /= 2;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int height = 0, length = n;

	while (length)
	{
		height++;
		length /= 2;
	}

	int size = int(pow(2, height + 1));
	int start = size / 2 - 1;

	v.resize(size + 1, LLONG_MAX);

	for (int i = start + 1; i <= start + n; ++i)
		cin >> v[i];

	for (int i = size - 1; i > 1; --i)
	{
		if (v[i / 2] > v[i])
			v[i / 2] = v[i];
	}

	for (int i = 0; i < m; ++i)
	{
		long long s, e;
		cin >> s >> e;

		s += start;
		e += start;

		cout << getMin(s, e) << '\n';
	}
	return 0;
}