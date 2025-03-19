#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

set<pair<int, int>> problems;
map<int, int> pl; // problem-level

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, p, l, x;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> p >> l;

		problems.insert({ l,p });
		pl[p] = l;
	}

	cin >> m;

	string op;

	for (int i = 0; i < m; ++i)
	{
		cin >> op;

		if (op == "recommend")
		{
			cin >> x;

			if (x == 1) // 가장 어려운
				cout << problems.rbegin()->second << '\n';
			else // 가장 쉬운
				cout << problems.begin()->second << '\n';
		}

		else if (op == "add")
		{
			cin >> p >> l;
			problems.insert({ l,p });
			pl[p] = l;
		}

		else // solved
		{
			cin >> p;
			problems.erase({ pl[p],p });
		}
	}

	return 0;
}