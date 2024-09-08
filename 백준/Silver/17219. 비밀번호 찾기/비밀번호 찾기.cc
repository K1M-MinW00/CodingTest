#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	map<string, string> info;

	for (int i = 0; i < n; ++i)
	{
		string str, pw;
		cin >> str >> pw;

		info[str] = pw;
	}


	for (int i = 0; i < m; ++i)
	{
		string id;
		cin >> id;

		cout << info[id] << '\n';
	}

	return 0;
}