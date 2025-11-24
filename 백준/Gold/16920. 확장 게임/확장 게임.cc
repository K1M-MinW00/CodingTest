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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int n, m, p;
int v[1001][1001];
bool visited[1001][1001];

int S[10];
queue<pair<pair<int, int>, int>> q[10], temp;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };


void bfs(int i)
{
	queue<pair<pair<int, int>, int>> temp;

	while (q[i].size())
	{
		pair<pair<int, int>, int> cur = q[i].front();
		q[i].pop();

		int cx = cur.first.first;
		int cy = cur.first.second;
		int cr = cur.second;

		if (cr == S[i])
		{
			temp.push({ {cx,cy},0 });
			continue;
		}

		for (int j = 0; j < 4; ++j)
		{
			int nx = cx + mx[j];
			int ny = cy + my[j];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (v[nx][ny] == 0)
			{
				v[nx][ny] = i;
				q[i].push({ {nx, ny}, cr + 1 });
			}
		}
	}

	q[i] = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; ++i)
		cin >> S[i];


	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			char c = str[j];

			if (c == '.')
				v[i][j] = 0;

			else if (c == '#')
				v[i][j] = -1;

			else
			{
				int num = c - '0';
				v[i][j] = num;
				q[num].push({ {i, j }, 0 });
			}
		}
	}


	while (1)
	{
		int sum1 = 0, sum2 = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sum1 += v[i][j];
			}
		}

		for (int i = 1; i <= p; ++i)
			bfs(i);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sum2 += v[i][j];
			}
		}

		if (sum1 == sum2)
			break;
	}

	vector<int> answer(10);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num = v[i][j];

			if (num > 0)
				answer[num]++;
		}
	}

	for (int i = 1; i <= p; ++i)
		cout << answer[i] << ' ';

	return 0;
}