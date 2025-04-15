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

using namespace std;

long long solve(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return solve(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long a, b, temp;
	cin >> a >> b;

	if (a < b)
	{
		temp = b;
		b = a;
		a = temp;
	}

	long long c = solve(a, b);

	for (long long i = 0; i < c; ++i)
		cout << 1;

	return 0;
}