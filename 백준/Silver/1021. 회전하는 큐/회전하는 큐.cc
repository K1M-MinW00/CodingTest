#include <iostream>
#include <deque>
using namespace std;

int target;

int left_clock(deque<int>& dq)
{
	int cnt = 0;

	while (target != dq.front())
	{
		int front = dq.front();
		dq.pop_front();
		dq.push_back(front);
		cnt++;
	}

	return cnt;
}

int right_clock(deque<int>& dq)
{
	int cnt = 0;

	while (target != dq.front())
	{
		int back = dq.back();
		dq.pop_back();
		dq.push_front(back);
		cnt++;
	}

	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		dq.push_back(i);

	int answer = 0;

	for (int i = 0; i < m; ++i)
	{
		cin >> target;

		if (target == dq.front())
		{
			dq.pop_front();
			continue;
		}
		deque<int> t1, t2;
		t1 = dq;
		t2 = dq;

		int l_cnt = left_clock(t1);
		int r_cnt = right_clock(t2);

		if (l_cnt < r_cnt)
		{
			answer += l_cnt;
			dq = t1;
		}
		else
		{
			answer += r_cnt;
			dq = t2;
		}

		dq.pop_front();
	}

	cout << answer;

	return 0;
}