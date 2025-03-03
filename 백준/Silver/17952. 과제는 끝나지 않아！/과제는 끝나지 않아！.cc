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

typedef struct pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int>>st;
	int op, a, t;

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> a >> t;
			t--;

			if (t == 0)
				answer += a;
			else
				st.push({ a,t });
		}
		else
		{
			if (st.empty())
				continue;

			p top = st.top();
			st.pop();

			int _a = top.first;
			int _t = --top.second;

			if (_t == 0)
				answer += _a;
			else
				st.push({ _a,_t });
		}
	}

	cout << answer;
	return 0;
}