#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> dp(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int min = v[0];

	for (int i = 1; i < n; ++i)
	{
		if (v[i] < min)
			min = v[i];

		dp[i] = max(v[i] - min, dp[i - 1]);
	}
	cout << dp[n - 1];

	return 0;
}