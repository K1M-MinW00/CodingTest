#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	int h = 0;

	for (int i = 0; i < n; ++i)
	{
		if (h < v[i].first)
		{
			h = v[i].first + v[i].second;
		}
		else
		{
			h += v[i].second;
		}
	}

	cout << h;
	return 0;
}