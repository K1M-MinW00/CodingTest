#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;

int a[21], answer = INT_MAX;
int n;
void solve(int idx)
{
	if (idx == n + 1)
	{
		int sum = 0;

		for (int i = 1; i <= (1 << (n - 1)); i *= 2)
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++)
			{
				if (a[j] & i)
				{
					cnt++;
				}
			}
			sum += min(cnt, n - cnt);
		}
		answer = min(answer, sum);
		return;
	}
	solve(idx + 1);
	a[idx] = ~a[idx];
	solve(idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	string line;
	for (int i = 1; i <= n; ++i)
	{
		cin >> line;

		int value = 1;

		for (int j = 0; j < n; ++j)
		{
			if (line[j] == 'T')
			{
				a[i] |= value;
			}
			value *= 2;
		}
	}

	solve(1);

	cout << answer;

	return 0;
}