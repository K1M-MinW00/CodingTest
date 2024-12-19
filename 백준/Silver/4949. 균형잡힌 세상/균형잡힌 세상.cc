#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string line;
	while (1)
	{
		getline(cin, line, '\n');

		if (line == ".")
			break;

		stack<char> st;
		bool answer = true;
		for (int i = 0; i < line.length(); ++i)
		{
			char c = line[i];

			if (c == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					answer = false;
					break;
				}
				else
					st.pop();
			}
			else if (c == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					answer = false;
					break;
				}
				else
					st.pop();
			}
			else if (c == '[' || c == '(')
				st.push(c);
		}

		if (st.size() || !answer)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
	}

	return 0;
}