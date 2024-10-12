#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string temp)
{
	string s = temp;
	reverse(s.begin(), s.end());

	if (s == temp)
		return true;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int n = str.length();

	if (check(str))
	{
		cout << n;
		return 0;
	}

	for (int i = 0; i < str.size(); ++i)
	{
		string temp = str;
		for (int j = i; j >= 0; --j)
		{
			temp += str[j];
			if (check(temp))
			{
				cout << temp.length();
				return 0;
			}
		}
	}

	return 0;
}