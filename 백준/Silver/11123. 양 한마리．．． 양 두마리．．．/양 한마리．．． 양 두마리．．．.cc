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

using namespace std;

int t, h, w;
char v[101][101];
bool visited[101][101];

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void solve(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;

			if (visited[nx][ny] || v[nx][ny] == '.')
				continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> h >> w;

		memset(v, NULL, sizeof(v));
		memset(visited, false, sizeof(visited));

		queue<pair<int, int>> q;

		string str;

		for (int i = 0; i < h; ++i)
		{
			cin >> str;
			for (int j = 0; j < w; ++j)
			{
				v[i][j] = str[j];
			}
		}

		int answer = 0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (v[i][j] == '#' && visited[i][j] == false)
				{
					answer++;
					solve(i, j);
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}