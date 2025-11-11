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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<double, double>> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	v.push_back(v[0]);

	double sum = 0;
	double x1, x2, y1, y2;

	for (int i = 0; i < n; ++i)
	{
		x1 = v[i].first, y1 = v[i].second;
		x2 = v[i + 1].first, y2 = v[i+1].second;

		sum += (x1 * y2) - (x2 * y1);
	}

	sum = abs(sum);
	sum /= (double)2;

	cout << fixed;
	cout.precision(1);

	cout << sum;
	return 0;
}