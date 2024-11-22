#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> p;
	priority_queue<int, vector<int>, greater<int>> q;

	int n, num;
	cin >> n >> num;

	cout << num << '\n'; // 1번째

	p.push(num);

	for (int i = 1; i < n; ++i)
	{
		cin >> num;

		if (p.size() > q.size())
			q.push(num);

		else
			p.push(num);

		if (q.top() < p.top())
		{
			int qtop = q.top();
			q.pop();
			p.push(qtop);

			if (p.size() > q.size() + 1)
			{
				int ptop = p.top();
				p.pop();
				q.push(ptop);
			}
		}
		if (p.top() > q.top())
		{
			int ptop = p.top();
			p.pop();
			q.push(ptop);
			if (q.size() >= p.size() + 1)
			{
				int qtop = q.top();
				p.pop();
				q.push(qtop);
			}
		}

		cout << p.top() << '\n';
	}

	return 0;
}