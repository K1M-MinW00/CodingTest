#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int n, a, b, m;
int answer = -1;
vector<vector<int>> v;
vector<int> dist;


void dfs(int p)
{
	for (int c : v[p])
	{
		if (dist[c] != -1)
			continue;

		dist[c] = dist[p] + 1;

		dfs(c);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> a >> b >> m;

	v.resize(n + 1);
	dist.resize(n + 1, -1);

	int p, c;
	for (int i = 1; i <= m; ++i)
	{
		cin >> p >> c;
		v[p].push_back(c);
		v[c].push_back(p);
	}

	dist[a] = 0;
	dfs(a);


	cout << dist[b];
	return 0;
}