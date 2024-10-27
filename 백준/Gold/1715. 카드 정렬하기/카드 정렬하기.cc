#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		pq.push(x);
	}

	int sum = 0;

	while (pq.size() >= 2)
	{
		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		sum += (first + second);
		pq.push(first + second);
	}

	cout << sum;

	return 0;
}
