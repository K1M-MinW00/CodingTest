#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10002];

int d = 0, endPoint;
void dfs(int p, int len)
{
	if (visited[p])
		return;

	visited[p] = true;

	if (d < len)
	{
		d = len;
		endPoint = p;
	}

	for (auto next : v[p])
		dfs(next.first, len + next.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int p, c, w;
	for (int i = 1; i < n; ++i)
	{
		cin >> p >> c >> w;
		v[p].push_back({ c,w });
		v[c].push_back({ p,w });
	}

	dfs(1, 0);

	for (int i = 0; i <= n; ++i)
		visited[i] = false;

	dfs(endPoint, 0);

	cout << d;

	return 0;
}