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
#define MAX 2001

int n, m;
vector<int> v[MAX];
vector<bool> visited(MAX, false);

bool isPossible;

void dfs(int idx, int cnt)
{
	if (cnt == 4)
	{
		isPossible = true;
		return;
	}

	visited[idx] = true;

	for (int next : v[idx])
	{
		if (!visited[next])
		{
			dfs(next, cnt + 1);
			visited[next] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			dfs(i, 0);
			visited[i] = false;
		}

		if (isPossible)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}