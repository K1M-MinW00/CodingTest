#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 0);

	int temp = 0;

	for (int i = 0; i < k; ++i)
	{
		cin >> v[i];
		dp[0] += v[i];
	}
	for (int i = k; i < n; ++i)
	{
		cin >> v[i];
		dp[i - k + 1] = dp[i - k] + v[i] - v[i - k];
	}

	int answer = dp[0];

	for (int i = 1; i <= n - k; ++i)
		if (answer < dp[i])
			answer = dp[i];

	cout << answer;
	return 0;
}