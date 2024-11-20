#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int dist(pair<int, int>& a, pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n + 1);
	vector<pair<int, int>> dp(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;


	int max = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		int no_skip_dist = dist(v[i], v[i + 1]) + dist(v[i + 1], v[i + 2]);
		int skip_dist = dist(v[i], v[i + 2]);

		int temp = no_skip_dist - skip_dist;

		if (max < temp)
			max = temp;
	}

	int sum = 0;
	for (int i = 1; i < n; ++i)
	{
		sum += dist(v[i], v[i + 1]);
	}

	cout << sum - max;
	return 0;
}