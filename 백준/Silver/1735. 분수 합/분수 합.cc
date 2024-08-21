#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;

	else
		return gcd(b, a % b);
}

int main()
{
	int na, nb, ma, mb;
	cin >> na >> nb >> ma >> mb;

	int lcm = nb * mb;

	na *= mb;
	ma *= nb;

	int s = na + ma;
	int k = gcd(lcm, s);

	cout << s / k << ' ' << lcm / k;
	return 0;
}