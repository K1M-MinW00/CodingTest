#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int size = str.length();
	str.push_back('0');
	str.push_back('0');
	int answer = 0;

	for (int i = 0; i < size; ++i)
	{
		answer++;
		char cur = str[i];
		char next = str[i + 1];
		if (cur == 'c')
		{
			if (next == '=' || next == '-')
				i++;
		}
		else if (cur == 'd')
		{
			if (next == '-')
				i++;
			else if (next == 'z' && str[i + 2] == '=')
				i += 2;
		}
		else if ((cur == 'l' || cur == 'n') && next == 'j')
			i++;
		else if ((cur == 's' || cur == 'z') && next == '=')
			i++;
	}

	cout << answer;
	return 0;
}