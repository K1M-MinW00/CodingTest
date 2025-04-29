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
#define MAX 251

int r, c;

char v[MAX][MAX];
bool visited[MAX][MAX];

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

int answer_wolf = 0, answer_sheep = 0;

void solve(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	int sheep = 0, wolf = 0;

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;

			if (visited[nx][ny])
				continue;

			if (v[nx][ny] == '#') // 벽
				continue;

			visited[nx][ny] = true;

			if (v[nx][ny] == 'v') // 늑대
				wolf++;
			else if (v[nx][ny] == 'k') // 양
				sheep++;

			q.push({ nx,ny });

		}
	}

	if (wolf >= sheep)
		answer_wolf += wolf;
	else
		answer_sheep += sheep;

	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
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
			if (v[i][j] != '.' && !visited[i][j])
			{
				visited[i][j] = true;
				solve(i, j);
			}
		}
	}

	cout << answer_sheep << ' ' << answer_wolf;
	return 0;
}