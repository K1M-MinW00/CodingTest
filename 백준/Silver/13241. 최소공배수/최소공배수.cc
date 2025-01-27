#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

long long a, b;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	long long GCD = gcd(a, b);

	return a * b / GCD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;

	cout << lcm(a, b);

	return 0;
}