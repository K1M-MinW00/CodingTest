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

	stack<int> st;

	int temp;

	for (int i = 0; i < str.length(); ++i)
	{
		char c = str[i];

		if (c == '(')
			st.push(0);
		else if (c == 'H')
			st.push(1);
		else if (c == 'C')
			st.push(12);
		else if (c == 'O')
			st.push(16);
		else if (c >= '2' && c <= '9')
		{
			temp = st.top() * (c - '0');
			st.pop();
			st.push(temp);
		}
		else if (c == ')')
		{
			temp = 0;
			while (st.top() != 0)
			{
				temp += st.top();
				st.pop();
			}
			st.pop();
			st.push(temp);
		}
	}

	int answer = 0;

	while (st.size())
	{
		answer += st.top();
		st.pop();
	}

	cout << answer;
	return 0;
}