#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string CC = "ChongChong";

	set<string> s;
	s.insert(CC);

	string a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		if (s.find(a) != s.end())
			s.insert(b);
		else if (s.find(b) != s.end())
			s.insert(a);
	}

	cout << s.size();
	return 0;
}