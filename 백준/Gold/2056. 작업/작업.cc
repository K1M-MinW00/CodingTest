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
#include <tuple>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> times, dp;
int inDegree[10001];

void topology()
{
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
			q.push({ i, times[i] });
	}

	while (q.size())
	{
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();


		for (int next : v[cur])
		{
			inDegree[next]--;

			dp[next] = max(dp[next], times[next] + time);

			if (inDegree[next] == 0)
			{
				q.push({ next, dp[next] });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 1);
	times.resize(n + 1);
	dp.resize(n + 1);


	for (int i = 1; i <= n; ++i)
	{
		int num, a;
		cin >> times[i] >> num;

		for (int j = 0; j < num; ++j)
		{
			cin >> a;
			v[a].push_back(i);
		}

		dp[i] = times[i];
		inDegree[i] = num;
	}

	topology();

	int answer = *max_element(dp.begin() + 1, dp.end());
    
	cout << answer;

	return 0;
}