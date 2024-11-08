#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,op;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; ++i)
	{
		cin >> op;

		if (op != 0)
		{
			for (int j = 0; j < op; ++j)
			{
				int x;
				cin >> x;
				pq.push(x);
			}
		}

		else
		{
			if (pq.empty())
				cout << -1 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}