#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> v;

	string str, answer;
	getline(cin, str); // 띄워쓰기를 포함하여 통째로 입력을 저장, 줄 바꿈 문자를 제외하고 입력받기

	// stack<char> st;

	char c;
	string temp;

	for (int i = 0; i < str.length(); ++i)
	{
		c = str[i];

		if (c == '<')
		{
			if (temp != "")
			{
				reverse(temp.begin(), temp.end());
				answer += temp;
				temp = "";
			}

			for (i; i < str.length(); ++i)
			{
				answer += str[i];
				if (str[i] == '>')
					break;
			}
		}
		else if (c != ' ')
		{
			temp += c;
		}
		else
		{
			reverse(temp.begin(), temp.end());
			answer += temp;
			temp = "";
			answer += " ";
		}
	}

	if (temp != "")
	{
		reverse(temp.begin(), temp.end());
		answer += temp;
		temp = "";
	}

	cout << answer;

	return 0;
}