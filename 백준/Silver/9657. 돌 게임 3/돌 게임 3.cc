#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> dp(1001);

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	dp[6] = 1;
	dp[7] = 0;
	dp[8] = 1;

	for (int i = 9; i <= n; ++i)
	{
		if (dp[i - 1] && dp[i - 3] && dp[i - 4])
			dp[i] = 0;
		else
			dp[i] = 1;
	}

	if (dp[n] == 1)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}