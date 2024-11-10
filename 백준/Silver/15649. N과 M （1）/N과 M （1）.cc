#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<int> v(9);
vector<bool> visited(9, false);

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])
			continue;

		v[cnt] = i;
		visited[i] = true;
		dfs(cnt + 1);
		visited[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	dfs(0);

	return 0;
}