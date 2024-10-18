#include <iostream>
#include <vector>
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

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		dp[i] = v[i];

		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}

		if (answer < dp[i])
			answer = dp[i];
	}

	cout << answer;

	return 0;
}