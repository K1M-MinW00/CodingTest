#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<string, int>> v[305];

	for (int i = 0; i < n; ++i)
	{
		int level;
		string name;
		cin >> level >> name;

		bool makeRoom = true;
		for (int j = 0; j <= i; ++j)
		{
			if (v[j].size() < m && v[j].size() > 0)
			{
				if (abs(v[j][0].second - level) <= 10)
				{
					makeRoom = false;
					v[j].push_back({ name,level });
					break;
				}
			}
		}

		if (makeRoom)
			v[i].push_back({ name,level });
	}

	for (int i = 0; i < n; ++i)
	{
		if (v[i].size() == 0)
			continue;

		else if (v[i].size() == m)
			cout << "Started!" << '\n';

		else if (v[i].size() < m)
			cout << "Waiting!" << '\n';

		sort(v[i].begin(), v[i].end());

		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j].second << ' ' << v[i][j].first << '\n';
	}

	return 0;
}