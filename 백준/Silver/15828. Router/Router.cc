#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, num;
	cin >> n;

	queue<int> q;

	while (1)
	{
		cin >> num;

		if (num == -1)
			break;

		if (num == 0)
		{
			if (q.empty())
				continue;
			else
				q.pop();
		}
		else
		{
			if (q.size() >= n)
				continue;
			else
				q.push(num);
		}
	}

	if (q.empty())
		cout << "empty";

	else
		while (q.size())
		{
			cout << q.front() << ' ';
			q.pop();
		}

	return 0;
}