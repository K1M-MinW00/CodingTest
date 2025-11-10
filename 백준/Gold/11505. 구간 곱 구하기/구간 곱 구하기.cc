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

const int MOD = 1000000007;

vector<long long> v;

void Update(int idx, long long value)
{
	v[idx] = value;

	while (idx > 1)
	{
		idx /= 2;
		v[idx] = v[idx * 2] % MOD * v[idx * 2 + 1] % MOD;
	}
}

int getMul(int s, int e)
{
	long long ret = 1;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			ret = ret * v[s] % MOD;
			s++;
		}
		if (e % 2 == 0)
		{
			ret = ret * v[e] % MOD;
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

	int n, m, k;
	cin >> n >> m >> k;

	int height = 0, length = n;

	while (length)
	{
		height++;
		length /= 2;
	}

	int size = int(pow(2, height + 1));
	int start = size / 2 - 1;

	v.resize(size + 1, 1);

	for (int i = start + 1; i <= start + n; ++i)
		cin >> v[i];

	for (int i = size - 1; i > 1; --i)
	{
		v[i / 2] = v[i / 2] * v[i] % MOD;
	}

	for (int i = 0; i < m + k; ++i)
	{
		int a, s, e;
		cin >> a >> s >> e;

		if (a == 1)
		{
			s += start;
			Update(s, e);
		}
		else if (a == 2)
		{
			s += start;
			e += start;
			cout << getMul(s, e) << '\n';
		}

	}
	return 0;
}