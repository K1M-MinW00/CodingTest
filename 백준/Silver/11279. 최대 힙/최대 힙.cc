#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int n, num;
	cin >> n;

	priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				int top = pq.top();
				cout << top << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(num);
		}
	}

	return 0;
}