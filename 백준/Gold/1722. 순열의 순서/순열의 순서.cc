#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
using namespace std;

long long f[21];
bool used[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	f[0] = 1;
	for (int i = 1; i <= 20; ++i)
		f[i] = f[i - 1] * i;

	int n, op;
	long long k;
	cin >> n >> op;

	vector<int> v(n);

	if (op == 1)
	{
		cin >> k;


		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (used[j])
					continue;

				if (f[n - i - 1] < k)
					k -= f[n - i - 1];
				else
				{
					v[i] = j;
					used[j] = true;
					break;
				}
			}
		}

		for (int e : v)
			cout << e << ' ';
	}
	else if (op == 2)
	{

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		long long answer = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j < v[i]; ++j)
			{
				if (used[j])
					continue;

				answer += f[n - i - 1];
			}
			used[v[i]] = true;
		}

		cout << answer + 1;
	}

	return 0;
}