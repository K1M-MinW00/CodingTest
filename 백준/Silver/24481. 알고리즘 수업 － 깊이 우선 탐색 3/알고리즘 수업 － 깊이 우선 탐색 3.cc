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

using namespace std;

int n, m, r;

vector<vector<int>> v;
vector<int> visited;

void dfs(int idx,int cnt)
{
	visited[idx] = cnt;
	
	for (int x : v[idx])
	{
		if (visited[x] != -1)
			continue;

		dfs(x,cnt+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> r;

	v.resize(n + 1);
	visited.resize(n + 1,-1);

	int s, e;

	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	
	for (int i = 1; i <= n; ++i)
		sort(v[i].begin(), v[i].end());


	dfs(r, 0);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << '\n';

	return 0;
}