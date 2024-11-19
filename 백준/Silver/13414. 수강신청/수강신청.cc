#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> uom;
	string num;
	for (int i = 1; i <= m; ++i)
	{
		cin >> num;

		uom[num] = i;
	}

	vector<pair<int, string>> v;

	for (auto e : uom)
		v.push_back({ e.second,e.first });

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		if (i == n)
			break;
		cout << v[i].second << '\n';
	}
	return 0;
}