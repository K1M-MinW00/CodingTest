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

typedef struct pair<int, char> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, op, before = 0;
	char c;

	cin >> n;

	deque<char> dq;
	stack<int> st;

	while (n--)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> c;
			dq.push_back(c);
			st.push(1);
		}
		else if (op == 2)
		{
			cin >> c;
			dq.push_front(c);
			st.push(2);
		}
		else
		{
			if (st.empty())
				continue;

			if (st.top() == 1)
			{
				dq.pop_back();
				st.pop();
			}
			else
			{
				dq.pop_front();
				st.pop();
			}
		}
	}

	if (dq.empty())
	{
		cout << 0;
		return 0;
	}


	for (char c : dq)
		cout << c;

	return 0;
}