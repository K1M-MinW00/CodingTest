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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x[4], y[4];

	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];

	x[3] = x[0];
	y[3] = y[0];

	int result = 0, sum = 0, sub = 0;
	for (int i = 0; i < 3; ++i)
	{
		result += x[i] * y[i + 1];
		result -= x[i + 1] * y[i];
	}

	if (result < 0)
		cout << -1;
	else if (result == 0)
		cout << 0;
	else
		cout << 1;
	return 0;
}