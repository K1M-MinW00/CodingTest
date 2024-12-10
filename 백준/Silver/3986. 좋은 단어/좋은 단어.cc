#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	int answer = 0;

	while (n--)
	{
		cin >> s;

		stack<char>st;

		bool good = true;
		for (int i = 0; i < s.length(); ++i)
		{
			char cur = s[i];

			if (st.empty())
				st.push(cur);

			else
			{
				char top = st.top();

				if (top == cur)
					st.pop();
				else
					st.push(cur);
			}
		}

		if (st.size() >= 2)
		{
			char top = st.top();
			st.pop();
			char ttop = st.top();

			if (top != ttop)
				good = false;
		}
		else if (st.size() == 1)
			good = false;

		if (good)
			answer++;
	}

	cout << answer;
	return 0;
}