#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

string a, b;
int la, lb;
int dp[1001][1001];
vector<char> lcs;

void LCS(int r, int c)
{
	if (r == 0 || c == 0)
		return;

	if (a[r - 1] == b[c - 1])
	{
		lcs.push_back(a[r - 1]);
		LCS(r - 1, c - 1);
	}
	else
	{
		if (dp[r - 1][c] > dp[r][c - 1])
			LCS(r - 1, c);
		else // dp[r][c-1] > dp[r-1][c]
			LCS(r, c - 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;

	la = a.length(), lb = b.length();

	for (int i = 1; i <= la; ++i)
	{
		for (int j = 1; j <= lb; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[la][lb] << '\n';

	LCS(la, lb);

	for (int i = lcs.size() - 1; i >= 0; --i)
		cout << lcs[i];

	return 0;
}