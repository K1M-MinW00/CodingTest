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
#define N 2224

int n;
int v[N][N];
vector<vector<int>> dp;
int mx[] = { 1,0 };
int my[] = { 0,1 };


void solve()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{1,1} });
	dp[1][1] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		int cur = v[cx][cy];

		pq.pop();

		if (cnt > dp[cx][cy])
			continue;

		if (cx == n && cy == n)
			break;


		for (int i = 0; i < 2; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];
			int node = v[nx][ny];

			if (nx < 1 || ny < 1 || nx > n || ny > n)
				continue;

			if (node < cur)
			{
				if (dp[nx][ny] > cnt)
				{
					dp[nx][ny] = cnt;
					pq.push({ cnt,{nx,ny} });
				}
			}
			else if (node >= cur)
			{
				int d = node - cur + 1;
				if (dp[nx][ny] > cnt + d)
				{
					dp[nx][ny] = cnt + d;
					pq.push({ dp[nx][ny],{nx,ny} });
				}
			}
		}
	}

	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << dp[n][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	dp.resize(n + 1, vector<int>(n + 1, INT_MAX));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}

	solve();
	return 0;
}