#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	stack<char> st;


	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];

		else
		{
			if (str[i] == '(')
				st.push('(');
			else if (str[i] == '*' || str[i] == '/')
			{
				while (st.size() && (st.top() == '*' || st.top() == '/'))
				{
					cout << st.top();
					st.pop();
				}
				st.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				while (st.size() && (st.top() != '('))
				{
					cout << st.top();
					st.pop();
				}
				st.push(str[i]);
			}
			else if (str[i] == ')')
			{
				while (st.size() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop(); // '(' 추출
			}
		}
	}

	while (st.size())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}