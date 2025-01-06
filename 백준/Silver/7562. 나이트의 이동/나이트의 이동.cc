#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mx[] = { 2,2,1,1,-1,-1,-2,-2 };
int my[] = { 1,-1,2,-2,2,-2,1,-1 };

int t, l, sx, sy, ex, ey, answer;

vector<vector<int>> v;
vector<vector<int>> visited;

void solve()
{
	visited[sx][sy] = 1;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = visited[cx][cy];
		q.pop();

		if (cx == ex && cy == ey)
		{
			answer = cur;
			return;
		}
		for (int i = 0; i < 8; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= l || ny >= l)
				continue;
			if (visited[nx][ny])
				continue;

			visited[nx][ny] = cur + 1;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> t;

	while (t--)
	{
		v.clear();
		visited.clear();

		cin >> l;

		v.resize(l);
		visited.resize(l);

		for (int i = 0; i < l; ++i)
		{
			v[i].resize(l, 0);
			visited[i].resize(l, 0);
		}

		cin >> sx >> sy;
		cin >> ex >> ey;

		answer = 0;

		solve();

		cout << answer - 1 << '\n';
	}

	return 0;
}
