#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <climits>
using namespace std;

int isPalindrome(int s, int e, int d, string str)
{
	while (s < e)
	{
		if (str[s] == str[e])
		{
			s++;
			e--;
			continue;
		}

		else
		{
			if (d == 0)
			{
				if (isPalindrome(s + 1, e, 1, str) == 0 || isPalindrome(s, e - 1, 1, str) == 0)
					return 1;
				else
					return 2;
			}
			else
				return 2;
		}
	}
	return 0;
}

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

		cout << isPalindrome(0, str.length() - 1, 0, str) << '\n';
	}

	return 0;
}