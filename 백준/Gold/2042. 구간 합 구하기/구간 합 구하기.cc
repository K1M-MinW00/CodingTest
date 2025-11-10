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

void Update(int idx, long long value)
{
	long long diff = value - v[idx];
	while (idx > 0)
	{
		v[idx] += diff;
		idx /= 2;
	}
}

long long Sum(int b, int c)
{
	long long sum = 0;

	while (b <= c)
	{
		if (b % 2 == 1)
		{
			sum += v[b];
			b++;
		}
		if (c % 2 == 0)
		{
			sum += v[c];
			c--;
		}

		b /= 2;
		c /= 2;
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int size = n;
	int depth = 0;

	while (size > 0)
	{
		size /= 2;
		depth++;
	}

	size = int(pow(2, depth + 1));
	int start = size / 2 - 1;

	v.resize(size + 1);

	for (int i = start + 1; i <= start + n; ++i)
		cin >> v[i];

	for (int i = size - 1; i > 0; --i)
		v[i / 2] += v[i];

	for (int i = 0; i < m + k; ++i)
	{
		long long a, s, e;
		cin >> a >> s >> e;

		if (a == 1)
		{
			Update(s + start, e);
		}

		else if (a == 2)
		{
			s += start;
			e += start;
			cout << Sum(s, e) << '\n';
		}
	}

	return 0;
}