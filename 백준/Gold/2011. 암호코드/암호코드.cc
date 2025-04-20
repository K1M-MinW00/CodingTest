#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <climits>
using namespace std;

vector<int> dp;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> str;

	if (str[0] == '0')
	{
		cout << 0;
		return 0;
	}

	int len = str.length();

	dp.resize(len + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= len; ++i)
	{
		char c = str[i - 1];

		if (c >= '1' && c <= '9')
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;

		if (i == 1)
			continue;

		char pc = str[i - 2];

		if ((pc == '1') || (pc == '2' && c <= '6'))
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;

	}

	cout << dp[len];

	return 0;
}