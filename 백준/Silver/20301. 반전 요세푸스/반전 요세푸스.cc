#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n, k, m;

deque<int> dq;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;

	for (int i = 1; i <= n; ++i)
		dq.push_back(i);

	int i = 0;
	bool reverse = false;
	while (dq.size())
	{
		if (!reverse)
		{
			for (int i = 0; i < k - 1; ++i)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else
		{
			for (int i = 0; i < k - 1; ++i)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}

		if (++i % m == 0)
			reverse = !reverse;
	}

	return 0;
}