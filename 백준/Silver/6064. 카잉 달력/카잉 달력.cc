#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int LCM = lcm(m, n);

		int answer = -1;

		for (int i = x; i <= LCM; i += m)
		{
			int remain_n = i % n;

			if (remain_n == 0)
				remain_n = n;

			if (remain_n == y)
			{
				answer = i;
				break;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
