#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	dp[1] = v[1];
	
	if (n == 1)
	{
		cout << dp[1];
		return 0;
	} 

	dp[2] = v[1] + v[2];

	for (int i = 3; i <= n; ++i)
			dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]) + v[i];

	cout << dp[n];

	return 0;
}