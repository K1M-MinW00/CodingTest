#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int num;

	priority_queue<int> minus;
	priority_queue<int, vector<int>, greater<int>> plus;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		if (num > 0)
			plus.push(num);

		else if (num < 0)
			minus.push(num);

		else
		{
			if (minus.empty() && plus.empty())
				cout << 0 << '\n';

			else
			{
				int minV = INT_MAX;
				int maxV = INT_MAX;

				if (!minus.empty())
					minV = abs(minus.top());

				if (!plus.empty())
					maxV = plus.top();

				if (minV <= maxV)
				{
					cout << minus.top() << '\n';
					minus.pop();
				}
				else
				{
					cout << maxV << '\n';
					plus.pop();
				}
			}
		}
	}

	return 0;
}