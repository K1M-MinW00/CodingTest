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
#define MAX 51
int n, m, r;

int v[MAX][MAX];
int d[MAX][MAX];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void solve()
{
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{0,0} });
	d[0][0] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;

		pq.pop();

		if (d[cx][cy] > cnt)
			continue;

		if (cx == n - 1 && cy == n - 1)
			return;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;


			if (d[nx][ny] > d[cx][cy] + v[nx][ny])
			{
				d[nx][ny] = d[cx][cy] + v[nx][ny];
				pq.push({ d[nx][ny],{nx,ny} });
			}
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	string line;

	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = line[j] - '0' ? 0 : 1;
		}
	}

	fill(d[0], d[MAX], INT_MAX);

	solve();

	cout << d[n - 1][n - 1];

	return 0;
}