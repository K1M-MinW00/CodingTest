#include <iostream>
#include <map>
using namespace std;

long long n, p, q;
map<long long, long long> m;

long long solve(long long value)
{
	if (m.find(value) != m.end())
		return m[value];

	return m[value] = solve(value / p) + solve(value / q);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> q;

	m[0] = 1;

	cout << solve(n);

	return 0;
}