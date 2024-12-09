#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string s, str;
	cin >> s;

	string l, r;

	bool find = false;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '*')
			find = true;

		else if (!find)
			l += s[i];
		else
			r += s[i];
	}

	int ln = l.length(), rn = r.length();
	reverse(r.begin(), r.end());

	for (int i = 0; i < n; ++i)
	{
		cin >> str;

		if (str.length() < ln)
		{
			cout << "NE" << '\n';
			continue;
		}
		string left = str.substr(0, ln);

		str = str.substr(ln);

		if (str.length() < rn)
		{
			cout << "NE" << '\n';
			continue;
		}

		reverse(str.begin(), str.end());

		string right = str.substr(0, rn);

		if (left == l && right == r)
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
	}

	return 0;
}