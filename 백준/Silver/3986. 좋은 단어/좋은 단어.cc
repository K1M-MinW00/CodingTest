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

		for (int i = 0; i < s.length(); ++i)
		{
			char cur = s[i];

			if (st.size() && st.top() == cur)
				st.pop();
			else
				st.push(cur);
		}

		if (st.empty())
			answer++;

	}

	cout << answer;
	return 0;
}