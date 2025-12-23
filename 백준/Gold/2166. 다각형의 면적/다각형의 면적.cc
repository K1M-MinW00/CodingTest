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

	int n;
	cin >> n;

	vector<pair<double, double>> v(n + 1);

	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	v[n] = v[0];

	double answer = 0;

	for (int i = 0; i < n; ++i)
		answer += (v[i].first * v[i + 1].second) - (v[i + 1].first * v[i].second);

	cout << fixed;
	cout.precision(1);
	cout << abs(answer) / 2.0;


	return 0;
}