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

using namespace std;
#define MAX 201

int n, k, s, x, y;

int v[MAX][MAX];
bool visited[MAX][MAX];

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

vector<queue<pair<int, int>>> q;

void solve(int idx)
{
	queue<pair<int, int>> tmp;
	tmp = q[idx];
	memset(visited, 0, sizeof(visited));
	while (tmp.size())
	{
		int cx = tmp.front().first;
		int cy = tmp.front().second;
		visited[cx][cy] = true;

		tmp.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 1 || ny < 1 || nx > n || ny > n)
				continue;

			if (visited[nx][ny])
				continue;

			if (v[nx][ny] == 0)
			{
				v[nx][ny] = idx;
				q[idx].push({ nx,ny });
			}

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	q.resize(k + 1);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] != 0)
			{
				int num = v[i][j];
				q[num].push({ i,j });
			}
		}
	}

	cin >> s >> x >> y;

	while (s--)
	{
		for (int i = 1; i <= k; ++i)
			solve(i);

		if (v[x][y] != 0)
			break;
	}

	cout << v[x][y];
	return 0;
}