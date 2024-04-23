#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	int tmp;
	priority_queue<int, vector<int>, less<int>> q;

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		q.push(tmp);
	}

	int sum = 0;

	while (1)
	{
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();

		sum += (first * second);
		q.push(first + second);

		if (q.size() == 1)
			break;
	}

	cout << sum;

	return 0;
}