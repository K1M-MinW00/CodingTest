#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	map<int, vector<int>> m;
	vector<int> temp(26, 0);
	for (int i = 0; i < s.length(); ++i)
	{
		int idx = s[i] - 'a';
		temp[idx]++;
		m[i] = temp;
	}

	int q;
	cin >> q;

	char c;
	int l, r;

	while (q--)
	{
		cin >> c >> l >> r;

		int idx = c - 'a';

		int rr = m[r][idx];
		int ll;
		if (l > 0)
			ll = m[l - 1][idx];
		else
		{
			ll = m[l][idx];
			if (ll > 0)
				ll -= 1;
		}
		cout << rr - ll << '\n';
	}
	return 0;
}

