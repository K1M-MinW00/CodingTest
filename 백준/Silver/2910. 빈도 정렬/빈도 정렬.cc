#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.second.first == b.second.first) // 등장 횟수 같으면
		return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unordered_map<int, pair<int, int>> uom;

	int n, c, t;
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;

		if (uom.find(t) == uom.end())
			uom.insert({ t,{1,i} });

		else
			uom[t].first++;
	}

	vector<pair<int, pair<int, int>>> v(uom.begin(), uom.end());

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].second.first; ++j)
			cout << v[i].first << ' ';
	}
	return 0;
}