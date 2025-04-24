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
#define MAX 301

int r, c;
int v[MAX][MAX];
bool visited[MAX][MAX];

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

typedef struct t { int x, y, c; };
vector<t> temp;

void solve(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = v[cx][cy];

		q.pop();

		int around = 0;
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx > r || ny > c)
				continue;

			if (v[nx][ny] == 0)
				around++;

			if (v[nx][ny] > 0 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

		if (around > 0)
		{
			int c = max(0, cur - around);
			temp.push_back({ cx,cy,c });
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> v[i][j];
		}
	}

	int answer = 0;

	while (1)
	{
		int cnt = 0;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (v[i][j] == 0)
					continue;

				if (visited[i][j])
					continue;

				visited[i][j] = true;
				solve(i, j);
				cnt++;
			}

		}


		if (cnt >= 2)
			break;

		if (cnt == 0)
		{
			answer = 0;
			break;
		}

		for (auto e : temp)
			v[e.x][e.y] = e.c;

		memset(visited, 0, sizeof(visited));
		temp.clear();

		answer++;
	}

	cout << answer;

	return 0;
}