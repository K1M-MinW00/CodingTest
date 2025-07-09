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
#define N 100

int n, m;
char graph[N][N];
vector<pair<int, int>> p;
vector<vector<vector<int>>> DP;

int mx[] = { 1,-1,0,0 }; // 위, 아래, 오른쪽, 왼쪽
int my[] = { 0,0,1,-1 };

void solve()
{
	int sx = p[0].first, sy = p[0].second;
	int ex = p[1].first, ey = p[1].second;

	// priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;

	queue <pair<int, pair<int, int>>> q;
	for (int i = 0; i < 4; ++i)
	{
		q.push({ i,{sx,sy} });
		DP[sx][sy][i] = 0;
	}

	int answer = INT_MAX;

	while (q.size())
	{
		int dir = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int cnt = DP[cx][cy][dir];
		q.pop();

		if (cx == ex && cy == ey)
		{
			answer = min(answer, cnt);
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (graph[nx][ny] == '*')
				continue;

			int next_cnt = (dir == i) ? cnt : cnt + 1;

			if (DP[nx][ny][i] <= next_cnt)
				continue;

			DP[nx][ny][i] = next_cnt;
			q.push({ i ,{nx,ny} });
		}
	}

	int ret = INT_MAX;
	for (int i = 0; i < 4; ++i)
	{
		ret = min(ret, DP[ex][ey][i]);
	}

	cout << ret << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	string line;

	DP.resize(m, vector<vector<int>>(n, vector<int>(4, INT_MAX)));

	for (int i = 0; i < m; ++i)
	{
		cin >> line;
		for (int j = 0; j < n; ++j)
		{
			graph[i][j] = line[j];

			if (line[j] == 'C')
			{
				p.push_back({ i,j });
			}
		}
	}

	solve();

	return 0;
}