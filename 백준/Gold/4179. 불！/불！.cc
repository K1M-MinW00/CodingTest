#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int r, c, answer;
char a[1001][1001];
int fire[1001][1001];
int person[1001][1001];
int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	pair<int, int> p;

	fill(&fire[0][0], &fire[0][0] + 1001 * 1001, 987654321);
	queue<pair<int, int>> q;
	string line;

	for (int i = 0; i < r; ++i)
	{
		cin >> line;
		for (int j = 0; j < c; ++j)
		{
			a[i][j] = line[j];

			if (a[i][j] == 'F')
			{
				q.push({ i,j });
				fire[i][j] = 1;
			}
			else if (a[i][j] == 'J')
				p = { i,j };
		}
	}


	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = fire[cx][cy];
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (a[nx][ny] == '#' || fire[nx][ny] != 987654321)
				continue;

			int next = cur + 1;
			fire[nx][ny] = next;
			q.push({ nx, ny });
		}
	}

	person[p.first][p.second] = 1;
	q.push({ p.first, p.second });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = person[cx][cy];
		q.pop();

		if (cx == 0 || cy == 0 || cx == r - 1 || cy == c - 1)
		{
			answer = cur;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (a[nx][ny] == '#' || person[nx][ny])
				continue;

			if (fire[nx][ny] <= cur + 1)
				continue;

			person[nx][ny] = cur + 1;
			q.push({ nx, ny });
		}
	}

	if (answer != 0)
		cout << answer;
	else
		cout << "IMPOSSIBLE";

	return 0;
}