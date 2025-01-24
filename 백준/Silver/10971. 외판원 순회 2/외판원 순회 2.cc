#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX  11

int n;
int v[MAX][MAX];
bool visited[MAX];
int answer = INT_MAX;

int mx[] = { -1,1,0,0 };
int my[] = { 0,0,1,-11 };

void solve(int start, int cur, int depth, int sum)
{
	if (depth == n)
	{
		if (v[cur][start])
		{
			answer = min(answer, sum + v[cur][start]);
			return;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;

		if (v[cur][i])
		{
			visited[i] = true;
			solve(start, i, depth + 1, sum + v[cur][i]);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];


	for (int i = 0; i < n; ++i)
	{
		visited[i] = true;
		solve(i, i, 1, 0);
		visited[i] = false;
	}

	cout << answer;

	return 0;
}