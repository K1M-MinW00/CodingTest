#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	stack<int> st;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
			st.push(-1);

		else if (s[i] == ')')
		{
			int cnt = 0;

			while (st.top() != -1)
			{
				cnt += st.top();
				st.pop();
			}

			st.pop(); // '(' 제거
			cnt *= st.top(); // top 번 반복
			st.pop();

			st.push(cnt);
		}
		else // 숫자
		{
			if (i < s.length() - 1 && s[i + 1] == '(') // 괄호 앞에 반복자
				st.push(s[i] - '0');
			else // 문자 하나
				st.push(1);
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