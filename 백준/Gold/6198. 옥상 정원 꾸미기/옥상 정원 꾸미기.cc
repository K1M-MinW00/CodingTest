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

	int n, num;
	cin >> n;

	stack<int> st;
	long long answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		if (st.empty())
		{
			st.push(num);
			continue;
		}

		while (st.size())
		{
			int top = st.top();

			if (top <= num)
				st.pop();
			else
				break;
		}

		answer += st.size();
		st.push(num);
	}

	cout << answer;

	return 0;
}