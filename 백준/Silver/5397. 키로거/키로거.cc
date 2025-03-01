#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;

		list<char> answer;
		list<char>::iterator it = answer.begin();

		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == '<')
			{
				if (it != answer.begin())
					it--;
			}
			else if (str[i] == '>')
			{
				if (it != answer.end())
					it++;
			}
			else if (str[i] == '-')
			{
				if (it != answer.begin())
					it = answer.erase(--it);
			}
			else
			{
				it = answer.insert(it, str[i]);
				it++;
			}
		}

		for (char c : answer)
			cout << c;
		cout << '\n';
	}
	return 0;
}