#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int v[5][5];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<string> answer;

void dfs(int i, int j, string cur, int depth)
{
	if (depth == 5)
	{
		answer.insert(cur);
		return;
	}

	for (int d = 0; d < 4; ++d)
	{
		int x = i + dx[d];
		int y = j + dy[d];

		if (0 <= x && x < 5 && 0 <= y && y < 5)
		{
			char c = v[x][y];
			dfs(x, y, cur + c, depth + 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> v[i][j];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			string cur = to_string(v[i][j]);
			dfs(i, j, cur, 0);
		}
	}

	cout << answer.size();
	return 0;
}