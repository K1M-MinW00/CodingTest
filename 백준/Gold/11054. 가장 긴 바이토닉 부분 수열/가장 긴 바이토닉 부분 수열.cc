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
#define N 1005

int n;
int v[N];
int dp[N];
int r[N];

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1; // 자기 자신

		for (int j = 0; j <= i; ++j) // 오름차
		{
			if (v[j] < v[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = n - 1; i >= 0; --i)
	{
		r[i] = 1;
		for (int j = n - 1; j >= i; --j)
		{
			if (v[i] > v[j] && r[j] + 1 > r[i])
			{
				r[i] = r[j] + 1;
			}
		}
	}


	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		answer = max(answer, dp[i] + r[i] - 1);
	}

	cout << answer << '\n';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	solve();

	return 0;
}