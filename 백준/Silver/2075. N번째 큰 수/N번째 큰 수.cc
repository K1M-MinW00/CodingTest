#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n * n; ++i)
	{
		int num;
		cin >> num;
		pq.push(num);
		if (pq.size() > n)
			pq.pop();
	}

	cout << pq.top();

	return 0;
}