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

	string s, e, q;

	cin >> s >> e >> q;


	string t, name;

	unordered_map<string, int> p;

	int answer = 0;

	while (cin >> t >> name)
	{
		if (t <= s)
			p[name] = 1;

		else if (t >= e && t <= q)
		{
			if (p[name] == 1)
			{
				p[name] = 2;
				answer++;
			}
		}
	}

	cout << answer;
	return 0;
}