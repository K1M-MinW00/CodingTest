#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int cnt2 = 0;



int f2(int n)
{
	int a = 1, b = 1, c;

	for (int i = 3; i <= n; ++i)
	{
		cnt2 = (cnt2 + 1) % 1000000007;
		c = (a + b) % 1000000007;
		a = b;
		b = c;
	}

	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << f2(n) << ' ' << cnt2;
	return 0;
}