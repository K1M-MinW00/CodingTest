#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n;
bool v[101][101];
bool visited[101];

void dfs(int i)
{
	for (int j = 0; j < n; ++j)
	{
		if (visited[j])
			continue;
		if (!v[i][j])
			continue;

		visited[j] = true;
		dfs(j);
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
		fill(visited, visited + n, 0);
		dfs(i);

		for (int j = 0; j < n; ++j)
			cout << visited[j] << ' ';
		cout << '\n';
	}

	return 0;
}
