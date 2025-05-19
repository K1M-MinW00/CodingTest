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

	int x[3], y[3];

	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];
	
	sort(x, x + 3);
	sort(y, y + 3);

	int ax, ay;

	if (x[0] == x[1])
	{
		ax = x[2];
	}
	else
	{
		ax = x[0];
	}
	if (y[0] == y[1])
	{
		ay = y[2];
	}
	else
	{
		ay = y[0];
	}

	cout << ax << " " <<  ay;
	return 0;
}