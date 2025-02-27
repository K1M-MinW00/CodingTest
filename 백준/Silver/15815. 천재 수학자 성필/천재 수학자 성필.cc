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

	string s;
	cin >> s;

	stack<int> st;

	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];

		if (c >= '0' && c <= '9')
			st.push(c - '0');
		else
		{
			int second = st.top();
			st.pop();
			int first = st.top();
			st.pop();

			switch (c)
			{
			case '+': st.push(first + second);
				break;
			case '-': st.push(first - second);
				break;
			case '*': st.push(first * second);
				break;
			case '/': st.push(first / second);
				break;
			}
		}
	}

	cout << st.top();
	return 0;
}