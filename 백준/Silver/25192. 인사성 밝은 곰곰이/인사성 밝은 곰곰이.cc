#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	set<string> s;
	string str;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;

		if (str.compare("ENTER") == 0)
		{
			s.clear();
		}
		else
		{
			if (s.find(str) == s.end())
			{
				cnt++;
				s.insert(str);
			}
		}
	}

	cout << cnt;
	return 0;
}