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
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> v[10];
bool visited[10];
long long d[10];

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long lcm = 1;

void dfs(int cur)
{
	visited[cur] = true;

	for (auto i : v[cur])
	{
		int next = get<0>(i);

		if (visited[next])
			continue;

		d[next] = d[cur] * get<2>(i) / get<1>(i);
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int a, b, p, q;

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b >> p >> q;
		v[a].push_back({ b,p,q });
		v[b].push_back({ a,q,p });

		lcm *= (p * q) / gcd(p, q);
	}

	d[0] = lcm;
	dfs(0);

	long long _gcd = d[0];

	for (int i = 1; i < n; ++i)
	{
		_gcd = gcd(_gcd, d[i]);
	}

	for (int i = 0; i < n; ++i)
		cout << d[i] / _gcd << ' ';

	return 0;
}