#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
	if (a.first == b.first)
	{
		if (a.second.length() == b.second.length())
		{
			return a.second < b.second;
		}
		return a.second.length() > b.second.length();
	}
	return a.first > b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, int> mm;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		if (s.length() >= m)
			mm[s]++;
	}

	vector<pair<int, string>> v;

	for (auto e : mm)
		v.push_back(make_pair(e.second, e.first));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].second << '\n';

	return 0;
}