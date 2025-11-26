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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

string a, b, c;
int dp[201][201];

int solve(int n, int m)
{
	if (n + m == c.length())
		return 1;

	if (dp[n][m] != -1)
		return dp[n][m];

	if (n < a.length() && c[n + m] == a[n] && solve(n + 1, m))
		return dp[n][m] = 1;
	if (m < b.length() && c[n + m] == b[m] && solve(n, m + 1))
		return dp[n][m] = 1;

	return dp[n][m] = 0;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int t = 1; t <= n; ++t)
	{
		cin >> a >> b >> c;

		memset(dp, -1, sizeof(dp));

		bool answer = solve(0, 0);


		cout << "Data set " << t << ": " << (answer ? "yes" : "no") << '\n';
	}

	return 0;
}