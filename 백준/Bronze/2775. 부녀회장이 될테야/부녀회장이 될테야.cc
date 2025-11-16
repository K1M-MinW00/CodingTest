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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	int dp[15][15];

	for (int i = 0; i <= 14; ++i)
	{
		dp[i][1] = 1;
		dp[0][i] = i;
	}

	for (int i = 1; i <= 14; ++i)
	{
		for (int j = 2; j <= 14; ++j)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	}

	
	int k, n;

	while (t--)
	{
		cin >> k >> n;

		cout << dp[k][n] << '\n'; 
	}
	return 0;
}