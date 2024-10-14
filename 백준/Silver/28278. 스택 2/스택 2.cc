#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		int op, num;
		cin >> op;

		if (op == 1)
		{
			cin >> num;
			s.push(num);
		}
		else if (op == 2)
		{
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (op == 3)
		{
			cout << s.size() << '\n';
		}
		else if (op == 4)
		{
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (op == 5)
		{
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}

	return 0;
}