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

using namespace std;

int r, c;
char v[251][251]; // 0 : 벽 , 1 : 빈 칸, 2 : 울타리, 3 : 양, 4 : 늑대
bool visited[251][251];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int sheep_cnt = 0, wolf_cnt = 0;

void bfs(int x, int y)
{
	int wolf = 0, sheep = 0;

	queue<pair<int, int>> q;
	q.push({ x,y });
	v[x][y] = true;


	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (v[cx][cy] == 'o')
			sheep++;
		else if (v[cx][cy] == 'v')
			wolf++;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (visited[nx][ny] || v[nx][ny] == '#')
				continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	if (sheep > wolf)
		sheep_cnt += sheep;
	else
		wolf_cnt += wolf;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;

	memset(v, '#', sizeof(v));

	string line;

	for (int i = 0; i < r; ++i)
	{
		cin >> line;
		for (int j = 0; j < c; ++j)
			v[i][j] = line[j];
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (visited[i][j])
				continue;

			bfs(i, j);
		}
	}

	cout << sheep_cnt << ' ' << wolf_cnt;

	return 0;
}