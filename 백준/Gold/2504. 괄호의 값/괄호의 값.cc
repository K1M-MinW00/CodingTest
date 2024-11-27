#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int temp = 1, answer = 0;
	stack<char> st;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(')
		{
			temp *= 2;
			st.push('(');
		}

		else if (str[i] == '[')
		{
			temp *= 3;
			st.push('[');
		}

		else if (str[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				answer = 0;
				break;
			}

			if (str[i - 1] == '(')
			{
				answer += temp;
				temp /= 2;
				st.pop();
			}
			else
			{
				temp /= 2;
				st.pop();
			}
		}

		else if (str[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				answer = 0;
				break;
			}

			if (str[i - 1] == '[')
			{
				answer += temp;
				temp /= 3;
				st.pop();
			}
			else
			{
				temp /= 3;
				st.pop();
			}
		}

	}

	if (!st.empty())
		answer = 0;


	cout << answer;
	return 0;
}