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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long x, y, w, s;
	long long direct, cross;

	cin >> x >> y >> w >> s;

	if (x > y)
		swap(x, y);

	if (s >= 2 * w)
	{
		direct = (x + y) * w;
		cross = 0;
	}
	else
	{
		if (s > w)
		{
			cross = x * s;
			direct = (y - x) * w;
		}
		else
		{
			if ((x + y) % 2 == 1 && x != y)
			{
				cross = (y - 1) * s;
				direct = w;
			}
			else
			{
				cross = y * s;
				direct = 0;
			}
		}
	}

	cout << cross + direct;
	return 0;
}