#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, answer = 0;
	cin >> n;

	string str, s;
	cin >> str;

	int str_l = str.length();
	int alpha[26] = { 0, };

	for (int i = 0; i < str_l; ++i)
		alpha[str[i] - 'A']++;


	for (int i = 0; i < n - 1; ++i)
	{
		cin >> s;

		int s_l = s.length();

		if (abs(s_l - str_l) > 1)
			continue;

		int temp[26];
		copy(alpha, alpha + 26, temp);

		int same = 0;

		for (int j = 0; j < s_l; ++j)
		{
			if (temp[s[j] - 'A'] > 0)
			{
				temp[s[j] - 'A']--;
				same++;
			}
		}

		if (str_l == s_l)
		{
			if (abs(str_l - same) <= 1)
				answer++;
		}
		else if (str_l - 1 == s_l && same == str_l - 1)
			answer++;
		else if (str_l + 1 == s_l && same == str_l)
			answer++;
	}

	cout << answer;
	return 0;
}