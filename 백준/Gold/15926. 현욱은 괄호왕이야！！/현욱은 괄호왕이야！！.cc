#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	string str;

	cin >> n >> str;

	stack<int> st;
	vector<int> d(n + 1);


	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '(')
			st.push(i);

		else if (st.size())
		{
			d[i] = 1;
			d[st.top()] = 1;
			st.pop();
		}
	}

	int len = 0, answer = 0;
	for (int i = 0; i < n; ++i)
	{
		if (d[i])
		{
			len++;
			answer = max(answer, len);
		}
		else
			len = 0;
	}

	cout << answer;
	return 0;
}