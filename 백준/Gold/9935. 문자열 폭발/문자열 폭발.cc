#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, b;
	cin >> s >> b;

	stack<char> st;
	vector<char> v;

	for (int i = 0; i < s.size(); ++i)
	{
		st.push(s[i]);
		if (s[i] == b.back() && st.size() >= b.size())
		{
			string temp;
			for (int j = 0; j < b.size(); ++j)
			{
				temp+=st.top();
				st.pop();
			}

			reverse(temp.begin(), temp.end());

			if (temp.compare(b) != 0)
				for (int j = 0; j < temp.size(); ++j)
					st.push(temp[j]);
		}
	}

	string result;

	while (1)
	{
		if (st.empty())
			break;

		result+=st.top();
		st.pop();
	}

	if (result.size())
	{
		reverse(result.begin(), result.end());
		cout << result;
	}
	else
		cout << "FRULA";

	return 0;
}