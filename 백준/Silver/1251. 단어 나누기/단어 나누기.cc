#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	vector<string> s;
	int n = str.length();

	for (int i = 1; i <= n - 2; ++i)
	{
		for (int j = 1; j <= n - i - 1; ++j)
		{
			string a = str.substr(0, i);
			string b = str.substr(i, j);
			string c = str.substr(i + j);

			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());

			s.push_back(a + b + c);
		}
	}

	sort(s.begin(), s.end());
	cout << s[0];

	return 0;
}