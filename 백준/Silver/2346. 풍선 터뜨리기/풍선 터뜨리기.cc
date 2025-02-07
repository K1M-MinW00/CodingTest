#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int temp;
	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		dq.push_back({ i,temp });
	}

	int front = dq.front().first;
	int move = dq.front().second;
	dq.pop_front();

	cout << front << ' ';

	pair<int, int> p;
	while (dq.size())
	{
		if (move > 0)
		{
			for (int i = 0; i < move; ++i)
			{
				p = dq.front();
				dq.pop_front();

				if (i != move - 1)
					dq.push_back(p);
			}

		}
		else
		{
			for (int i = move; i < 0; ++i)
			{
				p = dq.back();
				dq.pop_back();
				if (i != -1)
					dq.push_front(p);
			}
		}
		cout << p.first << ' ';
		move = p.second;
	}

	return 0;
}