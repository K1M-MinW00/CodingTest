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
#define MAX 125

int n, answer;

int v[MAX][MAX];
int visited[MAX][MAX];

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

void solve()
{
	answer = 0;
	memset(visited, 123456 , sizeof(visited));
	visited[0][0] = v[0][0];

	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (visited[nx][ny] > visited[cx][cy] + v[nx][ny])
				{
					visited[nx][ny] = visited[cx][cy] + v[nx][ny];
					q.push({ nx,ny });
				}
			}

		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int idx = 1;

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> v[i][j];

		solve();

		cout << "Problem "  << idx++ << ": " << visited[n - 1][n - 1] << '\n';
	}

	return 0;
}