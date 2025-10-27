#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

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
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (answer < v[i].second - i)
			answer = v[i].second - i;
	}

	cout << answer + 1;
	return 0;
}