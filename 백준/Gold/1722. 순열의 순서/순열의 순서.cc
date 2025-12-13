#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

long long f[21], s[21];
bool visited[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, op;
	cin >> n >> op;

	f[0] = 1;

	for (int i = 1; i <= 20; ++i)
		f[i] = f[i - 1] * i;

	if (op == 1)
	{
		long long k;
		cin >> k;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (visited[j])
					continue;

				if (f[n - i - 1] < k)
					k -= f[n - i - 1];
				else
				{
					s[i] = j;
					visited[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i)
			cout << s[i] << ' ';
	}
	else
	{
		for (int i = 0; i < n; ++i)
			cin >> s[i];

		long long answer = 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j < s[i]; ++j)
			{
				if (visited[j])
					continue;

				answer += f[n - i - 1];
			}
			visited[s[i]] = true;
		}

		cout << answer;
	}
	return 0;
}