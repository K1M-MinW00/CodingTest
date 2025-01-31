#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
using namespace std;

string s, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;

	while (1)
	{
		if (t[t.length() - 1] == 'A')
			t.pop_back();
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}

		if (t.length() == s.length())
		{
			if (t == s)
				cout << 1;
			else
				cout << 0;
			break;
		}
	}
	return 0;
}