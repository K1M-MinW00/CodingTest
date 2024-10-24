#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp.resize(n + 1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

	cout << dp[n];

	return 0;
}