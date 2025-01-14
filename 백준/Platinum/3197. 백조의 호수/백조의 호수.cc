#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char v[1501][1501];
bool visited[1501][1501], s_visited[1501][1501];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

int r, c;
int sx, sy;

queue<pair<int, int>> water, swan, water_temp, swan_temp;

void melt()
{
	while (water.size())
	{
		int cx = water.front().first;
		int cy = water.front().second;
		water.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (visited[nx][ny])
				continue;

			if (v[nx][ny] == 'X')
			{
				visited[nx][ny] = 1;
				water_temp.push({ nx,ny });
				v[nx][ny] = '.';
			}
		}
	}
}

bool solve()
{
	while (swan.size())
	{
		int cx = swan.front().first;
		int cy = swan.front().second;
		swan.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (s_visited[nx][ny])
				continue;

			s_visited[nx][ny] = 1;

			if (v[nx][ny] == '.')
				swan.push({ nx,ny });
			else if (v[nx][ny] == 'X')
				swan_temp.push({ nx,ny });
			else if (v[nx][ny] == 'L')
				return true;
		}
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	string line;
	for (int i = 0; i < r; ++i)
	{
		cin >> line;
		for (int j = 0; j < c; ++j)
		{
			v[i][j] = line[j];

			if (v[i][j] == 'L')
			{
				sx = i; sy = j;
			}
			if (v[i][j] == '.' || v[i][j] == 'L')
			{
				visited[i][j] = 1;
				water.push({ i,j });
			}
		}
	}

	swan.push({ sx,sy });
	s_visited[sx][sy] = 1;

	int answer = 0;

	while (1)
	{
		if (solve())
			break;
		melt();

		water = water_temp;
		swan = swan_temp;

		while (swan_temp.size())
			swan_temp.pop();
		while (water_temp.size())
			water_temp.pop();

		answer++;
	}

	cout << answer;

	return 0;
}
