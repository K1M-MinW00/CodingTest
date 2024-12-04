#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a;
	int b;
	while (1)
	{
		cin >> a;
		if (cin.eof())
			break;
		cin >> b;

		vector<char> s;

		for (int i = 0; i < a.length(); ++i)
			s.push_back(a[i]);

		sort(s.begin(), s.end());


		cout << a << " " << b << " = ";

		int i = 1;
		bool find = false;
		do
		{
			if (i == b)
			{
				find = true;
				break;
			}
			++i;
		} while (next_permutation(s.begin(), s.end()));

		if (find)
			for (int i = 0; i < s.size(); ++i)
				cout << s[i];
		else
			cout << "No permutation";
		cout << '\n';
	}

	return 0;
}