#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map<string, int> m;

	for (int i = 0; i < n; ++i)
	{
		string trash, str;
		getline(cin, trash, '.');
		cin >> str;

		m[str]++;
	}

	for (auto e : m)
	{
		cout << e.first << ' ' << e.second << '\n';
	}

	return 0;
}