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

	vector<double> v(n);
	vector<double> dp(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	dp[0] = v[0];

	double result = 0;

	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(dp[i - 1] * v[i], v[i]);
		result = max(result, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << result;

	return 0;
}