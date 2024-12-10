#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int m[11];
int dp[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 10; ++i)
	{
		cin >> m[i];
		dp[i] = dp[i - 1] + m[i];
	}

	int idx = 0;
	int sub = abs(100 - dp[0]);
	for (int i = 1; i <= 10; ++i)
	{
		int subtract = abs(100 - dp[i]);

		if (sub >= subtract && dp[idx] <= dp[i])
		{
			idx = i;
			sub = abs(100 - dp[i]);
		}
	}

	cout << dp[idx];
	return 0;
}