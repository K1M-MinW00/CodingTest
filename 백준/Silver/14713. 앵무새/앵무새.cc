#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

vector<queue<string>> parrot(100);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cin.ignore();

	string str, word, L;

	for (int i = 0; i < n; ++i)
	{
		getline(cin, str);
		word = "";
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] == ' ')
			{
				parrot[i].push(word);
				word = "";
			}
			else
				word += str[j];

			if (j == str.length() - 1)
				parrot[i].push(word);
		}
	}

	getline(cin, L);
	word = "";

	for (int i = 0; i < L.length(); ++i)
	{
		if (L[i] == ' ' || i == L.length() - 1)
		{
			if (i == L.length() - 1)
				word += L[i];

			bool flag = false;

			for (int j = 0; j < n; ++j)
			{
				if (parrot[j].front() == word)
				{
					parrot[j].pop();
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << "Impossible";
				return 0;
			}

			word = "";
		}
		else
		{
			word += L[i];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (parrot[i].size())
		{
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";
	return 0;
}