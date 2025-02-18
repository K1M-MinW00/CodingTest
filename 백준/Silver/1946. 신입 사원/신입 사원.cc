#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i].first >> v[i].second;

		sort(v.begin(), v.end());

		int answer = 1;
		int idx = 0;
		for (int i = 1; i < n; ++i)
		{
			if (v[idx].second > v[i].second)
			{
				answer++;
				idx = i;
			}
		}

		cout << answer << '\n';
	}
	return 0;
}