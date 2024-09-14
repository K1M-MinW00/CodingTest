#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case, n;
	char op;
	int num;

	cin >> test_case;

	for (int t = 0; t < test_case; ++t)
	{
		cin >> n;

		priority_queue<int, vector<int>, greater<int>> min_heap;
		priority_queue<int> max_heap;
		map<int, int> answer;

		for (int i = 0; i < n; ++i)
		{
			cin >> op >> num;

			if (op == 'I')
			{
				min_heap.push(num);
				max_heap.push(num);
				answer[num]++;
			}

			else if (op == 'D')
			{
				if (num == -1)
				{
					if (!min_heap.empty())
					{
						answer[min_heap.top()]--;
						min_heap.pop();
					}
				}
				else if (num == 1)
				{
					if (!max_heap.empty())
					{
						answer[max_heap.top()]--;
						max_heap.pop();
					}
				}

				while (!max_heap.empty() && answer[max_heap.top()] == 0)
				{
					max_heap.pop();
				}

				while (!min_heap.empty() && answer[min_heap.top()] == 0)
				{
					min_heap.pop();
				}
			}
		}


		while (!max_heap.empty() && answer[max_heap.top()] == 0)
		{
			max_heap.pop();
		}

		while (!min_heap.empty() && answer[min_heap.top()] == 0)
		{
			min_heap.pop();
		}

		if (max_heap.empty() || min_heap.empty())
			cout << "EMPTY" << '\n';
		else
			cout << max_heap.top() << ' ' << min_heap.top() << '\n';
	}

	return 0;
}