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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int ccw(long x1, long y1, long x2, long y2, long  x3, long y3)
{
	long result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	return 0;
}

bool isOverlab(long x1, long y1, long x2, long y2, long  x3, long y3, long x4, long y4)
{
	if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
		return true;

	return false;
}

bool isCross(long x1, long y1, long x2, long y2, long  x3, long y3, long x4, long y4)
{
	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd == 0 && cda * cdb == 0)
		return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
	else if (abc * abd <= 0 && cda * cdb <= 0)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	bool answer = isCross(x1, y1, x2, y2, x3, y3, x4, y4);

	if (answer)
		cout << 1;
	else
		cout << 0;

	return 0;
}