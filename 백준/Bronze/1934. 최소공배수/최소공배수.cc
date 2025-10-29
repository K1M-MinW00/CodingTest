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
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	int a, b;

	while (t--)
	{
		cin >> a >> b;

		cout << lcm(a, b) << '\n';
	}

	return 0;
}