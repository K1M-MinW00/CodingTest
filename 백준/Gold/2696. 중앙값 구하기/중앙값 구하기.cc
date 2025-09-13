#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int m, e;

	while (t--)
	{
		cin >> m;

		priority_queue<int> p1; // 내림차순
		priority_queue<int, vector<int>, greater<int>> p2; // 오름차순
		vector<int> mids;

		p1.push(INT_MIN);
		p2.push(INT_MAX);


		for (int i = 1; i <= m; ++i)
		{
			cin >> e;

			int lower_bound = p1.top();
			int upper_bound = p2.top();

			if (e <= lower_bound)
			{
				p1.push(e);
			}
			else if (upper_bound < e)
			{
				p2.push(e);
			}
			else
			{
				p1.push(e);
			}

			if (i % 2 == 0) // 짝수
			{
				while (p1.size() != p2.size())
				{
					if (p1.size() > p2.size())
					{
						int temp = p1.top();
						p1.pop();
						p2.push(temp);
					}
					else
					{
						int temp = p2.top();
						p2.pop();
						p1.push(temp);
					}
				}
			}
			else
			{
				while (p1.size() != p2.size() + 1)
				{
					if (p1.size() > p2.size() + 1)
					{
						int temp = p1.top();
						p1.pop();
						p2.push(temp);
					}
					else
					{
						int temp = p2.top();
						p2.pop();
						p1.push(temp);
					}
				}

				if (i % 2 == 1)
				{
					mids.push_back(p1.top());
				}
			}
		}

		cout << mids.size() << '\n';
		for (int i = 1; i <= mids.size(); ++i)
		{
			cout << mids[i - 1];

			if (i % 10 == 0)
				cout << '\n';
			else
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}