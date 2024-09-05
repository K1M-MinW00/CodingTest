#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int test_case = 0; test_case < t; ++test_case)
	{
		int N, M;
		cin >> N >> M;


		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; ++i)
		{
			int p;
			cin >> p;

			pq.push(p);
			q.push({ p,i });
		}

		int answer = 1;

		while (!q.empty())
		{
			int p = q.front().first;
			int idx = q.front().second;

			if (p == pq.top())
			{
				if (idx == M)
				{
					break;
				}
				else
				{
					q.pop();
					pq.pop();
					answer++;
				}
			}
			else
			{
				q.pop();
				q.push({ p, idx });
			}
		}

		cout << answer << '\n';
	}

	return 0;
}