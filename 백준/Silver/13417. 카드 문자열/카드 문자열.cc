#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, num;
	char card[1001];

	cin >> t;

	while (t--)
	{
		cin >> n;

		deque<char> dq;

		for (int j = 0; j < n; ++j)
		{
			cin >> card[j];

			if (j == 0)
				dq.push_back(card[j]);
			else if (card[j] <= dq.front())
				dq.push_front(card[j]);
			else
				dq.push_back(card[j]);
		}

		for (auto it : dq)
			cout << it;
		cout << '\n';
	}

	return 0;
}