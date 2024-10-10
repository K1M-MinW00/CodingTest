#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	list<char> ll;

	for (int i = 0; i < str.length(); ++i)
		ll.push_back(str[i]);

	int n;
	cin >> n;

	auto c = ll.end();

	for (int i = 0; i < n; ++i)
	{
		char op, temp;

		cin >> op;

		if (op == 'P')
		{
			cin >> temp;
			ll.insert(c, temp);
		}

		else if (op == 'L' && c != ll.begin())
			c--;

		else if (op == 'D' && c != ll.end())
			c++;

		else if (op == 'B' && c != ll.begin())
			c = ll.erase(--c);

	}

	for (auto e : ll)
	{
		cout << e;
	}

	return 0;
}