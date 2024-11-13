#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);

	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int l = v[0].length();

	int i;
	for (i = l - 1; i >= 0; --i)
	{
		int cnt = 0;

		set<string> s;
		for (int j = 0; j < n; ++j)
		{
			s.insert(v[j].substr(i));
		}
		if (s.size() == n)
			break;
	}

	cout << l - i;
	return 0;
}