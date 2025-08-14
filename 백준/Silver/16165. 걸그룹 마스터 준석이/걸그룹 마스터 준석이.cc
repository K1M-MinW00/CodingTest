#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	string team, name;
	int member;

	map<string, set<string>> gg;

	for (int i = 0; i < n; ++i)
	{
		cin >> team >> member;

		gg[team] = {};
		for (int j = 0; j < member; ++j)
		{
			cin >> name;
			gg[team].insert(name);
		}
	}

	int quiz;
	string q;
	for (int i = 0; i < m; ++i)
	{
		cin >> q >> quiz;

		if (quiz == 0)
		{
			for (string name : gg[q])
			{
				cout << name << '\n';
			}
		}
		else if (quiz == 1)
		{
			for (auto team : gg)
			{
				if (team.second.find(q) != team.second.end())
				{
					cout << team.first << '\n';
				}
			}
		}
	}

	return 0;
}