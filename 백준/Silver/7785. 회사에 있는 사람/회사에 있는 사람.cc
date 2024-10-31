#include <iostream>
#include <set>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	set<string, greater<string>> system;

	string name, log;

	for (int i = 0; i < n; ++i)
	{
		cin >> name >> log;

		if (log == "enter")
			system.insert(name);
		else
			system.erase(name);
	}

	for (auto name : system)
		cout << name << '\n';

	return 0;
}