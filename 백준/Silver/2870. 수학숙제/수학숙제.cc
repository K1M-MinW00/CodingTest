#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}

	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string s;
	vector<string> v;

	while (n--)
	{
		cin >> s;
		string temp;

		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				temp += s[i];

			else
			{
				if (temp != "")
				{
					if (temp[0] == '0')
					{
						while (temp.size() > 1)
						{
							if (temp[0] == '0')
								temp.erase(0, 1);
							else
								break;
						}
					}

					v.push_back(temp);
					temp = "";
				}
			}
		}

		if (temp != "")
		{
			if (temp[0] == '0')
			{
				while (temp.size() > 1)
				{
					if (temp[0] == '0')
						temp.erase(0, 1);
					else
						break;
				}
			}

			v.push_back(temp);
			temp = "";
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';

	return 0;
}