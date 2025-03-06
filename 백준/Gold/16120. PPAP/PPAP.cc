#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	stack<char> st;

	for (int i = 0; i < str.length(); ++i)
	{
		st.push(str[i]);

		if (st.size() >= 4 && str[i] == 'P')
		{
			string temp;

			for (int i = 0; i < 4; ++i)
			{
				temp.push_back(st.top());
				st.pop();
			}

			if (temp == "PAPP")
				temp = "P";

			for (int j = temp.size() - 1; j >= 0; --j)
				st.push(temp[j]);
		}
	}

	if (st.size() == 1 && st.top() == 'P')
		cout << "PPAP";
	else
		cout << "NP";

	return 0;
}