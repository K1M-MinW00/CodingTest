#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 500000
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	if (n  <= 10)
	{
		cout << n;
		return 0;
	}
		
	long long cnt = 0;
	long long answer = -1;

	queue<long long> q;

	for (int i = 1; i <= 9; ++i)
	{
		q.push(i);
		++cnt;
	}


	while (q.size())
	{
		long long cur = q.front();
		q.pop();

		 long long digit_1 = (cur % 10);
		
		cur *= 10;

		for (int i = 0; i < digit_1; ++i)
		{
			++cnt;

			if (cnt == n)
			{
				answer = cur + i;
				break;
			}
			q.push(cur + i);
		}

		if (cnt == n)
			break;
	}

	cout << answer;
	return 0;
}
