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
#define N 1005

int n;
int v[N];
int dp[N];
vector<int> w[N];
vector<int> answer;

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		w[i].push_back(v[i]);

		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				w[i] = w[j];
				w[i].push_back(v[i]);
			}
		}

		if (answer.size() < w[i].size())
		{
			answer = w[i];
		}
	}

	cout << answer.size() << '\n';

	for (int e : answer)
		cout << e << ' ';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	solve();

	return 0;
}