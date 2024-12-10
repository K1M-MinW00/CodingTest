#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int alpha[26] = { 0, };

	for (int i = 0; i < str.length(); ++i)
	{
		alpha[str[i] - 'A']++;
	}

	int odd = 0;
	string t;
	string answer;

	for (int i = 0; i < 26; ++i)
	{
		char c = i + 'A';

		if (alpha[i] % 2 == 1)
		{
			if (t == "")
				t = c;
			else
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}

		for (int j = 0; j < alpha[i] / 2; ++j)
			answer += c;
	}

	string temp = answer;
	reverse(temp.begin(), temp.end());

	if (t != "")
		answer += t;

	answer += temp;

	cout << answer;
	return 0;
}