#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

const int MAX = 10001;

bool p[MAX];

void isPrime()
{
	for (int i = 2; i < MAX; ++i)
		p[i] = i;

	for (int i = 2; i * i < MAX; ++i)
	{
		if (p[i] == 0)
			continue;

		for (int j = i * i; j < MAX; j += i)
			p[j] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	isPrime();
	int t, n;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;

		for (int j = n / 2; j < n - 1; ++j)
		{
			if (p[j] && p[n - j])
			{
				cout << n - j << ' ' << j << '\n';
				break;
			}
		}
	}
	return 0;
}