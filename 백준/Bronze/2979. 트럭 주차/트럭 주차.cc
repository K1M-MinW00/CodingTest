#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	vector<pair<int, int>> v(3);

	int end = 0;
	for (int i = 0; i < 3; ++i)
	{
		cin >> v[i].first >> v[i].second;
		end = max(end, v[i].second);
	}


	sort(v.begin(), v.end(), compare);

	int t = v[0].first;
	int cnt, sum = 0;

	while (t <= end)
	{
		cnt = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (v[i].first <= t && t < v[i].second)
				cnt++;
		}

		if (cnt == 1)
			sum += a;
		else if (cnt == 2)
			sum += 2 * b;
		else if (cnt == 3)
			sum += 3 * c;

		t++;
	}

	cout << sum;
	return 0;
}