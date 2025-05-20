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

using namespace std;

long long gcd(long long a, long long b)
{
	while (a)
	{
		long long t = b % a;
		b = a;
		a = t;
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<long long> v(n);
	vector<long long> dist(n);
	long long  d, min_gcd = 0;

	cin >> v[0];

	for (int i = 1; i < n; ++i)
	{
		cin >> v[i];

		dist[i] = v[i] - v[i - 1];
		min_gcd = gcd(min_gcd, dist[i]);
	}

	long long answer = 0;
	for (int i = 1; i < n; ++i)
		answer += (dist[i] / min_gcd) - 1;

	cout << answer;
	return 0;
}