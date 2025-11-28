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
#include <tuple>
#include <sstream>
using namespace std;

int n, m, answer = INT_MAX;
int v[50][50];
bool visited[50][50];
bool selected[10];
vector<pair<int, int>> virus;
vector<pair<int, int>> selected_virus;

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

bool check()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == 1)
				continue;
			if (visited[i][j] == false)
				return false;
		}
	}
	return true;
}

void bfs()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < selected_virus.size(); ++i)
	{
		int x = selected_virus[i].first;
		int y = selected_virus[i].second;

		q.push({ x,y });
		visited[x][y] = true;
	}

	int time = 0;
	while (q.size())
	{
		int size = q.size();

		for (int t = 0; t < size; ++t)
		{

			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (visited[nx][ny])
					continue;

				if (v[nx][ny] == 1)
					continue;

				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		if (q.size() > 0)
			time++;
	}

	if (check())
		answer = min(answer, time);
}

void solve(int idx, int cnt)
{
	if (cnt == m)
	{
		memset(visited, false, sizeof(visited));
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); ++i)
	{
		if (selected[i] == true)
			continue;

		selected[i] = true;
		selected_virus.push_back(virus[i]);
		solve(i, cnt + 1);
		selected_virus.pop_back();
		selected[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	solve(0, 0);

	if (answer == INT_MAX)
		cout << -1;

	else
		cout << answer;

	return 0;
}