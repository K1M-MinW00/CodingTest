#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<long long, int> m;

bool cmp(pair<long long, int> a, pair<long long, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long num;
		cin >> num;
		m[num]++;
	}

	vector<pair<long long, int>> v(m.begin(), m.end());


	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;
	return 0;
}