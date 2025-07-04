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
#define N 31

long long dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[2] = 3;
	dp[4] = 11;

	if (n % 2 == 1)
		cout << 0 << '\n';

	else
	{
		for (int i = 6; i <= n; ++i)
		{
			dp[i] = dp[i - 2] * 4 - dp[i - 4];
		}

		cout << dp[n] << '\n';
	}
	return 0;
}