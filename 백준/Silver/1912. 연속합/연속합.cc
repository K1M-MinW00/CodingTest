#include <iostream>
#include <vector>
#include <climits>
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

	for (int i = 2; i <= n; ++i)
		dp[i] = max(v[i], v[i] + dp[i - 1]);

	int answer = INT_MIN;

	for (int i = 1; i <= n; ++i)
		answer = max(answer, dp[i]);

	cout << answer;

	return 0;
}