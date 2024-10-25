#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	deque<int> dq;

	int op, x;
	while (n--)
	{
		cin >> op;

		switch (op)
		{
		case 1:
			cin >> x;
			dq.push_front(x);
			break;
		case 2:
			cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << '\n';
			break;
		case 6:
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 7:
			if (dq.size())
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
			break;
		case 8:
			if (dq.size())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
			break;
		}
	}

	return 0;
}