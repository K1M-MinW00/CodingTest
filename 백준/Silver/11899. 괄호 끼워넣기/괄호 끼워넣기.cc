#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int cnt = 0;
	stack<char> st;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ')')
		{
			if (st.empty())
			{
				cnt++;
			}
			else
			{
				char t = st.top();
				if (t == '(')
				{
					st.pop();
				}
			}
		}
		else
		{
			st.push('(');
		}
	}

	if (st.empty())
	{
		cout << cnt;
		return 0;
	}


	while (st.size())
	{
		char top = st.top();
		st.pop();

		if (top == '(')
		{
			cnt++;
		}
		else
		{
			if (st.empty())
				cnt++;

			else if (st.top() == '(')
				st.pop();
		}
	}

	cout << cnt;
	return 0;
}