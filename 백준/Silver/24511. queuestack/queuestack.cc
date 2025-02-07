#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n, num, m;

deque<int> dq;
vector<int> order;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	order.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> order[i];

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		if (order[i] == 0)
			dq.push_back(num);
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> num;

		dq.push_front(num);
		cout << dq.back() << ' ';
		dq.pop_back();
	}

	return 0;
}