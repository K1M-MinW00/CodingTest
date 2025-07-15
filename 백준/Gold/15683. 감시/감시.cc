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
#define N 10

int n, m, answer = INT_MAX;
vector<vector<int>> v;
vector<pair<int, int>> q;
int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

void check(int x, int y, int dir)
{
	dir %= 4;

	while (1)
	{
		int nx = x + mx[dir];
		int ny = y + my[dir];
		x = nx;
		y = ny;

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			break;

		if (v[nx][ny] == 6)
			break;

		if (v[nx][ny] != 0)
			continue;

		v[nx][ny] = -1;
	}

	return;
}
void solve(int idx)
{
	if (idx == q.size())
	{
		int cnt = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] == 0)
					cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	int cx = q[idx].first;
	int cy = q[idx].second;

	vector<vector<int>> tmp(n, vector<int>(m));

	for (int d = 0; d < 4; ++d)
	{
		tmp = v;

		if (v[cx][cy] == 1)
		{
			check(cx, cy, d);
		}
		else if (v[cx][cy] == 2)
		{
			check(cx, cy, d);
			check(cx, cy, d + 2);
		}
		else if (v[cx][cy] == 3)
		{
			check(cx, cy, d);
			check(cx, cy, d + 1);
		}
		else if (v[cx][cy] == 4)
		{
			check(cx, cy, d);
			check(cx, cy, d + 1);
			check(cx, cy, d + 2);
		}
		else if (v[cx][cy] == 5)
		{
			check(cx, cy, d);
			check(cx, cy, d + 1);
			check(cx, cy, d + 2);
			check(cx, cy, d + 3);
		}

		solve(idx + 1);

		v = tmp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] != 0 && v[i][j] != 6)
			{
				q.push_back({ i,j });
			}
		}
	}

	solve(0);

	cout << answer;

	return 0;
}