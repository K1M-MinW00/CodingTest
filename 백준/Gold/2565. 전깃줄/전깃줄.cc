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
#include <bitset>

using namespace std;
#define N 105

int n;
int dp[N];
vector<pair<int, int>> v;


void solve()
{
	int answer = 0;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (v[j].second < v[i].second)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		answer = max(dp[i], answer);
	}

	cout << n - answer << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	solve();

	return 0;
}