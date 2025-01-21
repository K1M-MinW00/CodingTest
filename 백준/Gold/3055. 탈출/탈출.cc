#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 51

int n, m, answer = 0;
char v[MAX][MAX];
int w_visited[MAX][MAX];
int visited[MAX][MAX];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

pair<int, int> dest;
pair<int, int> start;
queue<pair<int, int>> water_q;
queue<pair<int, int>> go_q;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	string line;
	for (int i = 0; i < n; ++i)
	{
		cin >> line;

		for (int j = 0; j < m; ++j)
		{
			v[i][j] = line[j];

			if (line[j] == 'D')
				dest = { i,j };
			else if (line[j] == '*')
				water_q.push({ i,j });
			else if (line[j] == 'S')
				go_q.push({ i,j });
		}
	}

	while (go_q.size())
	{
		answer++;
		int water_cnt = water_q.size();
		for (int k = 0; k < water_cnt; ++k) // 물 이동
		{
			int cx = water_q.front().first;
			int cy = water_q.front().second;
			water_q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if (v[nx][ny] == '.')
				{
					v[nx][ny] = '*';
					water_q.push({ nx,ny });
				}
			}
		}

		int go_cnt = go_q.size();
		for (int k = 0; k < go_cnt; ++k)
		{
			int cx = go_q.front().first;
			int cy = go_q.front().second;
			go_q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx == dest.first && ny == dest.second)
				{
					cout << answer;
					return 0;
				}

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if (v[nx][ny] == '.')
				{
					v[nx][ny] = 'S';
					go_q.push({ nx,ny });
				}
			}
		}
	}


	cout << "KAKTUS";

	return 0;
}