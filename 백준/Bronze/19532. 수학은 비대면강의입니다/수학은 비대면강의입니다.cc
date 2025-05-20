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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;


	for (int x = -999; x <= 999; ++x)
	{
		for (int y = -999; y <= 999; ++y)
		{
			if (a * x + b * y == c && d * x + e * y == f)
			{
				cout << x << ' ' << y;
				return 0;
			}
		}
	}

	return 0;
}