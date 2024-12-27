#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int n, l, r, answer = 0;

int a[54][54];
bool visited[54][54];
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
bool changed;

void bfs(int x, int y)
{
	int sum = a[x][y];
	queue<pair<int, int>> q;
	q.push({ x,y });
	vector<pair<int, int>> connect;
	connect.push_back({ x,y });

	while (q.size())
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

			int temp = abs(a[cx][cy] - a[nx][ny]);
			if (temp < l || temp > r)
				continue;

			sum += a[nx][ny];
			connect.push_back({ nx,ny });
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	if (connect.size() > 1)
	{
		changed = true;
		int divide = sum / connect.size();
		for (auto e : connect)
			a[e.first][e.second] = divide;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}

	while (1)
	{
		changed = false;
		memset(visited, 0, sizeof(visited));
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j])
					continue;
				visited[i][j] = 1;
				bfs(i, j);
			}
		}

		if (!changed)
			break;
		else
			answer++;
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//		cout << a[i][j] << ' ';
	//	cout << '\n';
	//}

	cout << answer;
	return 0;
}