#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int idx = 1;
	while (1)
	{
		string str;
		cin >> str;

		if (str[0] == '-')
			break;

		stack<char> st;
		int answer = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			char c = str[i];

			if (c == '{')
				st.push(c);

			else if (st.empty() && c == '}')
			{
				st.push('{');
				answer++;
			}
			else if (!st.empty() && c == '}')
				st.pop();

		}


		answer += st.size() / 2;
		cout << idx++ << ". " << answer << '\n';

	}
	return 0;
}