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

int n;
vector<pair<int, int>> v;
long long dp[502][502];

int solve(int s, int e)
{
	int answer = INT_MAX;

	if (dp[s][e] != -1)
		return dp[s][e];

	if (s == e)
		return 0;

	if (s + 1 == e)
		return v[s].first * v[s].second * v[e].second;

	for (int i = s; i < e; ++i)
	{
		answer = min(answer, v[s].first * v[i].second * v[e].second + solve(s, i) + solve(i + 1, e));
	}

	return dp[s][e] = answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 1);

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
			dp[i][j] = -1;
	}

	for (int i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;

	cout << solve(1, n);

	return 0;
}