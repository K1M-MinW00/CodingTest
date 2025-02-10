#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

const int MAX = 246913;

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

	int n = 1;
	isPrime();
	while (cin >> n)
	{
		if (n == 0)
			break;

		int answer = 0;

		for (int i = n+1; i <= 2 * n; ++i)
		{
			if (p[i] != 0)
				answer++;
		}

		cout << answer << '\n';
	}
	return 0;
}