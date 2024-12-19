#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	string s;
	while (t--)
	{
		cin >> s;

		stack<char> st;
		bool answer = true;
		for (int i = 0; i < s.length(); ++i)
		{
			char c = s[i];

			if (c == ')')
			{
				if (st.empty() || st.top() == ')')
				{
					answer = false;
					break;
				}
				else
					st.pop();
			}
			else
				st.push(c);
		}

		if (st.size())
			answer = false;

		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}